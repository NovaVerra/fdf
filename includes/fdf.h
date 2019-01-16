/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:03:51 by llee              #+#    #+#             */
/*   Updated: 2019/01/11 14:04:00 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_HEIGHT	1080
# define WIN_WIDTH	1920

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>

typedef struct	s_file
{
	int			fd;
	int			retval;
	char		*path;
	char		*buf;
	char		**cmap;
}				t_file;

typedef struct	s_vect
{
	double		x;
	double		y;
	double		z;
	int			color;
}				t_vect;

typedef struct	s_line
{
	t_vect		start;
	t_vect		end;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err2;
}				t_line;

typedef struct	s_map
{
	int			**imap;
	int			height;
	int			width;
	int			z_max;
	int			z_min;
}				t_map;

typedef struct	s_image
{
	void		*img;
	char		*ptr;
	int			bpp;
	int			line;
	int			endian;
}				t_image;

typedef struct	s_cam
{
	double		x;
	double		y;
	double		offset_x;
	double		offset_y;
	int			scale;
	double		*matrix;
}				t_cam;

typedef struct	s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			prev_x;
	int			prev_y;
}				t_mouse;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	double		**zbuf;
	t_map		*map;
	t_image		*image;
	t_cam		*cam;
	t_mouse		*mouse;
}				t_mlx;

// main.c
void			setup_map(t_file **file, t_map **map, char *path);
void			setup_mlx(t_map **map, t_mlx **mlx);
void			print_map(t_map **map);

// init.c
t_file			*init_file(void);
t_map			*init_map(void);
t_mlx			*init_mlx(void);
t_vect			*init_vect(void);
t_image			*init_image(t_mlx *mlx);

// clean.c
t_file			*clean_buf(t_file *file);
t_file			*clean_cmap(t_file *file);
t_file			*clean_file(t_file *file);
t_mlx			*clean_mlx(t_mlx *mlx);
t_image			*clean_image(t_mlx *mlx, t_image *image);
void			reset_image(t_image *image);

// read.c
int				copy_argv(t_file **file, char *path);
int				get_row_col(t_file **file, t_map **map);
int				read_whole_file(t_file **file);
int				open_file(t_file **file);
int				close_file(t_file **file);

// map.c
int				make_map(t_map **map);
int				copy_to_map(t_file **file, t_map **map);
void			find_min_max(t_map **map);
t_vect			transform(int x, int y, t_map *map);
void			set_pixel(t_image *image, int x, int y, int color);

// render.c
void			render(t_mlx *mlx);
t_vect			print_to_screen(t_vect vect, t_mlx *mlx);
t_vect			rotate(t_vect cur, t_cam *cam);
void			line(t_mlx *mlx, t_vect start, t_vect end);
int				line_process_point(t_mlx *mlx, t_line *line, t_vect *start, t_vect *end);

// window.c
int				lineclip(t_vect *p1, t_vect *p2);
int				region(int x, int y);
void			clip_xy(t_vect *v, t_vect *p1, t_vect *p2, int rout);

#endif
