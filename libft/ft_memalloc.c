/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 15:00:01 by aceciora          #+#    #+#             */
/*   Updated: 2018/06/27 10:39:16 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*memory;

	memory = malloc(sizeof(*memory) * size);
	if (memory)
		return (ft_memset(memory, 0, size));
	return (NULL);
}
