/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:30:19 by rpisano           #+#    #+#             */
/*   Updated: 2024/02/28 14:06:04 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack_node(long num)
{
	t_stack	*new;

	new = malloc(sizeof (t_stack));
	if (!new)
		ft_error();
	new->num = num;
	new->next = NULL;
	return (new);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->num = 0;
		free(*stack);
		*stack = tmp;
	}
}

void	add_back(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(get_last_node(*stack))->next = stack_new;
}

// This function finds what index number n will get after
// it is being pushed to the stack_b. If n is the new biggest
// or the new smallest number, place it  above the old biggest number.
// If not, place it above the number that is bigger than it and below
// the number that is smaller than it.
int	pos_b(t_stack *stack_b, int n)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (n > stack_b->num && n < get_last_node(stack_b)->num)
		i = 0;
	else if (n > get_max_num(stack_b) || n < get_min_num(stack_b))
		i = num_index(stack_b, get_max_num(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->num < n || tmp->num > n)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

// This function finds what index number n will get after
// it is being pushed to the stack_a.
int	pos_a(t_stack *stack_a, int n)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (n < stack_a->num && n > get_last_node(stack_a)->num)
		i = 0;
	else if (n > get_max_num(stack_a) || n < get_min_num(stack_a))
		i = num_index(stack_a, get_min_num(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->num > n || tmp->num < n)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
