/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 15:21:05 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/19 17:52:09 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso(int *x, int *y, int z)
{
	int new_x;
	int new_y;

	new_x = (*x - *y) * cos(0.523599);
	new_y = -z + (*x + *y) * sin(0.523599);
	*x = new_x;
	*y = new_y;
}

t_points	projection(t_points p, t_fdf *fdf)
{
	p.x *= fdf->camera->zoom;
	p.y *= fdf->camera->zoom;
	p.z *= fdf->camera->zoom / fdf->camera->z_divisor * fdf->camera->altitude;
	p.x -= fdf->map->nb_cols / 2 * fdf->camera->zoom;
	p.y -= fdf->map->nb_lines/ 2 * fdf->camera->zoom;
	rotate_x_axis(&p.y, &p.z, fdf->camera->x_angle);
	rotate_y_axis(&p.x, &p.z, fdf->camera->y_angle);
	rotate_z_axis(&p.x, &p.y, fdf->camera->z_angle);
	if (fdf->camera->projection == ISO)
		iso(&p.x, &p.y, p.z);
	p.x += (WIDTH - MENU_WIDTH) / 2 + MENU_WIDTH + fdf->camera->x_margin;
	p.y += HEIGHT / 2 + fdf->camera->y_margin;
	return (p);
}

static double	get_percent(int z, int z_range)
{
	double percent;

	if (z_range == 0)
		percent = 1.0;
//	else if(cur_z > next_z)
//		percent = (next_z + cur_z) / 2.0 / z_range;
//	else if (cur_z < next_z)
//		percent = (cur_z + next_z) / 2.0 / z_range;
	else
		percent = (double)z / z_range;
	return (percent);
}

static int		get_color(int z, int z_range)
{
	int		color;
	double	percent;

	color = 0xffe5e5;
	percent = get_percent(z, z_range);
	if (percent < 0.1)
		color = 0xffc5c5;
	else if (percent < 0.2)
		color = 0xffa5a5;
	else if (percent < 0.3)
		color = 0xff8585;
	else if (percent < 0.4)
		color = 0xff7575;
	else if (percent < 0.5)
		color = 0xff7070;
	else if (percent < 0.6)
		color = 0xff6565;
	else if (percent < 0.7)
		color = 0xff6060;
	else if (percent < 0.8)
		color = 0xff5252;
	else if (percent < 0.9)
		color = 0xff4545;
	else if (percent <= 1.0)
		color = 0xff0000;
	return (color);
}

t_points	new_point(int x, int y, t_map *map)
{
	t_points	p;
	int			index;

	index = x + y * map->nb_cols;
	p.x = x;
	p.y = y;
	p.z = map->coords_arr[index];
	p.color = get_color(p.z, map->z_range);
	return (p);
}

void		draw(t_fdf *fdf)
{
	int	x;
	int	y;

	background_color(fdf);
	y = 0;
	while (y < fdf->map->nb_lines)
	{
		x = 0;
		while (x < fdf->map->nb_cols)
		{
			if (x < fdf->map->nb_cols - 1)
				bresenham(projection(new_point(x, y, fdf->map), fdf),
							projection(new_point(x + 1, y, fdf->map), fdf), fdf);
			if (y < fdf->map->nb_lines - 1)
				bresenham(projection(new_point(x, y, fdf->map), fdf),
							projection(new_point(x, y + 1, fdf->map), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->mlx_win, fdf->mlx_img, 0, 0);
	display_menu(fdf);
}
