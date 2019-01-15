/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:08:37 by llee              #+#    #+#             */
/*   Updated: 2018/10/26 15:08:41 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strsplit_getwordcount(const char *s, const char c)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char		**ft_strsplit_malloc(char const *s, char c)
{
	char		**result;
	int			i;
	int			j;
	int			wordcount;
	int			alphacount;

	wordcount = ft_strsplit_getwordcount(s, c);
	if (!s || !(result = (char **)malloc(sizeof(char *) * (wordcount + 1))))
		return (NULL);
	result[wordcount] = 0;
	j = -1;
	i = -1;
	while (++i < (int)ft_strlen(s))
	{
		alphacount = 0;
		while (s[i] != c && s[i])
		{
			alphacount++;
			i++;
		}
		if ((s[i - 1] != c) && i > 0)
			if (!(result[++j] = ft_strsub(s, (i - alphacount), alphacount)))
				return (NULL);
	}
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**result;

	if (s == NULL)
		return (NULL);
	result = ft_strsplit_malloc(s, c);
	return (result);
}
