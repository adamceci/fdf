/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:26:08 by aceciora          #+#    #+#             */
/*   Updated: 2018/12/12 15:55:07 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

/*
int	ft_round(double nb)
{
	return (nb + 0.5);
}
*/

static int	ft_abs(int nb)
{
	if (nb >= 0)
		return (nb);
	return (-nb);
}

static void	get_draw_infos(t_line *elem, t_map_infos *tab)
{
	elem->w = tab->x1 - tab->x0;
	elem->h = tab->y1 - tab->y0;
	if (elem->w < 0)
		elem->dx1 = -1;
	else
		elem->dx1 = 1;
	if (elem->h < 0)
		elem->dy1 = -1;
	else
		elem->dy1 = 1;
	elem->dx2 = elem->dx1;
	elem->dy2 = 0;
	elem->longest = ft_abs(elem->w);
	elem->shortest = ft_abs(elem->h);
	if (elem->longest < elem->shortest)
	{
		ft_swap(&(elem->longest), &(elem->shortest));
		if (elem->h < 0)
			elem->dy2 = -1;
		else
			elem->dy2 = 1;
		elem->dx2 = 0;
	}
	elem->numerator = elem->longest / 2;
}

static void	draw_line(t_mlx_infos *mlx_info, t_map_infos *tab, int color)
{
	t_line	*elem;
	int	i;

	elem = (t_line*)malloc(sizeof(*elem));
	get_draw_infos(elem, tab);
	i = 0;
	while (i <= elem->longest)
	{
		mlx_info->img_str[tab->y0 * 2000 + tab->x0] = color;
		elem->numerator += elem->shortest;
		if (elem->numerator >= elem->longest)
		{
			elem->numerator -= elem->longest;
			tab->x0 += elem->dx1;
			tab->y0 += elem->dy1;
		}
		else
		{
			tab->x0 += elem->dx2;
			tab->y0 += elem->dy2;
		}
		i++;
	}
}

static void	draw_hlines(t_mlx_infos *mlx_info, t_map_infos *tab, t_draw *elem)
{
	int		i;
	int		j;

	tab->x0 = elem->start_x + ((tab->map[0][0]) * elem->ratio_x);
	tab->y0 = elem->start_y + ((tab->map[0][0]) * elem->ratio_y);
	i = 0;
	while (i < tab->nb_line)
	{
		j = 0;
		while (j < tab->nb_num - 1)
		{
			tab->x1 = elem->start_x + tab->inc_x * (j + 1) +
					tab->map[i][j + 1] * elem->ratio_x + elem->slope * i;
			tab->y1 = elem->start_y + tab->inc_y * i +
					tab->map[i][j + 1] * elem->ratio_y - elem->slope * (j + 1);
			if (tab->map[i][j + 1] > 0 || tab->map[i][j] > 0)
				draw_line(mlx_info, tab, 0xFF66B2);
			else
				draw_line(mlx_info, tab, 0xFFCCE5);
			tab->x0 = tab->x1;
			tab->y0 = tab->y1;
			j++;
		}
		i++;
		if (i < tab->nb_line)
		{
			tab->x0 = elem->start_x + elem->slope * i + tab->map[i][0] * elem->ratio_x;
			tab->y0 = elem->start_y + tab->inc_y * i + tab->map[i][0] * elem->ratio_y;
		}
	}
}

static void	draw_vlines(t_mlx_infos *mlx_info, t_map_infos *tab, t_draw *elem)
{
	int		i;
	int		j;

	tab->x0 = elem->start_x + ((tab->map[0][0]) * elem->ratio_x);
	tab->y0 = elem->start_y + ((tab->map[0][0]) * elem->ratio_y);
	j = 0;
	while (j < tab->nb_num)
	{
		i = 0;
		while (i < tab->nb_line - 1)
		{
			tab->x1 = elem->start_x + tab->inc_x * j +
					tab->map[i + 1][j] * elem->ratio_x + elem->slope * (i + 1);
			tab->y1 = elem->start_y + tab->inc_y * (i + 1) +
					tab->map[i + 1][j] * elem->ratio_y - elem->slope * j;
			if (tab->map[i + 1][j] > 0 || tab->map[i][j] > 0)
				draw_line(mlx_info, tab, 0xFF66B2);
			else
				draw_line(mlx_info, tab, 0xFFCCE5);
			tab->x0 = tab->x1;
			tab->y0 = tab->y1;
			i++;
		}
		j++;
		if (j < tab->nb_num)
			{
			tab->x0 = elem->start_x + tab->inc_x * j + tab->map[0][j] * elem->ratio_x;
			tab->y0 = elem->start_y - elem->slope * j + tab->map[0][j] * elem->ratio_y;
		}
	}m->start_y + ((tab->map[0][0]) * elem->ratio_y);
}

void	para_draw(t_mlx_infos *mlx_info, t_map_infos *tab)
{
	int		i;
	int		j;
	t_draw	*elem;

	elem = (t_draw*)malloc(sizeof(*elem));
	// fill_elem(); --> calcul ratio_x/ratio_y/slope/start_x/start_y & tab->inc_x/tab->inc_y
	elem->ratio_x = 0;
	elem->ratio_y = -2;
	elem->slope = 15;
	tab->inc_x = 300 / tab->nb_num;
	tab->inc_y = 150 / tab->nb_line;
	elem->start_x = 150;
	elem->start_y = 800;

	draw_hlines(mlx_info, tab, elem);
	draw_vlines(mlx_info, tab, elem);
	mlx_put_image_to_window(mlx_info->ptr, mlx_info->win, mlx_info->img, 0, 0);
}

int		deal_key(int key, t_mlx_infos *mlx_info)
{
	static int	i = 0;
	static int	j = 0;

	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 49)
	{
		i = 0;
		j = 0;
		mlx_put_image_to_window(mlx_info->ptr, mlx_info->win, mlx_info->img, i, j);
	}
	if (key == 53)
	{
		mlx_destroy_image(mlx_info->ptr, mlx_info->img);
		mlx_clear_window(mlx_info->ptr, mlx_info->win);
		mlx_destroy_window(mlx_info->ptr, mlx_info->win);
		exit(0);
	}
	if (key == 123)
	{
		i -= 10;
		mlx_put_image_to_window(mlx_info->ptr, mlx_info->win, mlx_info->img, i, j);
	}
	if (key == 124)
	{
		i += 10;
		mlx_put_image_to_window(mlx_info->ptr, mlx_info->win, mlx_info->img, i, j);
	}
	if (key == 125)
	{
		j += 10;
		mlx_put_image_to_window(mlx_info->ptr, mlx_info->win, mlx_info->img, i, j);
	}
	if (key == 126)
	{
		j -= 10;
		mlx_put_image_to_window(mlx_info->ptr, mlx_info->win, mlx_info->img, i, j);
	}
	return (0);
}
