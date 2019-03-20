/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf2.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 10:57:49 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/20 16:57:41 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdio.h>
#include <errno.h>

#include "libft.h"
#include "mlx.h"
#include <math.h>

# define HEIGHT 1080
# define WIDTH	1920
# define MENU_WIDTH	320
# define TEXT_COLOR 0x999999

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
	double			percent;
	int				tab_color[3];
	int				color;
}					t_points;

typedef struct		s_camera
{
	t_projection	projection;
	int				zoom;
	double			x_angle;
	double			y_angle;
	double			z_angle;
	float			z_divisor;
	float			altitude;
	int				x_margin;
	int				y_margin;
}					t_camera;

typedef struct		s_map
{
	int				nb_cols;
	int				nb_lines;
	int				*coords_arr;
//	int				*colors_arr;
	int				z_min;
	int				z_range;
}					t_map;

typedef struct		s_mouse
{
	int				is_pressed;
	int				x;
	int				y;
	int				prev_x;
	int				prev_y;
}					t_mouse;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*mlx_img;
	int				*mlx_data_addr;
	int				bpp;
	int				s_l;
	int				endian;
	double			tab_ratio[3];
	t_camera		*camera;
	t_map			*map;
	t_mouse			*mouse;
}					t_fdf;

typedef struct		s_bresenham
{
	int				dx1;
	int				dx2;
	int				dy1;
	int				dy2;
	int				w;
	int				h;
	int				longest;
	int				shortest;
	int				numerator;
}					t_bresenham;

void				ft_exit1(const char *s);
void				ft_exit2(const char *s, t_points **head, t_fdf *fdf);
void				ft_exit3(const char *s, t_fdf *fdf);
int					ft_exit4(void *param);
void				read_map(int fd, t_points **head, t_fdf *fdf);
void				lst_to_array(t_points **head, t_fdf *fdf);
void				lst_push(t_points **head, t_points *current);
void				lst_pop(t_points **head);
void				init_fdf(t_fdf *fdf);
void				init_camera(t_fdf *fdf);
void				init_mlx(t_fdf *fdf);
void				init_mouse(t_fdf *fdf);
void				draw(t_fdf *fdf);
void				get_color(t_points *p, t_fdf *fdf);
void				rotate_x_axis(int *y, int *z, double x_angle);
void				rotate_y_axis(int *x, int *z, double y_angle);
void				rotate_z_axis(int *x, int *y, double z_angle);
void				bresenham(t_points p1, t_points p2, t_fdf *fdf);
void				manage_events(t_fdf *fdf);
void				zoom(int key, t_fdf *fdf);
void				translation(int key, t_fdf *fdf);
void				altitude(int key, t_fdf *fdf);
void				change_projection(int key, t_fdf *fdf);
void				change_color(int key, t_fdf *fdf);
void				reset(int key, t_fdf *fdf);
void				rotate_x(int key, t_fdf *fdf);
void				rotate_y(int key, t_fdf *fdf);
void				rotate_z(int key, t_fdf *fdf);
void				background_color(t_fdf *fdf);
void				display_menu(t_fdf *fdf);
void				redraw(t_fdf *fdf);

#endif
