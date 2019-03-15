/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aceciora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 10:57:47 by aceciora          #+#    #+#             */
/*   Updated: 2019/03/15 16:36:06 by aceciora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf2.h"
#include "mlx.h"

void	print_lst(t_points *head)
{
	while (head)
	{
		printf("%d\n", head->z);
		head = head->next;
	}
	printf("\n\n");
}

void	print_arr(t_map map)
{
	int	i;

	i = 0;
	while (i < map.nb_cols * map.nb_lines)
	{
		printf("(%d)\n", map.coords_arr[i]);
		i++;
	}
}


int	main(int argc, char **argv)
{
	int			fd;
	t_points	*head;
	t_fdf		*fdf;

	if (argc != 2)
		ft_exit("usage: ./fdf <file>");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_exit("open() failed");
	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		ft_exit("malloc() failed");
	head = NULL;
	fdf->map = read_map(fd, &head);
//	print_lst(head);
	lst_to_array(&head, fdf->map);
//	print_arr(*(fdf->map));
	fdf->camera = init_camera(fdf);
	init_mlx(fdf);

	draw(fdf);
	mlx_loop(fdf->mlx_ptr);

	return (0);
}
