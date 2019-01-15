/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:31:16 by llee              #+#    #+#             */
/*   Updated: 2018/10/27 15:31:48 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*tempnext;

	temp = *alst;
	while (temp)
	{
		tempnext = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = tempnext;
	}
	*alst = NULL;
}
