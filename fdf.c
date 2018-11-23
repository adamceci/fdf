/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:53:55 by aceciora          #+#    #+#             */
/*   Updated: 2018/11/23 14:38:58 by aceciora         ###   ########.fr       */
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
		if ((*line != ' ' && *(line + 1) == ' ') ||
				(*line != ' ' && *(line + 1) == '\0'))
			i++;
		line++;
	}
	return (i);
}

int		**ft_fill_tab(int nb_line, int nb_char, char *file)
{
	int		**map;
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (!(map = (int**)malloc(sizeof(*map) * (nb_line + 1))))
		return (NULL);
	i = 0;
	while (i < nb_line)
	{
		get_next_line(fd, &line);
		printf("line[%d] = %s\n", i, line);
		tmp = line;
		if(!(map[i] = (int*)malloc(sizeof(**map) * (nb_char + 1))))
			return (NULL);
		j = 0;
		while (j < nb_char)
		{
			map[i][j] = ft_atoi(line);
			while (*line && *line == ' ')
				line++;
			while (*line && *line != ' ')
				line++;
			j++;
		}
		free(tmp);
		i++;
	}
	i = 0;
	while (i < nb_line)
	{
		printf("line[%d] = ", i);
		j = 0;
		while (j < nb_char)
		{
			printf("%d ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	close(fd);
	return (map);
}

void	read_file(char *file, t_map_infos *tab)
{
	int		fd;
	char	*line;
//	int		i;

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
	tab->map = ft_fill_tab(tab->nb_line, tab->nb_num, file);
}

void	*initialize()
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
		printf("failed to set up connection to the X server\n");
		return (NULL);
	}
	return (mlx_ptr);
}

void	*create_window(void *mlx_ptr)
{
	void	*mlx_window;

	mlx_window = mlx_new_window(mlx_ptr, 1000, 700, "fdf");
	if (mlx_window == NULL)
	{
		printf("failed to create a new window\n");
		return (NULL);
	}
	return (mlx_window);
}

/*
int	ft_round(double nb)
{
	return (nb + 0.5);
}
*/

int		ft_abs(int nb)
{
	if (nb >= 0)
		return (nb);
	return (-nb);
}

void	get_draw_infos(t_line *elem, int x0, int x1, int y0, int y1)
{	
	elem->w = x1 - x0;
	elem->h = y1 - y0;
	(elem->w < 0) ? (elem->dx1 = -1) : (elem->dx1 = 1);
	(elem->h < 0) ? (elem->dy1 = -1) : (elem->dy1 = 1);
	elem->dx2 = elem->dx1;
	elem->dy2 = 0;
	elem->longest = ft_abs(elem->w);
	elem->shortest = ft_abs(elem->h);
	if (elem->longest < elem->shortest)
	{
		ft_swap(elem->longest, elem->shortest);
		(elem->h < 0) ? (elem->dy2 = -1) : (elem->dy2 = 1);
		elem->dx2 = 0;
	}
	elem->numerator = elem->longest / 2;
}

void	draw_line(t_mlx_infos *mlx_info, int x0, int y0, int x1, int y1,
		int color)
{
	t_line	*elem;
	int	i;

	elem = (t_line*)malloc(sizeof(*elem));
	get_draw_infos(elem, x0, x1, y0, y1);
	i = 0;
	while (i <= elem->longest)
	{
		mlx_pixel_put(mlx_info->ptr, mlx_info->window, x0, y0, color);
		elem->numerator += elem->shortest;
		if (elem->numerator >= elem->longest)
		{
			elem->numerator -= elem->longest;
			x0 += elem->dx1;
			y0 += elem->dy1;
		}
		else
		{
			x0 += elem->dx2;
			y0 += elem->dy2;
		}
		i++;
	}
}

void	draw(t_mlx_infos *mlx_info, t_map_infos *tab)
{
	int	x;
	int	y;
//	int	inc_x;
//	int	inc_y;
	int	i;
	int	j;

	x = 50;
	y = 50;
	i = 0;
	while (i < tab->nb_line)
	{
		j = 0;
		while (j < tab->nb_num - 1)
		{
			draw_line(mlx_info, x, y, x + 50, 50 * (i + 1), 8584960);
			x += 50;
			j++;
		}
		x = 50;
		y += 50;
		i++;
	}
	x = 50;
	y = 50;
	i = 0;
	while (i < tab->nb_num)
	{
		j = 0;
		while (j < tab->nb_line - 1)
		{
			draw_line(mlx_info, x, y, 50 * (i + 1), y + 50, 8584960);
			y += 50;
			j++;
		}
		y = 50;
		x += 50;
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_mlx_infos	*mlx_info;
	t_map_infos	*tab;

	mlx_info = (t_mlx_infos*)malloc(sizeof(*mlx_info));
	tab = (t_map_infos*)malloc(sizeof(*tab));
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf file\n");
		return (0);
	}
	read_file(argv[1], tab);
	if (!(mlx_info->ptr = initialize()))
		return (0);
	if (!(mlx_info->window = create_window(mlx_info->ptr)))
		return (0);
	draw(mlx_info, tab);
	mlx_loop(mlx_info->ptr);
	return (0);
}
