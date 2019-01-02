/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:16:26 by aceciora          #+#    #+#             */
/*   Updated: 2019/01/02 16:53:23 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

static void	fill_coord(t_list_coord **list, t_map_datas *datas, int i, int j)
{
	datas->ratio_x = 0.0;
	datas->ratio_y = -1.0;
	datas->inc_x = 10;
	datas->inc_y = 10;
	(*list)->coord[j].x = j * datas->inc_x + datas->tab_value * datas->ratio_x; //calculer ratio;
	(*list)->coord[j].y = i * datas->inc_y + datas->tab_value * datas->ratio_y; //calculer ratio;
	(*list)->coord[j].z = datas->tab_value;
	(*list)->coord[j].i = i;
	(*list)->coord[j].j = j;

//	printf("(%d, %d)\n", (*list)->coord[j].x, (*list)->coord[j].y);
}

static void	find_min_max(t_map_datas *datas, t_list_coord **list, int j)
{
	static int		init = 0;

	if (!init++)
	{
		datas->min_x = (*list)->coord[j].x;
		datas->max_x = (*list)->coord[j].x;
		datas->min_y = (*list)->coord[j].y;
		datas->max_y = (*list)->coord[j].y;
	}
	if (datas->min_x > (*list)->coord[j].x)
		datas->min_x = (*list)->coord[j].x;
	else if (datas->max_x < (*list)->coord[j].x)
		datas->max_x = (*list)->coord[j].x;
	if (datas->min_y > (*list)->coord[j].y)
		datas->min_y = (*list)->coord[j].y;
	else if (datas->max_y < (*list)->coord[j].y)
		datas->max_y = (*list)->coord[j].y;
}

static void	fill_list_coord(char *line, int row, t_list_coord *list,
		t_map_datas *datas)
{
	char			**tab_split;
	int				*tab;
	int				j;
	static int		cpt = 0;

	tab_split = ft_strsplit(line, ' '); // --> free + proteger malloc
	j = 0;
	while (tab_split[j])
		j++;
	if (!(tab = (int*)malloc(sizeof(*tab) * j)))
		exit(-1); // --> look for perror strerror
	if (!((list)->coord = (t_coord*)malloc(sizeof(t_coord) * j)))
		exit(-1);
	if (!cpt++)
		datas->tot_cols = j;
	j = 0;
	while (tab_split[j])
	{
		tab[j] = ft_atoi(tab_split[j]);
		datas->tab_value = tab[j];
		free(tab_split[j]);
		fill_coord(&list, datas, row, j);
		find_min_max(datas, &list, j);
		j++;
	}
	//	printf("min : %d, max : %d\n", datas->min_y, datas->max_y);
	free(tab_split);
	free(tab);
}

static void	read_map(char *file, t_list_coord **list, t_map_datas *datas)
{
	t_list_coord	*current;
	int				fd;
	int				row;
	char			*line;
	int				gnl;

	if (!(*list = (t_list_coord*)malloc(sizeof(**list))))
		exit(-1);
	current = *list;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit (-1);
	row = 0;
	gnl = 0;
	while ((gnl = get_next_line(fd, &line)))
	{
		if (gnl < 0)
			exit(-1);
		fill_list_coord(line, row, current, datas);
		free(line);
		if (!(current->next = (t_list_coord*)malloc(sizeof(**list))))
			exit(-1);
		current = current->next;
		row++;
	}
	current = NULL;
	datas->tot_rows = row;
}

int			main(int argc, char **argv)
{
	t_list_coord	*list;
	t_map_datas		*datas;
	t_mlx_infos		*infos;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf file\n");
		return (0);
	}
	list = NULL;
	if (!(datas = (t_map_datas*)malloc(sizeof(*datas))))
		exit(-1);
	if (argc == 2)
		read_map(argv[1], &list, datas);
	if (!(infos = (t_mlx_infos*)malloc(sizeof(*infos))))
		exit(-1);
	get_win_size(infos, datas);
	initialize(infos);
	create_window(infos);
	modif_coord(list, datas);
	draw(list, datas, infos);
	mlx_loop(infos->ptr);
	//	if (!(infos->img = mlx_new_image(infos->ptr, 2000, 1000)))
	//		exit(-1);
	//	infos->img_str = (int*)mlx_get_data_addr(infos->img, &(infos->bpp), &(infos->s_l), &(infos->endian));
	return (0);
}
