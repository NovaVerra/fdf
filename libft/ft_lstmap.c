/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:44:09 by llee              #+#    #+#             */
/*   Updated: 2018/10/27 15:44:53 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = f(lst);
	new = temp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(temp->next = f(lst)))
		{
			free(temp->next);
			return (NULL);
		}
		temp = temp->next;
	}
	return (new);
}
