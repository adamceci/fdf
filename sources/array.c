/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:14:02 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/15 16:12:12 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf2.h"

void	lst_to_array(t_points **head, t_map *map)
{
	int	i;

	i = map->nb_cols * map->nb_lines - 1;
	map->coords_arr = (int*)malloc(sizeof(int) * i + 1);
	while (*head)
	{
		map->coords_arr[i] = (*head)->z;
		lst_pop(head);
		i--;
	}
}
