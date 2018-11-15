/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 15:52:56 by aceciora          #+#    #+#             */
/*   Updated: 2018/07/04 16:02:00 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strupper(char *str)
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
			s[i] = ft_toupper(str[i]);
			i++;
		}
	}
	return (s);
}
