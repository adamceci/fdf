/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 15:04:32 by aceciora          #+#    #+#             */
/*   Updated: 2018/06/25 15:04:33 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	position;

	position = ft_strlen(s);
	while (position >= 0)
	{
		if (s[position] == (char)c)
			return ((char*)&s[position]);
		position--;
	}
	return (NULL);
}
