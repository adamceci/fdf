/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 10:57:49 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/15 16:26:16 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF2_H
# define FDF2_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "libft.h"

# define HEIGHT 1080
# define WIDTH	1920
# define MENU_WIDTH	250

typedef enum
{
	ISO,
	PARALLEL
}	t_projection;

typedef struct	s_points
{
	int				x;
	int				y;
	int				z;
	struct s_points	*next;
//	int				color;
}					t_points;

typedef struct		s_camera
{
	t_projection	projection;
	int				zoom;
	double			x_angle;
	double			y_angle;
	double			z_angle;
	float			z_divisor;
	int				x_margin;
	int				y_margin;
}					t_camera;

typedef struct		s_map
{
	int				nb_cols;
	int				nb_lines;
	int				*coords_arr;
//	int				*colors_arr;
//	int				z_min;
//	int				z_max;
//	int				z_range;
}					t_map;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*mlx_img;
	char			*mlx_data_addr;
	int				bpp;
	int				s_l;
	int				endian;
	t_camera		*camera;
	t_map			*map;
//	t_mouse			*mouse;
}					t_fdf;

void				ft_exit(const char *s);
void				ft_exit_and_free(const char *s, t_points **head);
t_map				*read_map(int fd, t_points **head);
void				lst_to_array(t_points **head, t_map *map);
void				lst_push(t_points **head, t_points *current);
void				lst_pop(t_points **head);
t_camera			*init_camera(t_fdf *fdf);
void				init_mlx(t_fdf *fdf);
//void				print_arr(t_map map);
void				draw(t_fdf *fdf);

#endif

