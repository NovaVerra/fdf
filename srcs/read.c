/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:15:58 by llee              #+#    #+#             */
/*   Updated: 2019/01/15 12:16:04 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		copy_argv(t_file **file, char *path)
{
	if (!((*file)->path = ft_strnew(ft_strlen(path))))
		return (-1);
	ft_strcpy((*file)->path, path);
	return (0);
}

int		get_row_col(t_file **file, t_map **map)
{
	int	i;

	open_file(file);
	read_whole_file(file);
	i = -1;
	while ((*file)->buf[++i])
		if ((*file)->buf[i] == '\n')
			(*map)->height++;
	clean_buf(*file);
	close_file(file);
	open_file(file);
	get_next_line((*file)->fd, &(*file)->buf);
	(*file)->cmap = ft_strsplit((*file)->buf, ' ');
	i = -1;
	while ((*file)->cmap[++i])
		(*map)->width = i + 1;
	clean_buf(*file);
	close_file(file);
	return (0);
}

int		read_whole_file(t_file **file)
{
	(*file)->buf = ft_strnew(BUFF_SIZE);
	if (!((*file)->retval = read((*file)->fd, (*file)->buf, BUFF_SIZE)))
		return (-1);
	(*file)->buf[(*file)->retval] = '\0';
	return (0);
}

int		open_file(t_file **file)
{
	if (((*file)->fd = open((*file)->path, O_RDONLY)) == -1)
		return (-1);
	return (0);
}

int		close_file(t_file **file)
{
	if (!(close((*file)->fd)))
		return (-1);
	return (0);
}
