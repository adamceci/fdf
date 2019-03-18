/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:43:55 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/18 18:48:43 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf2.h"

void	init_camera(t_fdf *fdf)
{
	int			biggest;

	if (!(fdf->camera))
		if (!(fdf->camera = (t_camera*)malloc(sizeof(t_camera))))
			ft_exit3("malloc() failed", fdf);
	biggest = fdf->map->nb_lines;
	if (fdf->map->nb_cols >= biggest)
		biggest = fdf->map->nb_cols;
	fdf->camera->zoom = round(30 * 20 / biggest);
	fdf->camera->x_angle = 0;
	fdf->camera->y_angle = 0;
	fdf->camera->z_angle = 0;
	fdf->camera->z_divisor = 2;
	fdf->camera->altitude = 1;
	fdf->camera->x_margin = 0;
	fdf->camera->y_margin = 0;
}

void	init_mlx(t_fdf *fdf)
{
	if (!(fdf->mlx_ptr = mlx_init()))
		ft_exit3("failed to set up connection to the X server", fdf);
	if (!(fdf->mlx_win = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "fdf")))
		ft_exit3("failed to create a new window", fdf);
	if (!(fdf->mlx_img = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT)))
		ft_exit3("failed to create an image", fdf);
	fdf->mlx_data_addr = (int*)mlx_get_data_addr(fdf->mlx_img, &(fdf->bpp), &(fdf->s_l), &(fdf->endian));
}
