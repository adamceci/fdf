/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:02:43 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/12 15:54:35 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf2.h"

void	lst_push(t_points **head, t_points *current)
{
	if (head)
	{
		if (current)
			current->next = *head;
		*head = current;
	}
}

void	lst_pop(t_points **head)
{
	t_points	*tmp;

	tmp = *head;
	if (head && *head)
	{
		*head = (*head)->next;
		free(tmp);
	}
}
