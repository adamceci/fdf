/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:50:56 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/15 16:36:09 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf2.h"

static void	fill_coord(t_points **head, char *line, t_map *map)
{
	t_points	*current;
	char	**l_values;
	int		i;

	if(!(l_values = ft_strsplit(line, ' ')))
		ft_exit_and_free("Invalid file", head);
	i = 0;
	while(l_values[i])
	{
		if (!(current = (t_points*)malloc(sizeof(t_points))))
			ft_exit_and_free("malloc() failed", head);
//		current->x = i;
//		current->y = map->nb_lines;
		current->z = ft_atoi(l_values[i]);
		lst_push(head, current);
		i++;
	}
	free_2d_array(l_values, i);
	if (map->nb_lines == 0)
		map->nb_cols = i;
	if (i != map->nb_cols)
		ft_exit("Invalid file");
}

t_map		*read_map(int fd, t_points **head)
{
	t_map		*map;
	char		*line;
	int			result;

	if(!(map = (t_map*)malloc(sizeof(*map))))
		ft_exit("malloc() failed");
	map->nb_lines = 0;
	while ((result = get_next_line(fd, &line) == 1))
	{
		fill_coord(head, line, map);
		ft_strdel(&line);
		map->nb_lines++;
	}
	if (result == -1)
		ft_exit_and_free("Invalid file", head);
	return (map);
}
