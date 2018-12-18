/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:04:12 by aceciora          #+#    #+#             */
/*   Updated: 2018/12/18 15:26:04 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

void	get_win_size(t_mlx_infos *infos, t_map_datas *datas)
{
	infos->win_w = datas->max_x - datas->min_x + 100;
	infos->win_h = datas->max_y - datas->min_y + 100;
	if (infos->win_w > 1000)
		infos->win_w = 1000;
	if (infos->win_h > 800)
		infos->win_h = 800;
	if (infos->win_w < 500)
		infos->win_w = 500;
	if (infos->win_h < 600)
		infos->win_h = 600;
	datas->inc_x = (infos->win_w - 100) / datas->tot_cols;
	datas->inc_y = (infos->win_h - 100) / datas->tot_rows;
	printf("%d, %d\n", infos->win_w, infos->win_h);
	printf("%d, %d\n", datas->inc_x, datas->inc_y);
}

void	initialize(t_mlx_infos *infos)
{
	infos->ptr = mlx_init();
	if (infos->ptr == NULL)
	{
		ft_putstr("failed to set up connection to the X server\n");
		exit(-1);
	}
}

void	create_window(t_mlx_infos *infos)
{
	infos->win = mlx_new_window(infos->ptr, infos->win_w, infos->win_h, "fdf");
	if (infos->win == NULL)
	{
		ft_putstr("failed to create a new window\n");
		exit(-1);
	}
}
