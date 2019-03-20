/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_and_menu.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:13:20 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/20 16:51:15 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	background_color(t_fdf *fdf)
{
	int	i;

	i = 0;
	while (i < WIDTH * HEIGHT)
	{
		if (i % WIDTH > MENU_WIDTH)
			fdf->mlx_data_addr[i] = 0x04062E;
		else
			fdf->mlx_data_addr[i] = 0x0E1037;
		i++;
	}
}

void	display_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = fdf->mlx_ptr;
	win = fdf->mlx_win;
	mlx_string_put(mlx, win, 85, y += 50, TEXT_COLOR, "How to Use");
	mlx_string_put(mlx, win, 35, y += 55, TEXT_COLOR, "Zoom : Scroll or +/-");
	mlx_string_put(mlx, win, 35, y += 50, TEXT_COLOR, "Move : Right click - Drag");
	mlx_string_put(mlx, win, 35, y += 50, TEXT_COLOR, "Move : Arrows");
	mlx_string_put(mlx, win, 35, y += 50, TEXT_COLOR, "Altitude : 'u' / 'i'");
	mlx_string_put(mlx, win, 35, y += 50, TEXT_COLOR, "Rotate : Left click - Drag");
	mlx_string_put(mlx, win, 35, y += 50, TEXT_COLOR, "Rotate :");
	mlx_string_put(mlx, win, 77, y += 45, TEXT_COLOR, "X-Axis - '2' / '8'");
	mlx_string_put(mlx, win, 77, y += 45, TEXT_COLOR, "Y-Axis - '4' / '6'");
	mlx_string_put(mlx, win, 77, y += 45, TEXT_COLOR, "Z-Axis - '/' / '*'");
	mlx_string_put(mlx, win, 35, y += 50, TEXT_COLOR, "Change projection : 'P'");
	mlx_string_put(mlx, win, 35, y += 50, TEXT_COLOR, "Change color : 'C'");
	mlx_string_put(mlx, win, 35, y += 50, TEXT_COLOR, "Reset : SPACE");
	mlx_string_put(mlx, win, 35, y += 50, TEXT_COLOR, "Exit : ESC");
}
