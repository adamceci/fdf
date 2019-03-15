/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:49:46 by aceciora          #+#    #+#             */
/*   Updated: 2018/07/04 14:49:47 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*current;

	if (alst == NULL)
		return ;
	current = *alst;
	while (current != NULL)
	{
		temp = current->next;
		ft_lstdelone(&current, del);
		current = temp;
	}
	*alst = NULL;
}
