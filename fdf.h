/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:14:42 by aceciora          #+#    #+#             */
/*   Updated: 2018/12/19 13:54:55 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "mlx.h"

typedef struct			s_list_coord
{
	struct s_coord		*coord;
	struct s_list_coord	*next;
}						t_list_coord;

typedef struct			s_coord
{
	int					x;
	int					y;
	int					z;
	int					i;
	int					j;
}						t_coord;

typedef struct			s_map_datas
{
	int					start_x;
	int					start_y;
	int					inc_x;
	int					inc_y;
	int					min_x; // --> OK
	int					min_y; // --> OK
	int					max_x; // --> OK
	int					max_y; // --> OK
	int					tot_cols;
	int					tot_rows;
	double				ratio_x;
	double				ratio_y;
	double				mult;
	int					tab_value;
}						t_map_datas;

typedef struct			s_mlx_infos
{
	int					win_w;
	int					win_h;
	void				*ptr;
	void				*win;
	void				*img;
	int					*img_str;
	int					bpp;
	int					s_l;
	int					endian;
}						t_mlx_infos;

void					get_win_size(t_mlx_infos *infos, t_map_datas *datas);
void					initialize(t_mlx_infos *infos);
void					create_window(t_mlx_infos *infos);

#endif
