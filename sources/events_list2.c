/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:40:24 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/18 19:02:54 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf2.h"
#include "keys.h"

void	rotate_x(int key, t_fdf *fdf)
{
	if (key == X_ROT_L)
		fdf->camera->x_angle += 0.072;
	if (key == X_ROT_R)
		fdf->camera->x_angle -= 0.072;
}

void	rotate_y(int key, t_fdf *fdf)
{
	if (key == Y_ROT_U)
		fdf->camera->y_angle += 0.072;
	if (key == Y_ROT_D)
		fdf->camera->y_angle -= 0.072;
}

void	rotate_z(int key, t_fdf *fdf)
{
	if (key == Z_ROT_L)
		fdf->camera->z_angle += 0.072;
	if (key == Z_ROT_R)
		fdf->camera->z_angle -= 0.072;
}
