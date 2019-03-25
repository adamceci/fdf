/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:36:39 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/21 16:00:27 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

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
	if (key == C)
		change_color(key, fdf);
	change_projection(key, fdf);
	reset(key, fdf);
	if (key == ESC)
		ft_exit3("Program exited", fdf);
	return (0);
}

static int	mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	(void)x;
	(void)y;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		zoom(button, fdf);
		redraw(fdf);
	}
	if (button == LEFT_CLICK)
		fdf->mouse->is_pressed = 1;
	if (button == RIGHT_CLICK)
		fdf->mouse->is_pressed = 2;
	return (0);
}

static int	mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)button;
	(void)x;
	(void)y;
	fdf = (t_fdf*)param;
	fdf->mouse->is_pressed = 0;
	return (0);
}

static int	mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	fdf->mouse->prev_x = fdf->mouse->x;
	fdf->mouse->prev_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->is_pressed == 1)
	{
		fdf->camera->y_angle -= 0.003 * (fdf->mouse->x - fdf->mouse->prev_x);
		fdf->camera->x_angle -= 0.003 * (fdf->mouse->prev_y - fdf->mouse->y);
		redraw(fdf);
	}
	if (fdf->mouse->is_pressed == 2)
	{
		fdf->camera->x_margin += fdf->mouse->x - fdf->mouse->prev_x;
		fdf->camera->y_margin += fdf->mouse->y - fdf->mouse->prev_y;
		redraw(fdf);
	}
	return (0);
}

void		manage_events(t_fdf *fdf)
{
	mlx_hook(fdf->mlx_win, 2, 0, key_press, fdf);
	mlx_hook(fdf->mlx_win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->mlx_win, 6, 0, mouse_move, fdf);
	mlx_hook(fdf->mlx_win, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->mlx_win, 17, 0, ft_exit4, fdf);
}
