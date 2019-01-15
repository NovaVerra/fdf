/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:32:50 by llee              #+#    #+#             */
/*   Updated: 2019/01/15 12:33:00 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_file	*clean_buf(t_file *file)
{
	if (file->buf != NULL)
		ft_memdel((void **)&file->buf);
	return (file);
}

t_file	*clean_cmap(t_file *file)
{
	if (file->cmap != NULL)
		ft_memdel((void **)&file->cmap);
	return (file);
}

t_file	*clean_file(t_file *file)
{
	ft_memdel((void **)&file);
	return (NULL);
}
