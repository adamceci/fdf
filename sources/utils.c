/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:10:57 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/19 17:52:47 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_list(t_points **head)
{
	t_points	*tmp;

	if (head && *head)
	{
		while (*head)
		{
			tmp = *head;
			*head = (*head)->next;
			free(tmp);
		}
	}
}

void	ft_exit1(const char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}


void	ft_exit2(const char *s, t_points **head, t_fdf *fdf)
{
	free_list(head);
	if (fdf->map)
		free(fdf->map);
	free(fdf);
	ft_putendl_fd(s, 2);
	exit(1);
}

void	ft_exit3(const char *s, t_fdf *fdf)
{
	if (fdf->map)
	{
		if (fdf->map->coords_arr)
			free(fdf->map->coords_arr);
		free(fdf->map);
	}
	if (fdf->camera)
		free(fdf->camera);
	ft_putendl_fd(s, 2);
	exit(1);
}

int		ft_exit4(void *param)
{
	(void)param;
	exit(1);
	return (0);
}
