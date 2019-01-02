/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 14:47:22 by aceciora          #+#    #+#             */
/*   Updated: 2019/01/02 16:48:02 by aceciora         ###   ########.fr       */
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
//	double				multx;
	double				multy;
	int					tab_value;
}						t_map_datas;

typedef struct			s_mlx_infos
{
	double				win_w;
	double				win_h;
	void				*ptr;
	void				*win;
	void				*img;
	int					*img_str;
	int					bpp;
	int					s_l;
	int					endian;
}						t_mlx_infos;

typedef struct			s_draw
{
	int					w;
	int					h;
	int					dx1;
	int					dx2;
	int					dy1;
	int					dy2;
	int					longest;
	int					shortest;
	int					numerator;
}						t_draw;

void					get_win_size(t_mlx_infos *infos, t_map_datas *datas);
void					initialize(t_mlx_infos *infos);
void					create_window(t_mlx_infos *infos);
void					modif_coord(t_list_coord *list, t_map_datas *datas);

#endif
