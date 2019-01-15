/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:40:14 by llee              #+#    #+#             */
/*   Updated: 2018/10/22 21:50:23 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlen;

	needlen = ft_strlen(needle);
	if (needlen == 0)
		return ((char *)haystack);
	while (*haystack && len-- >= needlen)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, needlen) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
