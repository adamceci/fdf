/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:43:55 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/15 16:38:06 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf2.h"
#include "mlx.h"

t_camera	*init_camera(t_fdf *fdf)
{
	t_camera	*camera;

	if (!(camera = (t_camera*)malloc(sizeof(*camera))))
	{
		free(fdf->map->coords_arr);
		ft_exit("malloc() failed");
	}
	camera->zoom = 100;
	camera->x_angle = 0;
	camera->y_angle = 0;
	camera->z_angle = 0;
	camera->z_divisor = 1;
	camera->x_margin = 0;
	camera->y_margin = 0;
	return (camera);
}

void	init_mlx(t_fdf *fdf)
{
	if (!(fdf->mlx_ptr = mlx_init()))
	{
		free(fdf->map->coords_arr);
		ft_exit("failed to set up connection to the X server");
	}
	if (!(fdf->mlx_win = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "fdf")))
	{
		free(fdf->map->coords_arr);
		ft_exit("failed to create a new window");
	}
	if (!(fdf->mlx_img = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT)))
	{
//		free();
		ft_exit("failed to create an image");
	}
	fdf->mlx_data_addr = mlx_get_data_addr(fdf->mlx_img, &(fdf->bpp), &(fdf->s_l), &(fdf->endian));
}
