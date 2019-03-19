/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:27:16 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/19 15:44:28 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf2.h"

/*
double	get_percent(int cur_z, int next_z, int min_z, int max_z)
{
	double percent;

	if (max_z == min_z)
		percent = 1.0;
	else if(cur_z > next_z)
		percent = (next_z + cur_z) / 2.0 / (max_z - min_z);
	else if (cur_z < next_z)
		percent = (cur_z + next_z) / 2.0 / (max_z - min_z);
	else
		percent = (double)cur_z / (max_z - min_z);
	return (percent);
}

int		get_color(int cur_z, int next_z, int min_z, int max_z)
{
	int		color;
	double	percent;

	percent = get_percent(cur_z, next_z, min_z, max_z);
	if (percent < 0.1)
		color = 16025993;
	else if (percent < 0.2)
		color = 16097906;
	else if (percent < 0.3)
		color = 16170076;
	else if (percent < 0.4)
		color = 15980904;
	else if (percent < 0.5)
		color = 15857525;
	else if (percent < 0.6)
		color = 11859329;
	else if (percent < 0.7)
		color = 7926926;
	else if (percent < 0.8)
		color = 9762495;
	else if (percent < 0.9)
		color = 11598320;
	else if (percent <= 1.0)
		color = 12517370;
	return (color);
}
*/
void	init_bresenham(t_points p1, t_points p2, t_bresenham *elem)
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
	if (!(elem->longest>elem->shortest))
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

void	bresenham(t_points p1, t_points p2, t_fdf *fdf)
{
	int			i;
	t_bresenham	elem;

	init_bresenham(p1, p2, &elem);
	i = 0;
	while (i <= elem.longest)
	{
		if (p1.x > MENU_WIDTH && p1.x < WIDTH && p1.y > 0 && p1.y < HEIGHT)
			fdf->mlx_data_addr[p1.x + WIDTH * p1.y] = 0xFFFFFF;
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
