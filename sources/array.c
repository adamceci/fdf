/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:14:02 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/21 15:38:36 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	lst_to_array(t_points **head, t_fdf *fdf)
{
	int	i;
	int min_z;
	int max_z;

	max_z = -2147483648;
	min_z = 2147483647;
	i = fdf->map->nb_cols * fdf->map->nb_lines - 1;
	if (!(fdf->map->coords_arr = (int*)malloc(sizeof(int) * i + 1)))
		ft_exit2("malloc() failed", head, fdf);
	while (*head)
	{
		if ((*head)->z < min_z)
			min_z = (*head)->z;
		if ((*head)->z > max_z)
			max_z = (*head)->z;
		fdf->map->coords_arr[i] = (*head)->z;
		lst_pop(head);
		i--;
	}
	fdf->map->z_min = min_z;
	fdf->map->z_range = abs(max_z - min_z);
}
