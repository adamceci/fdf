/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 16:29:34 by aceciora          #+#    #+#             */
/*   Updated: 2019/02/03 16:31:40 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_listappend(t_list_c *lst, t_list_c *new)
{
	t_list_c	*current;

	if (lst && new)
	{
		current = lst;
		while (current->next)
			current = current->next;
		current->next = new;
		new->next = NULL;
	}
}
