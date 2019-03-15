/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 10:45:56 by aceciora          #+#    #+#             */
/*   Updated: 2018/06/27 10:47:00 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (s)
	{
		str = ft_strnew(len);
		if (str == NULL)
			return (NULL);
		s = s + start;
		i = 0;
		while (i < len)
		{
			str[i] = s[i];
			i++;
		}
		return (str);
	}
	return (NULL);
}
