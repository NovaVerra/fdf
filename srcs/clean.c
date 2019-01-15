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

t_mlx	*clean_mlx(t_mlx *mlx)
{
	if (mlx->win_ptr != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->cam != NULL)
		ft_memdel((void **)&mlx->cam);
	if (mlx->mouse != NULL)
		ft_memdel((void **)&mlx->mouse);
	if (mlx->image != NULL)
		clean_image(mlx, mlx->image);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_image	*clean_image(t_mlx *mlx, t_image *image)
{
	if (image != NULL)
	{
		if (image->img != NULL)
			mlx_destroy_image(mlx->mlx_ptr, image->img);
		ft_memdel((void **)&image);
	}
	return (NULL);
}
