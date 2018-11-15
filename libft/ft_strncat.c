/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:24:35 by aceciora          #+#    #+#             */
/*   Updated: 2018/06/21 14:24:36 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*str;

	str = s1;
	while (*str)
		str++;
	i = 0;
	while (s2[i] && i < n)
	{
		str[i] = s2[i];
		i++;
	}
	str[i] = '\0';
	return (s1);
}
