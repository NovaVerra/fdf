/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 15:47:11 by llee              #+#    #+#             */
/*   Updated: 2019/01/15 15:47:17 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		render(t_mlx *mlx)
{
	int			x;
	int			y;
	t_vect		translate;
	t_map		*map;

	map = mlx->map;
	clear_image(mlx->image);
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			translate = project_vector(vector_at(map, x, y), mlx);
			if (x + 1 < map->width)
				line(mlx, translate, project_vector(vector_at(map, x + 1, y), mlx));
			if (y + 1 < map->height)
				line(mlx, translate, project_vector(vector_at(map, x, y + 1), mlx));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->img, 0, 0);
}
