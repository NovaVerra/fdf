/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 15:00:20 by llee              #+#    #+#             */
/*   Updated: 2019/01/16 15:00:26 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		clerp(int c1, int c2, double p)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = ft_lerpi((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = ft_lerpi((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = ft_lerpi(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}

void	message(t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 50, 0xFFFFFF,
	"- LEFT CLICK + DRAG = rotate and inspect");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 75, 0xFFFFFF,
	"- SCROLLWHEEL = zoom in/out");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 100, 0xFFFFFF,
	"- UP/DOWN ARROW = shift up/down");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 125, 0xFFFFFF,
	"- LEFT/RIGHT ARROW = shift left/right");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 150, 0xFFFFFF,
	"- NUMBER ROW 1~6 = color change (rainbow)");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 175, 0xFFFFFF,
	"- ADD/SUBTRACT ON NUMPAD = zoom in/out");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 200, 0xFFFFFF,
	"- R = reset");
	message_2(mlx);
}

void	message_2(t_mlx *mlx)
{
	int	i;

	i = 34;
	while (++i < 235)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, 35, i, 0xFFFFFF);
	i = 34;
	while (++i < 500)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, i, 35, 0xFFFFFF);
	i = 34;
	while (++i < 235)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, 500, i, 0xFFFFFF);
	i = 34;
	while (++i < 500)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, i, 235, 0xFFFFFF);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 1810, 1030, 0xFFFFFF, "by llee");
}
