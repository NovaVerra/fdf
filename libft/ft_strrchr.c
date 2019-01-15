/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:25:37 by llee              #+#    #+#             */
/*   Updated: 2018/10/22 20:18:15 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*temp;

	temp = (char *)s + ft_strlen(s);
	while (*temp != (unsigned char)c)
	{
		if (temp == s)
			return (NULL);
		temp--;
	}
	return (temp);
}
