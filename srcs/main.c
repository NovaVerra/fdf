/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:59:58 by llee              #+#    #+#             */
/*   Updated: 2019/01/15 11:00:08 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	t_file	*file;
	t_map	*map;
	t_mlx	*mlx;

	if (argc > 1)
	{
		setup_map(&file, &map, argv[1]);
		setup_mlx(&map, &mlx);
	}
	else
		perror("usage: ./fdf [input height map]\n");
	return (0);
}

void	setup_map(t_file **file, t_map **map, char *path)
{
	*file = init_file();
	*map = init_map();
	copy_argv(file, path);
	get_row_col(file, map);
	make_map(map);
	copy_to_map(file, map);
	find_min_max(map);
	clean_file(*file);
	print_map(map);
}

void	setup_mlx(t_map **map, t_mlx **mlx)
{
	*mlx = init_mlx();
	(*mlx)->map = (*map);
	render(*mlx);
}

void	print_map(t_map **map)
{
	int i;
	int j;

	i = 0;
	while (i < (*map)->height)
	{
		j = 0;
		while (j < (*map)->width)
		{
			printf("%d ", (*map)->imap[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
