/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:51:09 by rpisano           #+#    #+#             */
/*   Updated: 2024/02/28 13:59:03 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate: shift up all elements of stack s by one.
// c is the name of stack.
void	ft_rotate(t_stack **s, int j, char c)
{
	t_stack	*tmp;

	if (!*s || !(*s)->next)
		return ;
	tmp = *s;
	*s = get_last_node(*s);
	(*s)->next = tmp;
	*s = tmp->next;
	tmp->next = NULL;
	if (j == 0)
	{
		if (c == 'a')
			write(1, "ra\n", 3);
		else if (c == 'b')
			write(1, "rb\n", 3);
		else
			write(1, "er\n", 3);
	}
}

// swap: swap the first 2 elements at the top of stack s.
// c is the name of stack.
void	ft_swap(t_stack **s, int j, char c)
{
	t_stack	*tmp;

	if (!*s || !((*s)->next))
		return ;
	tmp = *s;
	*s = (*s)->next;
	tmp->next = (*s)->next;
	(*s)->next = tmp;
	if (j == 0)
	{
		if (c == 'a')
			write(1, "sa\n", 3);
		else if (c == 'b')
			write(1, "sb\n", 3);
		else
			write(1, "er\n", 3);
	}
}

// push: take the first element at the top of
// 'from' and put it at the top of 'dest'.
// c is the name of dest stack.
void	ft_push(t_stack **dest, t_stack **from, int j, char c)
{
	t_stack	*tmp;

	if (!*from)
		return ;
	tmp = *dest;
	*dest = *from;
	*from = (*from)->next;
	(*dest)->next = tmp;
	if (j == 0)
	{
		if (c == 'a')
			write(1, "pa\n", 3);
		else if (c == 'b')
			write(1, "pb\n", 3);
		else
			write(1, "er\n", 3);
	}
}

void	ft_rev_rot_2(int j, char c)
{
	if (j == 0)
	{
		if (c == 'a')
			write(1, "rra\n", 4);
		else if (c == 'b')
			write(1, "rrb\n", 4);
		else
			write(1, "er\n", 3);
	}
}

// reverse rotate: shift down all elements of stack s by one.
// c is the name of stack.
void	ft_rev_rot(t_stack **s, int j, char c)
{
	t_stack	*tmp;
	int		i;

	if (!*s || !(*s)->next)
		return ;
	i = 0;
	tmp = *s;
	while ((*s)->next)
	{
		*s = (*s)->next;
		i++;
	}
	(*s)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	ft_rev_rot_2(j, c);
}
