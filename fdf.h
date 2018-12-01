/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:00:04 by aceciora          #+#    #+#             */
/*   Updated: 2018/12/01 14:53:12 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include "libft.h"

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
	char		*img_str;
}				t_mlx_infos;

#endif
