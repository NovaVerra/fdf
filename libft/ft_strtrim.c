/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:36:20 by llee              #+#    #+#             */
/*   Updated: 2018/10/26 13:36:25 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*temp;

	i = -1;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
		len--;
	if (len <= 0)
		len = 0;
	if (!(temp = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	s += i;
	i = -1;
	while (++i <= len)
		temp[i] = *s++;
	temp[i] = '\0';
	return (temp);
}
