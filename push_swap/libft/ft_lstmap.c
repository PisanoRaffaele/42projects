/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:18:54 by rpisano           #+#    #+#             */
/*   Updated: 2023/03/16 16:19:12 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_node;
	t_list	*node;

	if (!lst)
	{
		ft_lstclear(&lst, del);
		return ((void *)(0));
	}
	node = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst)
	{
		n_node = ft_lstnew(f(lst->content));
		if (!n_node)
		{
			ft_lstclear(&node, del);
			return ((void *)(0));
		}
		ft_lstadd_back(&node, n_node);
		lst = lst->next;
	}
	n_node = NULL;
	return (node);
}
