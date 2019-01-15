/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getwordcount.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 09:48:28 by llee              #+#    #+#             */
/*   Updated: 2019/01/14 09:48:43 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_getwordcount(char *str, char tgt)
{
	size_t res;
	size_t i;

	i = 0;
	res = 0;
	while (str[i] && str[i] == tgt)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != tgt)
			i++;
		res++;
		while (str[i] && str[i] == tgt)
			i++;
	}
	return (res);
}
