/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 16:56:58 by llee              #+#    #+#             */
/*   Updated: 2019/01/17 16:57:08 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom_in(t_mlx *mlx)
{
	mlx->cam->scale += 8;
	render(mlx);
}

void	zoom_out(t_mlx *mlx)
{
	mlx->cam->scale -= 8;
	render(mlx);
}
int		hook_keydown(int keycode, t_mlx *mlx)
{
	(void)mlx;
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
		zoom_in(mlx);
	if (keycode == 78)
		zoom_out(mlx);
	return (0);
}

int		hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	if (y < 0)
		return (0);
	mlx->mouse->isdown |= 1 << button;
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse->isdown &= ~(1 << button);
	return (0);
}

int		hook_mousemove(int x, int y, t_mlx *mlx)
{
	mlx->mouse->prev_x = mlx->mouse->x;
	mlx->mouse->prev_y = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->isdown & (1 << 1) && mlx->mouse->isdown & (1 << 2))
	{
		mlx->cam->offset_x += (x - mlx->mouse->prev_x);
		mlx->cam->offset_y += (y - mlx->mouse->prev_y);
	}
	else if (mlx->mouse->isdown & (1 << 1))
	{
		mlx->cam->x += (mlx->mouse->prev_y - y) / 200.0f;
		mlx->cam->y -= (mlx->mouse->prev_x - x) / 200.0f;
	}
	else if (mlx->mouse->isdown & (1 << 2))
	{
		mlx->cam->scale += (mlx->mouse->prev_y - y) / 10.0f + 0.5f;
		if (mlx->cam->scale < 1)
			mlx->cam->scale = 1;
	}
	if (mlx->mouse->isdown)
		render(mlx);
	return (0);
}
