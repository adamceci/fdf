/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:25:55 by aceciora          #+#    #+#             */
/*   Updated: 2018/12/11 17:48:56 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_nb_char(char *line)
{
	int			i;

	i = 0;
	while (*line)
	{
		if ((*line != ' ' && *(line + 1) == ' ') ||
				(*line != ' ' && *(line + 1) == '\0'))
			i++;
		line++;
	}
	return (i);
}

static void	fill_tab(t_map_infos *tab, char *file)
{
	int			fd;
	int			i;
	int			j;
	char		*line;
	char		**grid;

	fd = open(file, O_RDONLY);
	i = 0;
	while (i < tab->nb_line)
	{
		get_next_line(fd, &line);
		grid = ft_strsplit(line, ' ');
		j = 0;
		while (j < tab->nb_num)
		{
			tab->map[i][j] = atoi(grid[j]);
			j++;
		}
		free_2d_array(grid, tab->nb_num);
		free(line);
		i++;
	}
	close(fd);
}

static void	allocate_tab(t_map_infos *tab)
{
	int			i;

	if (!(tab->map = (int**)malloc(sizeof(*tab->map) * tab->nb_line)))
		exit(-1);
	i = 0;
	while (i < tab->nb_line)
	{
		if (!(tab->map[i] = (int*)malloc(sizeof(**tab->map) * tab->nb_num)))
			exit(-1);
		i++;
	}
}

static void	read_file(char *file, t_map_infos *tab)
{
	int			fd;
	char		*line;

	tab->map = NULL;
	fd = open(file, O_RDONLY);
	tab->nb_line = 0;
	tab->nb_num = 0;
	while (get_next_line(fd, &line))
	{
		if (!(tab->nb_num))
			tab->nb_num = ft_nb_char(line);
		free(line);
		tab->nb_line++;
	}
	close(fd);
	allocate_tab(tab);
	fill_tab(tab, file);
}

int			main(int argc, char **argv)
{
	t_mlx_infos	*mlx_info;
	t_map_infos	*tab;

	mlx_info = (t_mlx_infos*)malloc(sizeof(*mlx_info));
	tab = (t_map_infos*)malloc(sizeof(*tab));
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf file\n");
		return (-1);
	}
	read_file(argv[1], tab);
	if (!(mlx_info->ptr = initialize()) ||
		!(mlx_info->win = create_window(mlx_info->ptr)))
		return (-1);
	if (!(mlx_info->img = mlx_new_image(mlx_info->ptr, 700, 1000)))
		return (-1);
	mlx_info->img_str = (int*)mlx_get_data_addr(mlx_info->img, &(mlx_info->bpp),
						&(mlx_info->s_l), &(mlx_info->endian));
	para_draw(mlx_info, tab);
	mlx_key_hook(mlx_info->win, deal_key, mlx_info);
	mlx_loop(mlx_info->ptr);
	return (0);
}
