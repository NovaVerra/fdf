/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:12:31 by llee              #+#    #+#             */
/*   Updated: 2019/01/15 12:12:40 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_file	*init_file(void)
{
	t_file	*file;

	if ((file = ft_memalloc(sizeof(t_file))) == NULL)
		return (NULL);
	return (file);
}

t_map	*init_map(void)
{
	t_map	*map;

	if ((map = ft_memalloc(sizeof(t_map))) == NULL)
		return (NULL);
	return (map);
}

t_image	*init_image(t_mlx *mlx)
{
	t_image		*image;

	if (!(image = ft_memalloc(sizeof(t_image))))
		return (NULL);
	if (!(image->img = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		return (clean_image(mlx, image));
	image->ptr = mlx_get_data_addr(image->img, &image->bpp, &image->line,
			&image->endian);
	image->bpp /= 8;
	return (image);
}

t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx_ptr = mlx_init()) ||
		!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
		WIN_WIDTH, WIN_HEIGHT, "llee's FdF")) ||
		!(mlx->cam = ft_memalloc(sizeof(t_cam))) ||
		!(mlx->mouse = ft_memalloc(sizeof(t_mouse))) ||
		!(mlx->image = init_image(mlx)))
		return (clean_mlx(mlx));
	mlx->cam->x = 0.5;
	mlx->cam->y = 0.5;
	mlx->cam->scale = 32;
	mlx->cam->offset_x = WIN_WIDTH / 2;
	mlx->cam->offset_y = WIN_HEIGHT / 2;
	return (mlx);
}

t_vect	*init_vect(void)
{
	t_vect	*vector;

	if (!(vector = ft_memalloc(sizeof(t_vect))))
		return (NULL);
	return (vector);
}
