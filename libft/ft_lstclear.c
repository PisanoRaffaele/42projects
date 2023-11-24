/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:21:23 by rpisano           #+#    #+#             */
/*   Updated: 2023/03/16 16:21:25 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !del || (*lst) == NULL)
		return ;
	ft_lstclear(&(*lst)->next, del);
	del((*lst)->content);
	free((*lst));
	*lst = NULL;
}
