/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:12:31 by llee              #+#    #+#             */
/*   Updated: 2019/01/15 12:12:40 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_file	*init_file(void)
{
	t_file	*file;

	if ((file = ft_memalloc(sizeof(t_file))) == NULL)
		return (NULL);
	return (file);
}

t_map	*init_map(void)
{
	t_map	*map;

	if ((map = ft_memalloc(sizeof(t_map))) == NULL)
		return (NULL);
	return (map);
}
