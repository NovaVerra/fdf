/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ilerp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 11:02:04 by llee              #+#    #+#             */
/*   Updated: 2019/01/03 11:02:22 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_ilerp(double point, double min, double max)
{
	if (point == min)
		return (0.0);
	if (point == max)
		return (1.0);
	return ((point - min) / (max - min));
}
