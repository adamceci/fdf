/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 10:57:47 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/18 19:02:53 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf2.h"

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
	init_camera(fdf);
	init_mlx(fdf);

	draw(fdf);
	manage_events(fdf);
	mlx_loop(fdf->mlx_ptr);

	return (0);
}
