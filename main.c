/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:03:27 by aceciora          #+#    #+#             */
/*   Updated: 2019/02/21 17:48:50 by aceciora         ###   ########.fr       */
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
	printf("min x = %d, max x = %d, min y = %d, max y = %d\n", head->min_x, head->max_x, head->min_y, head->max_y);
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
	head->altitude = -10;
	head->zoom = 100.0;
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

/*
int		ft_abs(int c)
{
	if (c > 0)
		return (c);
	return (-c);
}
*/

void	calc_points(t_list_c *head)
{
	t_list_c	*current;
	int			i;
	int			j;
	int			min;

	min = ft_round(head->min_y * head->multy);
//	printf("min = %d\n", min);
	head->multx = (head->win_w - head->zoom) / (head->max_x - head->min_x);
	head->multy = (head->win_h - head->zoom) / (head->max_y - head->min_y);
	i = 0;
	current = head;
	while (current)
	{
		j = 0;
		while (j < head->cols)
		{
			current->coord[j].x = ft_round(head->multx * (10 * j) + (head->zoom / 2)) + head->addx; /* + head->multx * 0 * i + addx*/
//			current->coord[j].x = ft_round(datas.multx * 10 * j * i + 50);	conique
			if (min > 0)
				current->coord[j].y = ft_round(head->multy * ((head->altitude * current->coord[j].z) + (10 * i)) + (head->zoom / 2)) - head->addy;
			else
				current->coord[j].y = ft_round(head->multy * ((head->altitude * current->coord[j].z) + (10 * i)) + (head->zoom / 2)) + abs(min) - head->addy;
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

void	bresenham(t_list_c *current, t_list_c *head, int i, int n)
{
	int			j;
	t_bresen	elem;
	int			color;

	color = 0xFFFFFF;	//RED
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
	}
	else
	{
		elem.x2 = (current->next)->coord[i].x;
		elem.y2 = (current->next)->coord[i].y;
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
		if (elem.dy1 == 1 && current->coord[i].z > current->next->coord[i].z)
			color += 100 * 256 * 256;
		else if (elem.dy1 == -1 && current->coord[i].z < current->next->coord[i].z)
			color -= 100 * 256 * 256;
		if (elem.dx1 == 1 && current->coord[i].z >= current->coord[i + 1].z)
			color += 100 * 256 * 256;
		else if (elem.dx1 == -1 && current->coord[i].z <= current->coord[i + 1].z)
			color -= 100 * 256 * 256;

		if (elem.x1 > 0 && elem.x1 < head->win_w &&
				elem.y1 > 0 && elem.y1 < head->win_h)
			head->img_str[elem.x1 + head->win_w * elem.y1] = color;
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
	if (key == 69)
		head->zoom -= 10;
	else if (key == 78)
		head->zoom += 10;
}

void	translation(int key, t_list_c *head)
{
	if (key == 0)
		head->addx -= 10;
	else if (key == 1)
		head->addy -= 10;
	else if (key == 2)
		head->addx += 10;
	else if (key == 13)
		head->addy += 10;
}

void	altitude(int key, t_list_c *head)
{
	if (key == 32)
		head->altitude -= 1;
	else if (key == 34)
		head->altitude += 1;
}

void	reset(int key, t_list_c *head)
{
	if (key == 49)
		init_var(head);
}

void	quit(int key, t_list_c *head)
{
	if (key == 53)
		exit(0);
}

int		deal_key(int key, t_list_c *head)
{
	printf("%d\n", key);
	zoom(key, head);
	translation(key, head);
	altitude(key, head);
	reset(key, head);
	quit(key, head);
	calc_points(head);
	mlx_destroy_image(head->ptr, head->img);
	head->img = mlx_new_image(head->ptr, head->win_w, head->win_h);
	head->img_str = (int*)mlx_get_data_addr(head->img, &(head->bpp), &(head->s_l), &(head->endian));
	draw(head);
	mlx_put_image_to_window(head->ptr, head->win, head->img, 0, 0);
	return (0);
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
	mlx_key_hook(head->win, deal_key, head);	
	mlx_loop(head->ptr);
	return (0);
}
