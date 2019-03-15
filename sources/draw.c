/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:21:05 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/15 16:32:07 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf2.h"
#include "mlx.h"
#include <math.h>
/*
static void	bresenham(t_points p1, t_points p2, t_fdf *fdf)
{

}
*/

static void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_points	projection(t_points p, t_fdf *fdf)
{
	p.x *= fdf->camera->zoom;
	p.y *= fdf->camera->zoom;
	p.z *= fdf->camera->zoom / fdf->camera->z_divisor;
	p.x -= (fdf->map->nb_cols * fdf->camera->zoom) / 2;
	p.y -= (fdf->map->nb_lines * fdf->camera->zoom) / 2;
	//	rotate_x(&p.y, &p.z, fdf->camera->x_angle);
	//	rotate_y(&p.x, &p.z, fdf->camera->y_angle);
	//	rotate_z(&p.x, &p.y, fdf->camera->z_angle);
	if (fdf->camera->projection == ISO)
		iso(&p.x, &p.y, p.z);
	p.x += (WIDTH - MENU_WIDTH) / 2 + fdf->camera->x_margin + MENU_WIDTH;
	p.y += (HEIGHT + fdf->map->nb_lines * fdf->camera->zoom) / 2
		+ fdf->camera->y_margin;
	return (p);
}

t_points	new_point(int x, int y, t_map *map)
{
	t_points	p;
	int			index;

	index = x + y * map->nb_cols;
	p.x = x;
	p.y = y;
	p.z = map->coords_arr[index];
	return (p);
}

void		draw(t_fdf *fdf)
{
	t_points	p;
	int	x;
	int	y;

	y = 0;
	while (y < fdf->map->nb_lines)
	{
		x = 0;
		while (x < fdf->map->nb_cols)
		{
			p = projection(new_point(x, y, fdf->map), fdf);
			mlx_pixel_put(fdf->mlx_ptr, fdf->mlx_win, p.x, p.y, 0xFFFFFF);
			//			if (x < fdf->map->nb_cols - 1)
			//				bresenham(projection(new_point(x, y, fdf->map), fdf),
			//						projection(new_point(x + 1, y, fdf->map), fdf), fdf);
			//			if (y < fdf->map->nb_lines - 1)
			//				bresenham(projection(new_point(x, y, fdf->map), fdf),
			//						projection(new_point(x, y + 1, fdf->map), fdf), fdf);
			x++;
		}
		y++;
	}
}
