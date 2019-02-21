/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:55:45 by aceciora          #+#    #+#             */
/*   Updated: 2019/02/21 17:24:02 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <math.h>
#include "mlx.h"
#include "libft.h"

typedef struct		s_list_c
{
	struct s_coord	*coord;
	size_t			content_size;
	struct s_list_c	*next;

	int			min_x;
	int			max_x;
	int			min_y;
	int			max_y;
	int			cols;
	int			rows;
	double		multx;
	double		multy;
	int			min_z;
	int			max_z;
	int			altitude;
	int			color;
	double		zoom;
	int			addx;
	int			addy;

	void		*ptr;
	void		*win;
	int			win_h;
	int			win_w;
	void		*img;
	int			*img_str;
	int			bpp;
	int			s_l;
	int			endian;
}					t_list_c;

typedef struct	s_coord
{
	int			i;
	int			j;
	int			x;
	int			y;
	int			z;
}				t_coord;

typedef struct	s_bresen
{
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			w;
	int			h;
	int			dx1;
	int			dx2;
	int			dy1;
	int			dy2;
	int			longest;
	int			shortest;
	int			numerator;
}				t_bresen;

t_list_c		*ft_listnew(t_coord *coord, size_t content_size);
void			ft_listappend(t_list_c *lst, t_list_c *new);
