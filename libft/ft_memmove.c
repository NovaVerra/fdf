/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 13:20:05 by llee              #+#    #+#             */
/*   Updated: 2018/10/22 13:51:26 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp1;
	char	*temp2;
	size_t	i;

	i = -1;
	temp1 = (char *)dst;
	temp2 = (char *)src;
	if (temp2 < temp1)
		while ((int)--len >= 0)
			*(temp1 + len) = *(temp2 + len);
	else
		while (++i < len)
			*(temp1 + i) = *(temp2 + i);
	return (dst);
}
