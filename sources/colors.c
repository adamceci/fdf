/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:57:02 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/21 15:39:01 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	get_percent(int z, t_fdf *fdf)
{
	double percent;

	if (fdf->map->z_range == 0)
		percent = 1.0;
	else
		percent = (double)(z - fdf->map->z_min) / (double)fdf->map->z_range;
	return (percent);
}

void			get_color(t_points *p, t_fdf *fdf)
{
	p->percent = get_percent(p->z, fdf);
	if (fdf->tab_ratio[0] == 1)
		p->tab_color[0] = 255;
	else
		p->tab_color[0] = p->percent * 255;
	if (fdf->tab_ratio[1] == 1)
		p->tab_color[1] = 255;
	else
		p->tab_color[1] = p->percent * 255;
	if (fdf->tab_ratio[2] == 1)
		p->tab_color[2] = 255;
	else
		p->tab_color[2] = p->percent * 255;
}
