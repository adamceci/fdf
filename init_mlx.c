/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:42:44 by aceciora          #+#    #+#             */
/*   Updated: 2018/12/12 13:09:17 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*initialize(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
		ft_putstr("failed to set up connection to the X server\n");
		return (NULL);
	}
	return (mlx_ptr);
}

void	*create_window(void *mlx_ptr)
{
	void	*mlx_window;

	mlx_window = mlx_new_window(mlx_ptr, 2000, 1000, "fdf");
	if (mlx_window == NULL)
	{
		ft_putstr("failed to create a new window\n");
		return (NULL);
	}
	return (mlx_window);
}
