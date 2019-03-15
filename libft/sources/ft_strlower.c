/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 15:56:35 by aceciora          #+#    #+#             */
/*   Updated: 2018/07/04 16:03:59 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strlower(char *str)
{
	unsigned int	i;
	char			*s;

	s = NULL;
	if (str)
	{
		s = ft_strnew(ft_strlen(str));
		if (!s)
			return (NULL);
		i = 0;
		while (str[i])
		{
			s[i] = ft_tolower(str[i]);
			i++;
		}
	}
	return (s);
}
