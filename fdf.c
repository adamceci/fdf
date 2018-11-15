/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:53:55 by aceciora          #+#    #+#             */
/*   Updated: 2018/11/15 17:30:43 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int		ft_nb_char(char *line)
{
	int		i;


}

char	**read_file(char *file)
{
	int		fd;
	int		nb_line;
	int		nb_char;
	char	*line;
	char	**map;

	map = NULL;
	fd = open(file, O_RDONLY);
	nb_line = 0;
	while (get_next_line(fd, &line))
	{
		nb_char = ft_nb_char(line);
		free(line);
		nb_line++;
	}
	printf("nb_line = %d\n", nb_line);
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
	mlx_loop(mlx_ptr);
	return (0);
}
