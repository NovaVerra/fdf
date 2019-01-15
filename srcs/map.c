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
	return (0);
}

int		copy_to_map(t_file **file, t_map **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (*map)->width)
		(*map)->imap[0][i] = ft_atoi((*file)->cmap[i]);
	clean_cmap(*file);
	open_file(file);
	i = 1;
	while (i < (*map)->height)
	{
		get_next_line((*file)->fd, &(*file)->buf);
		(*file)->cmap = ft_strsplit((*file)->buf, ' ');
		j = 0;
		while (j < (*map)->width)
		{
			(*map)->imap[i][j] = ft_atoi((*file)->cmap[j]);
			j++;
		}
		i++;
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