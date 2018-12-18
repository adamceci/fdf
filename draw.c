/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:37:03 by aceciora          #+#    #+#             */
/*   Updated: 2018/12/18 15:26:06 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
