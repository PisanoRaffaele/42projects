/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:00:14 by rpisano           #+#    #+#             */
/*   Updated: 2024/02/01 01:00:16 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function returns the last node of the stack.
t_stack	*get_last_node(t_stack *stack_node)
{
	if (!stack_node)
		return (NULL);
	while (stack_node->next)
		stack_node = stack_node->next;
	return (stack_node);
}

// This function returns the size of the stack.
int	get_size(t_stack *stack_node)
{
	size_t	i;

	i = 0;
	while (stack_node)
	{
		stack_node = stack_node->next;
		i++;
	}
	return (i);
}

// This function finds and returns the smallest number in the given stack.
int	get_min_num(t_stack *stack_node)
{
	int	i;

	i = stack_node->num;
	while (stack_node)
	{
		if (stack_node->num < i)
			i = stack_node->num;
		stack_node = stack_node->next;
	}
	return (i);
}

// This function finds and returns the biggest number in the given stack.
int	get_max_num(t_stack *stack_node)
{
	int	i;

	i = stack_node->num;
	while (stack_node)
	{
		if (stack_node->num > i)
			i = stack_node->num;
		stack_node = stack_node->next;
	}
	return (i);
}

// This function checks the position of a number in the stack.
int	find_num_index(t_stack *a, int num)
{
	int		i;

	i = 0;
	while (a->num != num)
	{
		i++;
		a = a->next;
	}
	if (a)
		a->i = 0;
	return (i);
}
