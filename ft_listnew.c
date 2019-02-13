/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 16:26:10 by aceciora          #+#    #+#             */
/*   Updated: 2019/02/04 18:44:51 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list_c		*ft_listnew(t_coord *coord, size_t content_size)
{
	t_list_c	*new;

	new = (t_list_c*)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	if (coord == NULL)
	{
		new->coord = NULL;
		new->content_size = 0;
	}
	else
	{
		new->coord = coord;
		ft_memcpy(new->coord, coord, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
