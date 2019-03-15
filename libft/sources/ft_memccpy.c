/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 13:28:50 by aceciora          #+#    #+#             */
/*   Updated: 2018/06/25 15:00:07 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char*)src;
	s2 = (unsigned char*)dst;
	i = 0;
	while (i < n && *s1 != (unsigned char)c)
	{
		*s2++ = *s1++;
		i++;
	}
	if (i < n)
	{
		*s2++ = *s1++;
		return ((void*)s2);
	}
	return (NULL);
}
