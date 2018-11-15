/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 11:18:44 by aceciora          #+#    #+#             */
/*   Updated: 2018/06/28 14:49:32 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	character;
	char			*str;

	character = (unsigned char)c;
	str = (char*)b;
	i = 0;
	while (i < len)
	{
		str[i] = character;
		i++;
	}
	return (b);
}
