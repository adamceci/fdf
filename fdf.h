/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:55:45 by aceciora          #+#    #+#             */
/*   Updated: 2019/02/13 16:33:39 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "mlx.h"
#include "libft.h"

typedef struct		s_list_c
{
	struct s_coord	*coord;
	size_t			content_size;
	struct s_list_c	*next;
}					t_list_c;

typedef struct	s_coord
{
	int			i;
	int			j;
	int			x;
	int			y;
	int			z;
}				t_coord;

typedef struct	s_data
{
	int			min_x;
	int			max_x;
	int			min_y;
	int			max_y;
	int			c_min_x;
	int			c_max_x;
	int			r_min_y;
	int			r_max_y;
	int			cols;
	int			rows;
	double		multx;
	double		multy;
}				t_data;

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	int			win_h;
	int			win_w;
}				t_mlx;

typedef struct	s_bresen
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
}				t_bresen;

t_list_c		*ft_listnew(t_coord *coord, size_t content_size);
void			ft_listappend(t_list_c *lst, t_list_c *new);
