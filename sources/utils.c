/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:10:57 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/14 18:33:27 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf2.h"

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

void	ft_exit_and_free(const char *s, t_points **head)
{
	free_list(head);
	ft_putendl_fd(s, 2);
	exit(1);
}

void	ft_exit(const char *s)
{
	ft_putendl_fd(s, 2);
	exit(1);
}

