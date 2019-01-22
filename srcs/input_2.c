/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:15:15 by llee              #+#    #+#             */
/*   Updated: 2019/01/21 15:15:21 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(t_mlx *mlx, int key)
{
	if (key == 69 || key == 4)
		mlx->cam->scale += 2;
	if (key == 78 || key == 5)
		mlx->cam->scale -= 2;
	render(mlx);
}

void	shift(t_mlx *mlx, int key)
{
	if (key == 126)
		mlx->cam->offset_y -= 8;
	if (key == 125)
		mlx->cam->offset_y += 8;
	if (key == 123)
		mlx->cam->offset_x -= 8;
	if (key == 124)
		mlx->cam->offset_x += 8;
	render(mlx);
}

void	color(t_mlx *mlx, int key)
{
	if (key == 18)
		mlx->map->c_min = 0xFF0000;
	if (key == 19)
		mlx->map->c_min = 0xFF7F00;
	if (key == 20)
		mlx->map->c_min = 0xFFFF00;
	if (key == 21)
		mlx->map->c_min = 0x00FF00;
	if (key == 22)
		mlx->map->c_min = 0x4B0082;
	if (key == 23)
		mlx->map->c_min = 0x0000FF;
	if (key == 26)
		mlx->map->c_min = 0x9400D3;
	render(mlx);
}

void	reset(t_mlx *mlx)
{
	mlx->cam->x = 0.0;
	mlx->cam->y = 0.0;
	mlx->cam->scale = 32;
	mlx->cam->offset_x = WIN_WIDTH / 2;
	mlx->cam->offset_y = WIN_HEIGHT / 2;
	mlx->map->c_min = 0xFF00FF;
	render(mlx);
}
