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

// void		fill_colors(t_map *m)
// {
// 	t_vect	v;
// 	t_vect	*cur;

// 	v.y = 0;
// 	while (v.y < m->height)
// 	{
// 		v.x = 0;
// 		while (v.x < m->width)
// 		{
// 			cur = m->vectors[(int)v.y * m->width + (int)v.x];
// 			cur->color = clerp(0xFF00FF, 0xFFFFFF, ft_ilerp(cur->z,
// 				m->z_min, m->z_max));
// 			v.x++;
// 		}
// 		v.y++;
// 	}
// }

int			clerp(int c1, int c2, double p)
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
