/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:33:40 by llee              #+#    #+#             */
/*   Updated: 2018/10/25 21:13:30 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*temp;

	if (!(temp = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(temp, '\0', size + 1);
	return (temp);
}
