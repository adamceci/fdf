/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:49:36 by aceciora          #+#    #+#             */
/*   Updated: 2018/07/04 14:49:37 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list *lst, t_list *new)
{
	t_list	*current;

	if (lst && new)
	{
		current = lst;
		while (current->next)
			current = current->next;
		current->next = new;
		new->next = NULL;
	}
}
