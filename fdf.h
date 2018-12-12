/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:00:04 by aceciora          #+#    #+#             */
/*   Updated: 2018/12/12 11:43:45 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <math.h>

// Struct pour draw_line()
typedef struct	s_line
{
	int			w;
	int			h;
	int			dx1;
	int			dx2;
	int			dy1;
	int			dy2;
	int			longest;
	int			shortest;
	int			numerator;
}				t_line;

// Struct pour draw
typedef struct	s_draw
{
	int			start_x;
	int			start_y;
	int			ratio_x;
	int			ratio_y;
	int			slope;
}				t_draw;

// struct pour la map et les x, y (draw())
typedef struct	s_map_infos
{
	int			**map;
	int			nb_line;
	int			nb_num;
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			inc_x;
	int			inc_y;
}				t_map_infos;

// Struct pour les retour des fonctions de la mlx
typedef struct	s_mlx_infos
{
	void		*ptr;
	void		*win;
	void		*img;
	int			*img_str;
	int			bpp;
	int			s_l;
	int			endian;
}				t_mlx_infos;

void			*initialize(void);
void			*create_window(void *mlx_ptr);
void			para_draw(t_mlx_infos *mlx_info, t_map_infos *tab);
int				deal_key(int key, t_mlx_infos *mlx_info);

#endif
