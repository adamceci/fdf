/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:00:05 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/19 13:44:10 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf2.h"
#include "keys.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == MAIN_PLUS || key == PAD_PLUS || key == SCROLL_UP)
		fdf->camera->zoom += 1;
	else if (key == MAIN_MINUS || key == PAD_MINUS || key == SCROLL_DOWN)
		fdf->camera->zoom -= 1;
	(fdf->camera->zoom < 0) ? fdf->camera->zoom = 0 : fdf->camera->zoom;
}

void	translation(int key, t_fdf *fdf)
{
	if (key == LEFT_ARROW)
		fdf->camera->x_margin -= 10;
	else if (key == RIGHT_ARROW)
		fdf->camera->x_margin += 10;
	else if (key == UP_ARROW)
		fdf->camera->y_margin -= 10;
	else if (key == DOWN_ARROW)
		fdf->camera->y_margin += 10;
}

void	 altitude(int key, t_fdf *fdf)
{
	if (key == U)
		fdf->camera->altitude += 0.1;
	else if (key == I)
		fdf->camera->altitude -= 0.1;
}

void	change_projection(int key, t_fdf *fdf)
{
	if (key == P)
	{
		fdf->camera->x_angle = 0;
		fdf->camera->y_angle = 0;
		fdf->camera->z_angle = 0;
		if (fdf->camera->projection == ISO)
			fdf->camera->projection = PARALLEL;
		else
			fdf->camera->projection = ISO;
	}
}

void	reset(int key, t_fdf *fdf)
{
	if (key == SPACE)
		init_camera(fdf);
}
