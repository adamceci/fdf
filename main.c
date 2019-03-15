/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:03:27 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/11 15:00:43 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_cols(char *line, int n)
{
	static int	count = 0;
	static int	cols = 0;
	int			i;
	char		**tab;
	int			val;

	if (!n)
	{
		tab = ft_strsplit(line, ' ');
		i = 0;
		while (tab[i])
			i++;
		if (!count++)
			cols = i;
		(i != cols) ? (val = 0) : (val = 1);
			i = -1;
		while (tab[++i])
			free(tab[i]);
		free(tab);
		return (val);
	}
	return (cols);
}

t_coord	*fill_coord(t_coord *coord, char *line, int i, int *j)
{
	char		**tab;
	
	tab = ft_strsplit(line, ' ');
	while (tab[*j])
		(*j)++;
	coord = (t_coord*)malloc(sizeof(t_coord) * (*j));
	*j = 0;
	while (tab[*j])
	{
		coord[*j].i = i;
		coord[*j].j = *j;
		coord[*j].z = ft_atoi(tab[*j]);
		(*j)++;
	}
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (coord);
}

void	min_max(t_list_c *head, int j)
{
	t_list_c	*current;
	int			i;
	int			cpt;

	current = head;
	head->max_z = current->coord[0].z;
	head->min_z = current->coord[0].z;
	head->min_x = 0;
	head->max_x = j * 10;
	head->min_y = - 10 * (current->coord[0].z);
	head->max_y = head->min_y;
	i = 0;
	while (current)
	{
		cpt = 0;
		while (cpt < j)
		{
			if (head->max_z < current->coord[cpt].z)
				head->max_z = current->coord[cpt].z;
			if (head->min_z > current->coord[cpt].z)
				head->min_z = current->coord[cpt].z;
			if (head->min_y > i * 10 - 10 * current->coord[cpt].z)
				head->min_y = i * 10 - 10 * current->coord[cpt].z;
			if (head->max_y < i * 10 - 10 * current->coord[cpt].z)
				head->max_y = i * 10 - 10 * current->coord[cpt].z;
			cpt++;
		}
		i++;
		current = current->next;
	}
	head->rows = i;
//	printf("min x = %d, max x = %d, min y = %d, max y = %d\n", head->min_x, head->max_x, head->min_y, head->max_y);
}

t_list_c		*fill_list(t_list_c *head, int fd)
{
	int			i;
	int			j;
	char		*line;
	t_list_c	*new;
	t_coord		*coord;

	i = 0;
	while (get_next_line(fd, &line))
	{
		if(!count_cols(line, 0))
		{
			ft_putstr("Found wrong line length. Exiting.\n");
			exit (-1);
		}
		j = 0;
		coord = fill_coord(coord, line, i, &j);
		free(line);
		if (!head)
			head = ft_listnew(coord, sizeof(t_coord) * (j));
		else
		{
			new = ft_listnew(coord, sizeof(t_coord) * (j));
			ft_listappend(head, new);
		}
		i++;
	}
	head->cols = count_cols(line, 1);
	min_max(head, j);
	return (head);
}

void	init_var(t_list_c *head)
{
	head->multx = (head->win_w - 100.0) / (head->max_x - head->min_x);
	head->multy = (head->win_h - 100.0) / (head->max_y - head->min_y);
	head->zoom = 10.0;
	head->altitude = -1.0;
	head->r = 255 * 256 * 256;
	head->b = 255 * 256;
	head->g = 255;
	head->color = head->r + head->b + head->g;
	head->p = 255 / (head->max_y - head->min_y);
	head->addx = 0;
	head->addy = 0;
}

void	win_size(t_list_c *head)
{
	head->win_h = head->max_y - head->min_y;
	head->win_w = head->max_x - head->min_x;
	if (head->win_w > 1000.0)
		head->win_w = 1000.0;
	else if (head->win_w < 600.0)
		head->win_w = 600.0;
	if (head->win_h > 800.0)
		head->win_h = 800.0;
	else if (head->win_h < 600.0)
		head->win_h = 600.0;
	init_var(head);
}

int		ft_round(double x)
{
	if (x < 0)
		return (x - 0.5);
	return (x + 0.5);
}

