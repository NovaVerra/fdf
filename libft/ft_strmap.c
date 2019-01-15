/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:32:19 by llee              #+#    #+#             */
/*   Updated: 2018/10/26 12:32:25 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*temp;

	if (s == NULL)
		return (NULL);
	i = -1;
	if (!(temp = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1))))
		return (NULL);
	while ((char)s[++i])
		temp[i] = (*f)(s[i]);
	temp[i] = '\0';
	return (temp);
}
