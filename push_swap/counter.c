/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:52:04 by rpisano           #+#    #+#             */
/*   Updated: 2024/01/30 21:43:16 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function calculates how many times do ra+rb rotation together.
// c is the name of the stack that num is moved to.
int	ft_count_rarb(t_stack *a, t_stack *b, int num, char c)
{
	int	i;

	if (c == 'a')
	{
		i = pos_a(a, num);
		if (i < ft_find_index(b, num))
			i = ft_find_index(b, num);
	}
	else
	{
		i = pos_b(b, num);
		if (i < ft_find_index(a, num))
			i = ft_find_index(a, num);
	}
	return (i);
}

// This function calculates how many times do rra+rrb reverse rotation together.
// c is the name of the stack that num is moved to.
int	ft_count_rrarrb(t_stack *a, t_stack *b, int num, char c)
{
	int	i;

	i = 0;
	if (c == 'b')
	{
		if (pos_b(b, num))
			i = get_size(b) - pos_b(b, num);
		if ((i < (get_size(a) - ft_find_index(a, num))) && ft_find_index(a, num))
			i = get_size(a) - ft_find_index(a, num);
	}
	else
	{
		if (pos_a(a, num))
			i = get_size(a) - pos_a(a, num);
		if ((i < (get_size(b) - ft_find_index(b, num))) && ft_find_index(b, num))
			i = get_size(b) - ft_find_index(b, num);
	}
	return (i);
}

// Again, this function makes similar calculations.
// This function do same calculations for rra+rb case.
// c is the name of the stack that num is moved to.
int	ft_count_rrarb(t_stack *a, t_stack *b, int num, char c)
{
	int	i;

	i = 0;
	if (c == 'b')
	{
		if (ft_find_index(a, num))
			i = get_size(a) - ft_find_index(a, num);
		i = pos_b(b, num) + i;
	}
	else
	{
		if (ft_find_index(b, num))
			i = get_size(b) - ft_find_index(b, num);
		i = pos_a(a, num) + i;
	}
	return (i);
}

// Again, this function makes similar calculations.
// This function do same calculations for ra+rrb case.
// c is the name of the stack that num is moved to.
int	ft_count_rarrb(t_stack *a, t_stack *b, int num, char c)
{
	int	i;

	i = 0;
	if (c == 'b')
	{
		if (pos_b(b, num))
			i = get_size(b) - pos_b(b, num);
		i = ft_find_index(a, num) + i;
	}
	else
	{
		if (pos_a(a, num))
			i = get_size(a) - pos_a(a, num);
		i = ft_find_index(b, num) + i;
	}
	return (i);
}

// This function calculates which rotation combination is the best to sort the stack.
// c is the name of the stack that num is moved to.
int	ft_choose_rotation(t_stack *a, t_stack *b, char c)
{
	int		i;
	t_stack	*tmp;

	if (c == 'a')
	{
		tmp = a;
		i = ft_case_rrarrb(a, b, a->num, c);
	}
	else
	{
		tmp = b;
		i = ft_case_rrarrb(a, b, b->num, c);
	}
	while (tmp)
	{
		if (i > ft_count_rarb(a, b, tmp->num, c))
			i = ft_count_rarb(a, b, tmp->num, c);
		if (i > ft_count_rrarrb(a, b, tmp->num, c))
			i = ft_count_rrarrb(a, b, tmp->num, c);
		if (i > ft_count_rarrb(a, b, tmp->num, c))
			i = ft_count_rarrb(a, b, tmp->num, c);
		if (i > ft_count_rrarb(a, b, tmp->num, c))
			i = ft_count_rrarb(a, b, tmp->num, c);
		tmp = tmp->next;
	}
	return (i);
}
