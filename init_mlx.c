/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:04:12 by aceciora          #+#    #+#             */
/*   Updated: 2019/01/02 16:52:38 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int		ft_round(double x)
{
	if (x < 0)
		return (x - 0.5);
	return (x + 0.5); 
}

void	get_win_size(t_mlx_infos *infos, t_map_datas *datas)
{
	datas->multy = 1.0;
	//datas->multx =;
	infos->win_w = (double)(datas->max_x - datas->min_x + 100);
	infos->win_h = (double)(datas->max_y - datas->min_y + 100);
	if (infos->win_w > 1000.0)
		infos->win_w = 1000.0;
	if (infos->win_h > 800.0)
		infos->win_h = 800.0;
	if (infos->win_w < 500.0)
		infos->win_w = 500.0;
	if (infos->win_h < 600.0)
		infos->win_h = 600.0;
	//datas_multx;
	datas->multy = (infos->win_h - 100) / (datas->max_y - datas->min_y);
	datas->inc_x = ft_round((infos->win_w - 100) / datas->tot_cols);
	if (datas->multy < 1)
		datas->inc_y = ft_round(((infos->win_h - 100) / datas->tot_rows) * datas->multy);
	if (datas->multy > 1)
		datas->inc_y = ft_round(((infos->win_h - 100) / datas->tot_rows) / datas->multy);
	datas->ratio_y *= datas->multy;
	//datas->ratio_x *= datas->multx;
//	printf("inc_y = %d\n", datas->inc_y);
//	printf("multy = %f\n", datas->multy);
//	printf("win_h = %f\n", infos->win_h);
}

void	find_new_minmax(t_list_coord *list, t_map_datas *datas, int j)
{
	static int		init = 0;

	if (!init++)
	{
		datas->min_x = list->coord[j].x;
		datas->max_x = list->coord[j].x;
		datas->min_y = list->coord[j].y;
		datas->max_y = list->coord[j].y;
	}
	if (datas->min_x > list->coord[j].x)
		datas->min_x = list->coord[j].x;
	else if (datas->max_x < list->coord[j].x)
		datas->max_x = list->coord[j].x;
	if (datas->min_y > list->coord[j].y)
		datas->min_y = list->coord[j].y;
	else if (datas->max_y < list->coord[j].y)
		datas->max_y = list->coord[j].y;
}

void				modif_coord(t_list_coord *list, t_map_datas *datas)
{
	int				i;
	int				j;
	t_list_coord	*current;

	current = list;
	i = 0;
	while (i < datas->tot_rows)
	{
		j = 0;
		while (j < datas->tot_cols)
		{
			current->coord[j].x = ft_round(j * datas->inc_x + current->coord[j].z * datas->ratio_x);
			current->coord[j].y = ft_round(i * datas->inc_y + current->coord[j].z * datas->ratio_y);
			find_new_minmax(list, datas, j);
//			printf("(%d, %d)\n", list->coord[j].x, list->coord[j].y);
//			printf("%d\n", list->coord[j].z);
			j++;
		}
		i++;
		current = current->next;
	}
//	printf("(%d, %d)\n", datas->min_y, datas->max_y);
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