void	calc_points(t_list_c *head)
{
	t_list_c	*current;
	int			i;
	int			j;
	int			min;
	double		margin;

	min = ft_round(head->min_y * head->multy);
//	printf("min = %d\n", min);
	margin = (head->win_w - ((head->max_x - head->min_x) * head->multx * (head->zoom / 10))) / 2;
//	margin = 50 - ((head->zoom - 10.0) * head->multx);
//	printf("width = %d\n", head->win_w);
//	printf("margin = %f\n", margin);
	i = 0;
	current = head;
	while (current)
	{
		j = 0;
		while (j < head->cols)
		{
			current->coord[j].x = ft_round(head->multx * head->zoom * j + margin) + head->addx;
			if (min >= 0)
				current->coord[j].y = ft_round(head->multy * (head->altitude * current->coord[j].z + i) * head->zoom + margin) + head->addy;
			else
				current->coord[j].y = ft_round(head->multy * ((head->altitude * current->coord[j].z) + i) * head->zoom + margin) + abs(min) + head->addy;
			current->coord[j].x = (current->coord[j].x + current->coord[j].y) * cos(0.523599);
//			current->coord[j].y = current->coord[j].z + (current->coord[j].x + current->coord[j].y) * sin(0.523599);

//			printf("(%d, %d)\n", current->coord[j].x, current->coord[j].y);
			j++;
		}
//		printf("\n");
		i++;
		current = current->next;
	}
}

void	initialize(t_list_c *head)
{
	head->ptr = mlx_init();
	if (head->ptr == NULL)
	{
		ft_putstr("failed to set up connection to the X server\n");
		exit(-1);
	}
}

void	create_window(t_list_c *head)
{
	head->win = mlx_new_window(head->ptr, head->win_w, head->win_h, "fdf");
	if (head->win == NULL)
	{
		ft_putstr("failed to create a new window\n");
		exit(-1);
	}
}

double		get_percent(int cur_z, int next_z, int min_z, int max_z)
{
	double percent;

	if (max_z == min_z)
		percent = 1.0;
	else if(cur_z > next_z)
		percent = (next_z + cur_z) / 2.0 / (max_z - min_z);
	else if (cur_z < next_z)
		percent = (cur_z + next_z) / 2.0 / (max_z - min_z);
	else
		percent = (double)cur_z / (max_z - min_z);
	return (percent);
}
int		get_color(int cur_z, int next_z, int min_z, int max_z)
{
	int		color;
	double	percent;

	percent = get_percent(cur_z, next_z, min_z, max_z);
	if (percent < 0.1)
		color = 16025993;
	else if (percent < 0.2)
		color = 16097906;
	else if (percent < 0.3)
		color = 16170076;
	else if (percent < 0.4)
		color = 15980904;
	else if (percent < 0.5)
		color = 15857525;
	else if (percent < 0.6)
		color = 11859329;
	else if (percent < 0.7)
		color = 7926926;
	else if (percent < 0.8)
		color = 9762495;
	else if (percent < 0.9)
		color = 11598320;
	else if (percent <= 1.0)
		color = 12517370;
	return (color);
}

void	bresenham(t_list_c *current, t_list_c *head, int i, int n)
{
	int			j;
	t_bresen	elem;

	elem.dx1 = 0;
	elem.dy1 = 0;
	elem.dx2 = 0;
	elem.dy2 = 0;
	elem.x1 = current->coord[i].x;
	elem.y1 = current->coord[i].y;
	if (n == 1)
	{
		elem.x2 = current->coord[i + 1].x;
		elem.y2 = current->coord[i + 1].y;
		head->color = get_color(current->coord[i].z, current->coord[i + 1].z, head->min_z, head->max_z);
	}
	else
	{
		elem.x2 = (current->next)->coord[i].x;
		elem.y2 = (current->next)->coord[i].y;
		head->color = get_color(current->coord[i].z, (current->next)->coord[i].z, head->min_z, head->max_z);
	}
	elem.w = elem.x2 - elem.x1;
	elem.h = elem.y2 - elem.y1;
	if (elem.w < 0)
		elem.dx1 = -1;
	else if (elem.w > 0)
		elem.dx1 = 1;
	if (elem.h < 0)
		elem.dy1 = -1;
	else if (elem.h > 0)
		elem.dy1 = 1;
	if (elem.w < 0)
		elem.dx2 = -1;
	else if (elem.w > 0)
		elem.dx2 = 1;

	elem.longest = abs(elem.w);
	elem.shortest = abs(elem.h);

	if (!(elem.longest>elem.shortest))
	{
		elem.longest = abs(elem.h);
		elem.shortest = abs(elem.w);
		if (elem.h < 0)
			elem.dy2 = -1;
		else if (elem.h > 0)
			elem.dy2 = 1;
		elem.dx2 = 0;
	}
	elem.numerator = elem.longest / 2;
	j = 0;
	while (j <= elem.longest)
	{
		if (elem.x1 > 0 && elem.x1 < head->win_w &&
				elem.y1 > 0 && elem.y1 < head->win_h)
			head->img_str[elem.x1 + head->win_w * elem.y1] = head->color;
		elem.numerator += elem.shortest;
		if (!(elem.numerator < elem.longest))
		{
			elem.numerator -= elem.longest;
			elem.x1 += elem.dx1;
			elem.y1 += elem.dy1;
		}
		else
		{
			elem.x1 += elem.dx2;
			elem.y1 += elem.dy2;
		}
		j++;
	}
}

