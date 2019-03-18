/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:17:19 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/18 14:34:45 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf2.h"

void	rotate_x_axis(int *y, int *z, double x_angle)
{
	int	new_y;
	int	new_z;

	new_y = *y * cos(x_angle) + *z * sin(x_angle);
	new_z = *y * -sin(x_angle) + *z * cos(x_angle);
	*y = new_y;
	*z = new_z;
}

void	rotate_y_axis(int *x, int *z, double y_angle)
{
	int	new_x;
	int	new_z;

	new_x = *x * cos(y_angle) + *z * -sin(y_angle);
	new_z = *x * sin(y_angle) + *z * cos(y_angle);
	*x = new_x;
	*z = new_z;
}

void	rotate_z_axis(int *x, int *y, double z_angle)
{
	int	new_x;
	int	new_y;

	new_x = *x * cos(z_angle) + *y * sin(z_angle);
	new_y = *x * -sin(z_angle) + *y * cos(z_angle);
	*x = new_x;
	*y = new_y;
}
