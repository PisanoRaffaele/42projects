/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:10:47 by rpisano           #+#    #+#             */
/*   Updated: 2024/02/02 01:28:31 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function sort the stack if there are only three elements in the stack.
void	ft_sort_three(t_stack **stack_a)
{
	if (get_min_num(*stack_a) == (*stack_a)->num)
	{
		ft_rev_rot(stack_a, 0, 'a');
		ft_swap(stack_a, 0, 'a');
	}
	else if (get_max_num(*stack_a) == (*stack_a)->num)
	{
		ft_rotate(stack_a, 0, 'a');
		if (!check_sorted(*stack_a))
			ft_swap(stack_a, 0, 'a');
	}
	else
	{
		if (find_num_index(*stack_a, get_max_num(*stack_a)) == 1)
			ft_rev_rot(stack_a, 0, 'a');
		else
			ft_swap(stack_a, 0, 'a');
	}
}

// This function sorts the stack_a.
// All values are pushed to stack_b, sorted and pushed back to stack_a.
// At the end it brings the smallest number of the stack_a to the top to have stack_a sorted too.
// This function sort and push stacks until 3 members left behind.
void	ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (get_size(*stack_a) > 3 && !check_sorted(*stack_a))
	{
		tmp = *stack_a;
		i = ft_choose_rotation(*stack_a, *stack_b, 'b');
		while (i >= 0)
		{
			if (i == ft_count_rarb(*stack_a, *stack_b, tmp->num, 'b'))
				i = ft_apply_rarb(stack_a, stack_b, tmp->num, 'a');
			else if (i == ft_count_rrarrb(*stack_a, *stack_b, tmp->num, 'b'))
				i = ft_apply_rrarrb(stack_a, stack_b, tmp->num, 'a');
			else if (i == ft_count_rarrb(*stack_a, *stack_b, tmp->num, 'b'))
				i = ft_apply_rarrb(stack_a, stack_b, tmp->num, 'a');
			else if (i == ft_count_rrarb(*stack_a, *stack_b, tmp->num, 'b'))
				i = ft_apply_rrarb(stack_a, stack_b, tmp->num, 'a');
			else
				tmp = tmp->next;
		}
	}
}

// This function pushes all the elements in stack_a to stack_b, until only 3 elements are left.
// While pushing, it makes sure if the stack_b is sorted.
// When three elements are left, it calls ft_sort_three to sort left over elements in stack_a.
t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (get_size(*stack_a) > 3 && !check_sorted(*stack_a))
		ft_push(&stack_b, stack_a, 0, 'b');
	if (get_size(*stack_a) > 3 && !check_sorted(*stack_a))
		ft_push(&stack_b, stack_a, 0, 'b');
	if (get_size(*stack_a) > 3 && !check_sorted(*stack_a))
		ft_sort_b_till_3(stack_a, &stack_b);
	if (!check_sorted(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
}

// This function pushes back the elements from stack_b to stack_a until stack_b is empty.
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = ft_choose_rotation(*stack_a, *stack_b, 'a');
		while (i >= 0)
		{
			if (i == ft_count_rarb(*stack_a, *stack_b, tmp->num, 'a'))
				i = ft_apply_rarb(stack_a, stack_b, tmp->num, 'b');
			else if (i == ft_count_rarrb(*stack_a, *stack_b, tmp->num, 'a'))
				i = ft_apply_rarrb(stack_a, stack_b, tmp->num, 'b');
			else if (i == ft_count_rrarrb(*stack_a, *stack_b, tmp->num, 'a'))
				i = ft_apply_rrarrb(stack_a, stack_b, tmp->num, 'b');
			else if (i == ft_count_rrarb(*stack_a, *stack_b, tmp->num, 'a'))
				i = ft_apply_rrarb(stack_a, stack_b, tmp->num, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}

void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (get_size(*stack_a) == 2)
		ft_swap(stack_a, 0, 'a');
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		i = find_num_index(*stack_a, get_min_num(*stack_a));
		if (i < get_size(*stack_a) - i)
		{
			while ((*stack_a)->num != get_min_num(*stack_a))
				ft_rotate(stack_a, 0, 'a');
		}
		else
		{
			while ((*stack_a)->num != get_min_num(*stack_a))
				ft_rev_rot(stack_a, 0, 'a');
		}
	}
}
