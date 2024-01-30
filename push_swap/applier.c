/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applier.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:00:26 by rpisano           #+#    #+#             */
/*   Updated: 2024/01/30 22:21:55 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function rotates both stack_a and stack_b
// in the same direction as required amount.
// s is the source stack.
int	ft_apply_rarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->num != c && pos_b(*b, c) > 0)
			ft_rr(a, b, 0);
		while ((*a)->num != c)
			ft_rotate(a, 0, 'a');
		while (pos_b(*b, c) > 0)
			ft_rotate(b, 0, 'b');
		ft_push(b, a, 0, 'b');
	}
	else
	{
		while ((*b)->num != c && pos_a(*a, c) > 0)
			ft_rr(a, b, 0);
		while ((*b)->num != c)
			ft_rotate(b, 0, 'b');
		while (pos_a(*a, c) > 0)
			ft_rotate(a, 0, 'a');
		ft_push(a, b, 0, 'a');
	}
	return (-1);
}

// This function rotate both stack_a and stack_b in the
// reverse direction as required amount.
// s is the source stack.
int	ft_apply_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->num != c && pos_b(*b, c) > 0)
			ft_rrr(a, b, 0);
		while ((*a)->num != c)
			ft_rev_rot(a, 0, 'a');
		while (pos_b(*b, c) > 0)
			ft_rev_rot(b, 0, 'b');
		ft_push(b, a, 0, 'b');
	}
	else
	{
		while ((*b)->num != c && pos_a(*a, c) > 0)
			ft_rrr(a, b, 0);
		while ((*b)->num != c)
			ft_rev_rot(b, 0, 'b');
		while (pos_a(*a, c) > 0)
			ft_rev_rot(a, 0, 'a');
		ft_push(a, b, 0, 'a');
	}
	return (-1);
}

// This function rotate the stack_a in reverse direction,
// the stack_b in oppsite direction of stack_a as required amount.
// s is the source stack.
int	ft_apply_rrarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->num != c)
			ft_rev_rot(a, 0, 'a');
		while (pos_b(*b, c) > 0)
			ft_rotate(b, 0, 'b');
		ft_push(b, a, 0, 'b');
	}
	else
	{
		while (pos_a(*a, c) > 0)
			ft_rev_rot(a, 0, 'a');
		while ((*b)->num != c)
			ft_rotate(b, 0, 'b');
		ft_push(a, b, 0, 'a');
	}
	return (-1);
}

// This function rotate the stack_b in reverse direction,
// the stack_a in oppsite direction of stack_a as required amount.
// s is the source stack.
int	ft_apply_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->num != c)
			ft_rotate(a, 0, 'a');
		while (pos_b(*b, c) > 0)
			ft_rev_rot(b, 0, 'b');
		ft_push(b, a, 0, 'b');
	}
	else
	{
		while (pos_a(*a, c) > 0)
			ft_rotate(a, 0, 'a');
		while ((*b)->num != c)
			ft_rev_rot(b, 0, 'b');
		ft_push(a, b, 0, 'a');
	}
	return (-1);
}
