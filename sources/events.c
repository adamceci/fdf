/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:36:39 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/18 19:02:56 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf2.h"
#include "keys.h"

static void	redraw(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->mlx_img);
	if (!(fdf->mlx_img = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT)))
		ft_exit3("failed to create an image", fdf);
	fdf->mlx_data_addr = (int*)mlx_get_data_addr(fdf->mlx_img, &(fdf->bpp),
											&(fdf->s_l), &(fdf->endian));
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->mlx_win, fdf->mlx_img, 0, 0);
}

static int	key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (key == MAIN_PLUS || key == PAD_PLUS ||
			key == MAIN_MINUS || key == PAD_MINUS)
		zoom(key, fdf);
	if (key == LEFT_ARROW || key == RIGHT_ARROW ||
			key == UP_ARROW || key == DOWN_ARROW)
		translation(key, fdf);
	if (key == U || key == I)
		altitude(key, fdf);
	if (key == X_ROT_L || key == X_ROT_R)
		rotate_x(key, fdf);
	if (key == Y_ROT_U || key == Y_ROT_D)
		rotate_y(key, fdf);
	if (key == Z_ROT_L || key == Z_ROT_R)
		rotate_z(key, fdf);
	if (key == P)
		change_projection(key, fdf);
	if (key == SPACE)
		reset(key, fdf);
	if (key == ESC)
		ft_exit3("Au revoir mon petit lapin, tot ziens mijn klein konijntje",
					fdf);
	redraw(fdf);
	printf("%d\n", key);
	return (0);
}

static int	mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	(void)x;
	(void)y;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		zoom(button, fdf);
	redraw(fdf);
	printf("button = %d\n", button);
	return (0);
}

void		manage_events(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_win, 2, 0, key_press, fdf);
	mlx_hook(fdf->mlx_win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->mlx_win, 17, 0, ft_exit4, fdf);
}
