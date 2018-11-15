/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:49:59 by aceciora          #+#    #+#             */
/*   Updated: 2018/07/04 14:50:19 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*first_elem;
	t_list	*temp;

	if (lst && f)
	{
		temp = f(lst);
		new_lst = ft_lstnew(temp->content, temp->content_size);
		if (!new_lst)
			return (NULL);
		first_elem = new_lst;
		lst = lst->next;
		while (lst != NULL)
		{
			temp = f(lst);
			new_lst->next = ft_lstnew(temp->content, temp->content_size);
			if (!(new_lst->next))
				return (NULL);
			new_lst = new_lst->next;
			lst = lst->next;
		}
		return (first_elem);
	}
	return (NULL);
}
