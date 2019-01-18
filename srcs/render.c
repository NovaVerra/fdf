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

void	render(t_mlx *mlx)
{
	int			x;
	int			y;
	t_vect		cur_vect;
	t_map		*map;

	map = mlx->map;
	reset_image(mlx->image);
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			cur_vect = print_to_screen(transform(x, y, map), mlx);
			if (x + 1 < map->width)
				line(mlx, cur_vect, print_to_screen(transform(x + 1, y, map), mlx));
			if (y + 1 < map->height)
				line(mlx, cur_vect, print_to_screen(transform(x, y + 1, map), mlx));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->image->img, 0, 0);
	ft_memdel((void **)&map);
}

t_vect	print_to_screen(t_vect vect, t_mlx *mlx)
{
	vect.x -= (double)(mlx->map->width - 1) / 2.0f;
	vect.y -= (double)(mlx->map->height - 1) / 2.0f;
	vect.z -= (double)(mlx->map->z_min + mlx->map->z_max) / 2.0f;
	vect = rotate(vect, mlx->cam);
	vect.x *= mlx->cam->scale;
	vect.y *= mlx->cam->scale;
	vect.x += mlx->cam->offset_x;
	vect.y += mlx->cam->offset_y;
	return (vect);
}

t_vect	rotate(t_vect cur, t_cam *cam)
{
	t_vect		vec;
	double		x;
	double		y;
	double		z;

	x = cur.x;
	z = cur.z;
	vec.x = cos(cam->y) * x + sin(cam->y) * z;
	vec.z = -sin(cam->y) * x + cos(cam->y) * z;
	y = cur.y;
	z = vec.z;
	vec.y = cos(cam->x) * y - sin(cam->x) * z;
	vec.z = sin(cam->x) * y + cos(cam->x) * z;
	vec.color = cur.color;
	return (vec);
}

void		line(t_mlx *mlx, t_vect start, t_vect end)
{
	t_line	line;

	start.x = (int)start.x;
	end.x = (int)end.x;
	start.y = (int)start.y;
	end.y = (int)end.y;
	line.start = start;
	line.end = end;
	if (!lineclip(&start, &end))
		return ;
	line.dx = (int)ft_abs((int)end.x - (int)start.x);
	line.sx = (int)start.x < (int)end.x ? 1 : -1;
	line.dy = (int)ft_abs((int)end.y - (int)start.y);
	line.sy = (int)start.y < (int)end.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (((int)start.x != (int)end.x || (int)start.y != (int)end.y))
		if (line_process_point(mlx, &line, &start, &end))
			break ;
}

int			line_process_point(t_mlx *mlx, t_line *line, t_vect *start, t_vect *end)
{
	double	percent;

	if (start->x < 0 || start->x >= WIN_WIDTH || start->y < 0 || start->y >= WIN_HEIGHT
		|| end->x < 0 || end->x >= WIN_WIDTH || end->y < 0 || end->y >= WIN_HEIGHT)
		return (1);
	percent = (line->dx > line->dy ?
			ft_ilerp((int)start->x, (int)line->start.x, (int)line->end.x)
			: ft_ilerp((int)start->y, (int)line->start.y, (int)line->end.y));
	set_pixel(mlx->image, (int)start->x, (int)start->y, clerp(start->color,
				end->color, percent));
	line->err2 = line->err;
	if (line->err2 > -line->dx)
	{
		line->err -= line->dy;
		start->x += line->sx;
	}
	if (line->err2 < line->dy)
	{
		line->err += line->dx;
		start->y += line->sy;
	}
	return (0);
}
