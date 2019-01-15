/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:53:02 by llee              #+#    #+#             */
/*   Updated: 2018/10/26 15:53:07 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_itoa_sign(long int n)
{
	return ((n < 0) ? -n : n);
}

static int		ft_itoa_getlen(long int n)
{
	int			len;

	len = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int			len;
	int			sign;
	char		*res;

	sign = (n < 0) ? -1 : 1;
	len = ft_itoa_getlen(n);
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	len--;
	while (len >= 0)
	{
		res[len] = '0' + ft_itoa_sign(n % 10);
		n = ft_itoa_sign(n / 10);
		len--;
	}
	if (sign == -1)
		res[0] = '-';
	return (res);
}
