/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:21:01 by rpisano           #+#    #+#             */
/*   Updated: 2023/03/30 00:03:35 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	if (!lst || !n)
		return ;
	if (*lst == NULL)
	{
		*lst = n;
		return ;
	}
	if ((*lst)->next == NULL)
		(*lst)->next = n;
	else
		ft_lstadd_back(&(*lst)->next, n);
}
