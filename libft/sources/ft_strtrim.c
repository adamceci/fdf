/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 11:45:58 by aceciora          #+#    #+#             */
/*   Updated: 2018/06/27 12:00:19 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	start;
	unsigned int	end;

	if (s)
	{
		start = 0;
		while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
			start++;
		if (s[start] == '\0')
			return (ft_strnew(0));
		end = ft_strlen(s) - 1;
		while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
			end--;
		str = ft_strsub((char const*)s, start, end - start + 1);
		return (str);
	}
	return (NULL);
}
