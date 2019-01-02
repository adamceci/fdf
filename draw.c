/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:37:03 by aceciora          #+#    #+#             */
/*   Updated: 2019/01/02 17:11:33 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_abs(int nb)
{
	if (nb >= 0)
		return (nb);
	return (-nb);
}

static void	get_draw_infos(t_list_coord *list, t_line *elem)
{
	elem->w = list->coord[j + 1].x - list->coord[j].x;
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

static void	draw_line(t_list_coord *list, t_map_datas *datas, t_mlx_infos *infos, int color)
{
	t_draw	*elem;
	int		i;

	elem = (t_line*)malloc(sizeof(*elem));
	get_draw_infos(list, elem);
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
			list->coord[j].x += elem->dx2;
			tab->y0 += elem->dy2;
		}
		i++;
	}
}

void	draw(t_list_coord *list, t_map_datas *datas, t_mlx_infos *infos)
{

	color = 0xFFFFFF;
	draw_line(list, datas, infos, color);
}
