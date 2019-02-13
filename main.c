/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:54:25 by aceciora          #+#    #+#             */
/*   Updated: 2019/02/13 16:33:38 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_cols(char *line, t_data *datas)
{
	static int	count = 0;
	int			i;
	char		**tab;
	int			val;

	tab = ft_strsplit(line, ' ');
	i = 0;
	while (tab[i])
		i++;
	if (!count++)
		datas->cols = i;
	if (i != datas->cols)
		val = 0;
	else
		val = 1;
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (val);
}

t_coord	*fill_coord(t_coord *coord, char *line, int i, int *j)
{
	char		**tab;
	/*
	 *	trouver comment calculer x et y
	 *	initialiser des inc_x / inc_y ?
	 *	et un ratio ?
	*/

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

void	min_max(t_data *datas, t_list_c *head, int j)
{
	t_list_c	*current;
	int			i;
	int			cpt;

	current = head;
	datas->min_x = 0;
	datas->max_x = j * 10;
	datas->min_y = -(current->coord[0].z);
	datas->max_y = datas->min_y;
	datas->r_min_y = 0;
	datas->r_max_y = 0;
	i = 0;
	while (current)
	{
		cpt = 0;
		while (cpt < j)
		{
			if (datas->min_y > i * 10 - current->coord[cpt].z)
			{
				datas->min_y = i * 10 - current->coord[cpt].z;
				datas->r_min_y = i;
			}
			if (datas->max_y < i * 10 - current->coord[cpt].z)
			{
				datas->max_y = i * 10 - current->coord[cpt].z;
				datas->r_max_y = i;
			}
			cpt++;
		}
		i++;
		current = current->next;
	}
	datas->rows = i;
}

t_list_c	*fill_list(t_list_c *head, int fd, t_data *datas)
{
	int			i;
	int			j;
	char		*line;
	t_list_c	*new;
	t_coord		*coord;

	i = 0;
	while (get_next_line(fd, &line))
	{
		if(!count_cols(line, datas))
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
	min_max(datas, head, j);
	return (head);
/*
// * Print values of coord
	i = j;
	t_list_c	*current;
	current = head;
	while (current)
	{
		j = 0;
		while (j < i)
		{
			printf("(%d, %d, %d, %d, %d)\n", current->coord[j].i, current->coord[j].j, current->coord[j].x, current->coord[j].y, current->coord[j].z);
			j++;
		}
		current = current->next;
		printf("\n");
	}
//	* Print mins/maxs
	printf("%d, %d, %d, %d\n", datas->min_x, datas->max_x, datas->min_y, datas->max_y);
*/

}

void	win_size(t_data *datas, t_mlx *infos)
{
	infos->win_h = datas->max_y - datas->min_y;
	infos->win_w = datas->max_x - datas->min_x;
	printf("%d, %d\n", infos->win_w, infos->win_h) ;
	if (infos->win_w > 1000.0)
		infos->win_w = 1000.0;
	else if (infos->win_w < 500.0)
		infos->win_w = 500.0;
	if (infos->win_h > 800.0)
		infos->win_h = 800.0;
	else if (infos->win_h < 600.0)
		infos->win_h = 600.0;
	datas->multx = (infos->win_w - 100.0) / (datas->max_x - datas->min_x);
	datas->multy = (infos->win_h - 100.0) / (datas->max_y - datas->min_y);
	printf("%d, %d\n", infos->win_w, infos->win_h) ;
	printf("%f\n", datas->multx);
	printf("%f\n\n", datas->multy);
}

int		ft_round(double x)
{
	if (x < 0)
		return (x - 0.5);
	return (x + 0.5);
}

int		ft_abs(int c)
{
	if (c > 0)
		return (c);
	return (-c);
}

void	calc_points(t_list_c *head, t_data datas)
{
	t_list_c	*current;
	int			i;
	int			j;
	int			min;

	min = ft_round(((datas.r_min_y * 10) + datas.min_y) * datas.multy);
	i = 0;
	current = head;
	while (current)
	{
		j = 0;
		while (j < datas.cols)
		{
			current->coord[j].x = ft_round(datas.multx * (10 * j) + 50);
			if (min > 0)
				current->coord[j].y = ft_round(datas.multy * ((-current->coord[j].z) + (10 * i))) + 50;
			else
				current->coord[j].y = ft_round(datas.multy * ((-current->coord[j].z) + (10 * i))) + 50 + ft_abs(min);
			printf("(%d, %d)\n", current->coord[j].x, current->coord[j].y);
			j++;
		}
		printf("\n");
		i++;
		current = current->next;
	}
}

void	initialize(t_mlx *infos)
{
	infos->ptr = mlx_init();
	if (infos->ptr == NULL)
	{
		ft_putstr("failed to set up connection to the X server\n");
		exit(-1);
	}
}

void	create_window(t_mlx *infos)
{
	infos->win = mlx_new_window(infos->ptr, infos->win_w, infos->win_h, "fdf");
	if (infos->win == NULL)
	{
		ft_putstr("failed to create a new window\n");
		exit(-1);
	}
}

void	bresenham(t_list_c *head, t_mlx infos, int color)
{
	mlx_pixel_put(infos.ptr, infos.win, head->coord[i].x, head->coord[i].y, 0xFFFFFF);
}

void	draw(t_list_c *head, t_data datas, t_mlx infos)
{
	int	i;
	int	color;

	color = 0xFFFFFF;
	while (head)
	{
		i = 0;
		while (i < datas.cols)
		{
			bresenham(head, infos, color);
			i++;
		}
		head = head->next;
	}
}

int		main(int argc, char **argv)
{
	t_list_c	*head;
	t_data		datas;
	t_mlx		infos;
	int			fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf <file>\n");
		return (0);
	}
	head = NULL;
	fd = open(argv[1], O_RDONLY);
	head = fill_list(head, fd, &datas);
	close(fd);
	win_size(&datas, &infos);
	calc_points(head, datas);
	initialize(&infos);
	create_window(&infos);
	draw(head, datas, infos);
	mlx_loop(infos.ptr);
	return (0);
}
