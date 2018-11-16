/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:53:55 by aceciora          #+#    #+#             */
/*   Updated: 2018/11/16 16:33:43 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int		ft_nb_char(char *line)
{
	int		i;

	i = 0;
	while (*line)
	{
		if ((*line != ' ' && *(line + 1) == ' ') || (*line != ' ' && *(line + 1) == '\0'))
			i++;
		line++;
	}
	return (i);
}

char	**read_file(char *file)
{
	int		fd;
	int		nb_line;
	int		nb_char;
	char	*line;
	char	**map;
	int		i;

	map = NULL;
	fd = open(file, O_RDONLY);
	nb_line = 0;
	while (get_next_line(fd, &line))
	{
		if (!nb_char)
			nb_char = ft_nb_char(line);
		free(line);
		nb_line++;
	}
	close(fd);
	if (!(map = (char**)malloc(sizeof(*map) * (nb_line + 1))))
		return (NULL);
	i = 0;
	while (nb_words-- > 0)
	{
		if(!(map[i] = (char*)malloc(sizeof(**map) * (nb_char + 1))))
			return (NULL);
		i++;
	}
	return (map);
}

int		main(int argc, char **argv)
{
	char	**map;
	void	*mlx_ptr;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf file\n");
		return (0);
	}
	map = read_file(argv[1]);
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	return (0);
}
