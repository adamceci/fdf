/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:51:43 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/21 15:48:42 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int			fd;
	t_points	*head;
	t_fdf		*fdf;

	if (argc != 2)
		ft_exit1("usage: ./fdf <file>");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_exit1("open() failed");
	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		ft_exit1("malloc() failed");
	head = NULL;
	read_map(fd, &head, fdf);
	lst_to_array(&head, fdf);
	init_fdf(fdf);
	init_camera(fdf);
	init_mlx(fdf);
	init_mouse(fdf);
	draw(fdf);
	manage_events(fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
