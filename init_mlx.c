/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:04:12 by aceciora          #+#    #+#             */
/*   Updated: 2018/12/17 18:29:29 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_win_size(t_mlx_infos *infos, t_map_datas *datas)
{
	// if pas trop grand
	infos->win_w = datas->max_x - datas->min_x + 50;
	infos->win_h = datas->max_y - datas->min_y + 50;
	if (infos->win_w > 2000)
		infos->win_w = 2000;
	if (infos->win_h > 1500)
		infos->win_h = 1500;
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
