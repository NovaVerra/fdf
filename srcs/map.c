/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:26:34 by llee              #+#    #+#             */
/*   Updated: 2019/01/15 12:26:41 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		make_map(t_map **map)
{
	int	i;

	if (!((*map)->imap = (int **)malloc(sizeof(int *) * ((*map)->height))))
		return (-1);
	i = -1;
	while (++i < (*map)->height)
		if (!((*map)->imap[i] = (int *)malloc(sizeof(int) * ((*map)->width))))
			return (-1);
	(*map)->c_max = 0xFFFFFF;
	(*map)->c_min = 0xFF00FF;
	return (0);
}

int		copy_to_map(t_file **file, t_map **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (*map)->width)
	{
		copy_to_map_2(file, map, i);
	}
	free((*file)->cmap);
	open_file(file);
	i = 0;
	while (++i < (*map)->height)
	{
		get_next_line((*file)->fd, &(*file)->buf);
		(*file)->cmap = ft_strsplit((*file)->buf, ' ');
		free((*file)->buf);
		j = -1;
		while (++j < (*map)->width)
		{
			(*map)->imap[i][j] = ft_atoi((*file)->cmap[j]);
			free((*file)->cmap[j]);
		}
		free((*file)->cmap);
	}
	return (close_file(file));
}

void	find_min_max(t_map **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*map)->height)
	{
		j = 0;
		while (j < (*map)->width)
		{
			if ((*map)->imap[i][j] > (*map)->z_max)
				(*map)->z_max = (*map)->imap[i][j];
			if ((*map)->imap[i][j] < (*map)->z_min)
				(*map)->z_min = (*map)->imap[i][j];
			j++;
		}
		i++;
	}
}

t_vect	transform(int x, int y, t_map *map)
{
	t_vect	vect;

	vect.x = x;
	vect.y = y;
	vect.z = map->imap[y][x];
	vect.color = clerp(map->c_min, map->c_max, ft_ilerp(vect.z,
				map->z_min, map->z_max));
	return (vect);
}

void	set_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	*(int *)(image->ptr + ((x + y * WIN_WIDTH) * image->bpp)) = color;
}