void	draw(t_list_c *head)
{
	int	i;
	t_list_c	*current;

	current = head;
	while (current)
	{
		i = 0;
		while (i < head->cols)
		{
			if (current->next)
				bresenham(current, head, i, 0);
			if (i != head->cols - 1)
				bresenham(current, head, i, 1);
			i++;
		}
		current = current->next;
	}
}

void	zoom(int key, t_list_c *head)
{
	if (key == MAIN_PLUS || key == PAD_PLUS || key == SCROLL_UP)
		head->zoom += 1;
	else if (key == MAIN_MINUS || key == PAD_MINUS || key == SCROLL_DOWN)
		head->zoom -= 1;
	(head->zoom < 0) ? head->zoom = 0 : head->zoom;
}

void	translation(int key, t_list_c *head)
{
	if (key == LEFT_ARROW)
		head->addx -= 10;
	else if (key == RIGHT_ARROW)
		head->addx += 10;
	else if (key == UP_ARROW)
		head->addy -= 10;
	else if (key == DOWN_ARROW)
		head->addy += 10;
}

void	altitude(int key, t_list_c *head)
{
	if (key == U)
	{
		head->altitude -= 0.1;
		//		head->p = 255 / (head->max_y - head->min_y);
	}
	else if (key == I)
	{
		head->altitude += 0.1;
		//		head->p = 255 / (head->max_y - head->min_y);
	}
}

void	reset(int key, t_list_c *head)
{
	init_var(head);
}

void	quit(int key, t_list_c *head)
{
	exit(0);
}

void	redraw(t_list_c *head)
{
	calc_points(head);
	mlx_destroy_image(head->ptr, head->img);
	head->img = mlx_new_image(head->ptr, head->win_w, head->win_h);
	head->img_str = (int*)mlx_get_data_addr(head->img, &(head->bpp), &(head->s_l), &(head->endian));
	draw(head);
	mlx_put_image_to_window(head->ptr, head->win, head->img, 0, 0);
}

int		key_press(int key, void *param)
{
	t_list_c	*head;

	head = (t_list_c*)param;
	printf("%d\n", key);
	if (key == MAIN_PLUS || key == PAD_PLUS || key == MAIN_MINUS || key == PAD_MINUS)
		zoom(key, head);
	if (key == LEFT_ARROW || key == RIGHT_ARROW || key == UP_ARROW || key == DOWN_ARROW)
		translation(key, head);
	if (key == U || key == I)
		altitude(key, head);
	if (key == SPACE)
		reset(key, head);
	if (key == ESC)
		quit(key, head);
	redraw(head);
	return (0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_list_c	*head;

	head = (t_list_c*)param;
	(void)x;
	(void)y;
	printf("button = %d\n", button);
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		zoom(button, head);
	redraw(head);
	return (0);
}

void	manage_key(t_list_c *head)
{
	mlx_hook(head->win, 2, 0, key_press, head);
	mlx_hook(head->win, 4, 0, mouse_press, head);
}

int		main(int argc, char **argv)
{
	t_list_c	*head;
	int			fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf <file>\n");
		return (0);
	}
	head = NULL;
	fd = open(argv[1], O_RDONLY);
	head = fill_list(head, fd);
	close(fd);
	win_size(head);
	initialize(head);
	create_window(head);
	calc_points(head);
	head->img = mlx_new_image(head->ptr, head->win_w, head->win_h);
	head->img_str = (int*)mlx_get_data_addr(head->img, &(head->bpp), &(head->s_l), &(head->endian));
	draw(head);
	mlx_put_image_to_window(head->ptr, head->win, head->img, 0, 0);
	manage_key(head);
	//	mlx_key_hook(head->win, deal_key, head);
	mlx_loop(head->ptr);
	return (0);
}
