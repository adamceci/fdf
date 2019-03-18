/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:14:02 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/18 17:55:16 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf2.h"

void	lst_to_array(t_points **head, t_fdf *fdf)
{
	int	i;

	i = fdf->map->nb_cols * fdf->map->nb_lines - 1;
	if (!(fdf->map->coords_arr = (int*)malloc(sizeof(int) * i + 1)))
		ft_exit2("malloc() failed", head, fdf);
	while (*head)
	{
		fdf->map->coords_arr[i] = (*head)->z;
		lst_pop(head);
		i--;
	}
}
