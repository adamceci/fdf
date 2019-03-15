/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:30:14 by aceciora          #+#    #+#             */
/*   Updated: 2018/12/11 15:36:00 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_2d_array(char **array, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (size-- > 0)
		free(array[size]);
	free(array);
}
