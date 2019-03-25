/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:27:16 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/21 15:47:56 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	point_color(t_points *p1, t_points p2)
{
	p1->color = p1->tab_color[0] * 256 * 256 + p1->tab_color[1] * 256 +
				p1->tab_color[2];
	p2.color = p2.tab_color[0] * 256 * 256 + p2.tab_color[1] * 256 +
				p2.tab_color[2];
	if (p1->color != p2.color)
		p1->color = (p1->tab_color[0] + p2.tab_color[0]) / 2 * 256 * 256 +
					(p1->tab_color[1] + p2.tab_color[1]) / 2 * 256 +
					(p1->tab_color[2] + p2.tab_color[2]) / 2;
}

static void	init_bresenham(t_points p1, t_points p2, t_bresenham *elem)
{
	elem->dx1 = 0;
	elem->dy1 = 0;
	elem->dx2 = 0;
	elem->dy2 = 0;
	elem->w = p2.x - p1.x;
	elem->h = p2.y - p1.y;
	(elem->w < 0) ? (elem->dx1 = -1) : (elem->dx1);
	(elem->w > 0) ? (elem->dx1 = 1) : (elem->dx1);
	(elem->h < 0) ? (elem->dy1 = -1) : (elem->dy1);
	(elem->h > 0) ? (elem->dy1 = 1) : (elem->dy1);
	(elem->w < 0) ? (elem->dx2 = -1) : (elem->dx2);
	(elem->w > 0) ? (elem->dx2 = 1) : (elem->dx2);
	elem->longest = abs(elem->w);
	elem->shortest = abs(elem->h);
	if (!(elem->longest > elem->shortest))
	{
		ft_swap(&elem->longest, &elem->shortest);
		if (elem->h < 0)
			elem->dy2 = -1;
		else if (elem->h > 0)
			elem->dy2 = 1;
		elem->dx2 = 0;
	}
	elem->numerator = elem->longest / 2;
}

void		bresenham(t_points p1, t_points p2, t_fdf *fdf)
{
	int			i;
	t_bresenham	elem;

	point_color(&p1, p2);
	init_bresenham(p1, p2, &elem);
	i = 0;
	while (i <= elem.longest)
	{
		if (p1.x > MENU_WIDTH && p1.x < WIDTH && p1.y > 0 && p1.y < HEIGHT)
			fdf->mlx_data_addr[p1.x + WIDTH * p1.y] = p1.color;
		elem.numerator += elem.shortest;
		if (!(elem.numerator < elem.longest))
		{
			elem.numerator -= elem.longest;
			p1.x += elem.dx1;
			p1.y += elem.dy1;
		}
		else
		{
			p1.x += elem.dx2;
			p1.y += elem.dy2;
		}
		i++;
	}
}
