/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 15:18:10 by aceciora          #+#    #+#             */
/*   Updated: 2018/07/01 13:44:05 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;

	s1 = (char*)src;
	s2 = (char*)dst;
	if (s1 < s2)
	{
		s1 = s1 + len - 1;
		s2 = s2 + len - 1;
		while (len > 0)
		{
			*s2-- = *s1--;
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
