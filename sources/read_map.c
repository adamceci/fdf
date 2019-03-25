/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:50:56 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/21 15:52:52 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_coord(t_points **head, char *line, t_fdf *fdf)
{
	t_points	*current;
	char		**l_values;
	int			i;

	if (!(l_values = ft_strsplit(line, ' ')))
		ft_exit2("Invalid file", head, fdf);
	i = 0;
	while (l_values[i])
	{
		if (!(current = (t_points*)malloc(sizeof(t_points))))
		{
			free_2d_array(l_values, i);
			ft_exit2("malloc() failed", head, fdf);
		}
		current->z = ft_atoi(l_values[i]);
		lst_push(head, current);
		i++;
	}
	free_2d_array(l_values, i);
	if (fdf->map->nb_lines == 0)
		fdf->map->nb_cols = i;
	if (i != fdf->map->nb_cols)
		ft_exit2("Invalid file", head, fdf);
}

void		read_map(int fd, t_points **head, t_fdf *fdf)
{
	char		*line;
	int			result;

	if (!(fdf->map = (t_map*)malloc(sizeof(t_map))))
		ft_exit2("malloc() failed", head, fdf);
	fdf->map->nb_lines = 0;
	while ((result = get_next_line(fd, &line) == 1))
	{
		fill_coord(head, line, fdf);
		ft_strdel(&line);
		fdf->map->nb_lines++;
	}
	if (result == -1)
		ft_exit2("Invalid file", head, fdf);
}
