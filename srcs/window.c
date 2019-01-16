/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 11:15:16 by llee              #+#    #+#             */
/*   Updated: 2019/01/16 11:15:29 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		region(int x, int y)
{
	int c;

	c = 0;
	if (y >= WIN_HEIGHT)
		c |= 1;
	else if (y < 0)
		c |= 2;
	if (x >= WIN_WIDTH)
		c |= 4;
	else if (x < 0)
		c |= 8;
	return (c);
}

void	clip_xy(t_vect *vect, t_vect *start, t_vect *end, int rout)
{
	if (rout & 1)
	{
		vect->x = start->x + (end->x - start->x) * (WIN_HEIGHT - start->y) / (end->y - start->y);
		vect->y = WIN_HEIGHT - 1;
	}
	else if (rout & 2)
	{
		vect->x = start->x + (end->x - start->x) * -start->y / (end->y - start->y);
		vect->y = 0;
	}
	else if (rout & 4)
	{
		vect->x = WIN_WIDTH - 1;
		vect->y = start->y + (end->y - start->y) * (WIN_WIDTH - start->x) / (end->x - start->x);
	}
	else
	{
		vect->x = 0;
		vect->y = start->y + (end->y - start->y) * -start->x / (end->x - start->x);
	}
}

int		lineclip(t_vect *start, t_vect *end)
{
	t_vect		vect;
	int			r1;
	int			r2;
	int			rout;

	r1 = region(start->x, start->y);
	r2 = region(end->x, end->y);
	while (!(!(r1 | r2) || (r1 & r2)))
	{
		rout = r1 ? r1 : r2;
		clip_xy(&vect, start, end, rout);
		if (rout == r1)
		{
			start->x = vect.x;
			start->y = vect.y;
			r1 = region(start->x, start->y);
		}
		else
		{
			end->x = vect.x;
			end->y = vect.y;
			r2 = region(end->x, end->y);
		}
	}
	return (!(r1 | r2));
}
