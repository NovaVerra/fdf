/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:22:11 by llee              #+#    #+#             */
/*   Updated: 2018/10/26 13:22:23 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*temp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = -1;
	if (!(temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
	ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[++i])
		temp[i] = s1[i];
	while (*s2)
		temp[i++] = *s2++;
	temp[i] = '\0';
	return (temp);
}
