/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:20:23 by aceciora          #+#    #+#             */
/*   Updated: 2018/07/01 13:54:10 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_words(char const *s, char c)
{
	unsigned int	nb_words;

	nb_words = 0;
	while (*s)
	{
		if ((*s != c && *(s + 1) == c) || (*s != c && *(s + 1) == '\0'))
			nb_words++;
		s++;
	}
	return (nb_words);
}

static unsigned int	ft_count_letters(char const *s, char c)
{
	unsigned int	nb_letters;

	nb_letters = 0;
	while (*s && *s != c)
	{
		nb_letters++;
		s++;
	}
	return (nb_letters);
}

static char			*ft_fill_tab(char *tab, char const **s, char c,
								unsigned int nb_letters)
{
	unsigned int	i;

	while (**s && **s != c)
	{
		tab = (char*)malloc(sizeof(tab) * (nb_letters + 1));
		if (!tab)
			return (NULL);
		i = 0;
		while (i < nb_letters)
		{
			tab[i] = **s;
			(*s)++;
			i++;
		}
		tab[i] = '\0';
	}
	return (tab);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	nb_words;
	unsigned int	nb_letters;

	if (s)
	{
		nb_words = ft_count_words(s, c);
		tab = (char**)malloc(sizeof(*tab) * (nb_words + 1));
		if (!tab)
			return (NULL);
		i = 0;
		while (i < nb_words)
		{
			while (*s && *s == c)
				s++;
			nb_letters = ft_count_letters(s, c);
			if (*s)
				tab[i] = ft_fill_tab(tab[i], &s, c, nb_letters);
			i++;
		}
		tab[i] = NULL;
		return (tab);
	}
	return (NULL);
}
