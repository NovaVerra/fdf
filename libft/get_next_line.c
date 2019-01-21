/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:05:05 by llee              #+#    #+#             */
/*   Updated: 2018/12/14 13:26:00 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	read_next_line(const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	int		retval;

	if ((retval = read(fd, buf, BUFF_SIZE)) < 0)
		return (-1);
	buf[retval] = '\0';
	NULL_CHECK((temp = ft_strjoin(*line, buf)));
	free(*line);
	*line = temp;
	return (retval);
}

int	get_next_line(const int fd, char **line)
{
	static char *temp = NULL;
	int			retval;
	char		*offset;

	if (!temp && (temp = (char *)ft_memalloc(sizeof(char))) == NULL)
		return (-1);
	offset = ft_strchr(temp, '\n');
	while (offset == NULL)
	{
		retval = read_next_line(fd, &temp);
		if (retval == 0)
		{
			if ((offset = ft_strchr(temp, '\0')) == temp)
				return (0);
		}
		else if (retval < 0)
			return (-1);
		else
			offset = ft_strchr(temp, '\n');
	}
	NULL_CHECK((*line = ft_strsub(temp, 0, offset - temp)));
	offset = ft_strdup(offset + 1);
	free(temp);
	temp = offset;
	return (1);
}
