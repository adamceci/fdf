/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 16:49:14 by aceciora          #+#    #+#             */
/*   Updated: 2018/07/04 17:27:31 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bubble_sort(int *tab, int size)
{
	int i;
	int j;
	int temp;

	j = 0;
	while (j < size - 1)
	{
		i = 0;
		while (i < size - j - 1)
		{
			if (tab[i + 1] < tab[i])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		j++;
	}
}
