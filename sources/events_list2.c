/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:40:24 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/20 17:03:34 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

void	rotate_x(int key, t_fdf *fdf)
{
	if (key == X_ROT_L)
		fdf->camera->x_angle += 0.072;
	if (key == X_ROT_R)
		fdf->camera->x_angle -= 0.072;
	redraw(fdf);
}

void	rotate_y(int key, t_fdf *fdf)
{
	if (key == Y_ROT_U)
		fdf->camera->y_angle += 0.072;
	if (key == Y_ROT_D)
		fdf->camera->y_angle -= 0.072;
	redraw(fdf);
}

void	rotate_z(int key, t_fdf *fdf)
{
	if (key == Z_ROT_L)
		fdf->camera->z_angle += 0.072;
	if (key == Z_ROT_R)
		fdf->camera->z_angle -= 0.072;
	redraw(fdf);
}

void	change_color(int key, t_fdf *fdf)
{
	if (key == C)
	{
		if (fdf->tab_ratio[0] == 1)
		{
			fdf->tab_ratio[0] = 0;
			fdf->tab_ratio[1] = 1;
			fdf->tab_ratio[2] = 0;
		}
		else if (fdf->tab_ratio[1] == 1)
		{
			fdf->tab_ratio[0] = 0;
			fdf->tab_ratio[1] = 0;
			fdf->tab_ratio[2] = 1;
		}
		else if (fdf->tab_ratio[2] == 1)
		{
			fdf->tab_ratio[0] = 1;
			fdf->tab_ratio[1] = 0;
			fdf->tab_ratio[2] = 0;
		}
	}
	redraw(fdf);
}

void	draw_points(int keym t_fdf *fdf)
{
	if (key == POINT)
	{
	}
}
