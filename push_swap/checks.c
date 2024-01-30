/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:45:12 by rpisano           #+#    #+#             */
/*   Updated: 2024/01/30 18:23:08 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isalpha2(int c)
{
	if ((c >= 58 && c <= 126) || (c >= 33 && c <= 42)
		|| (c == 44) || (c == 46) || (c == 47))
		return (1);
	return (0);
}

//function to check if given arguments is valid
int	check_nums(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j] != '\0'))
		{
			char c = argv[i][j];
			if (c == '+' || c == '-')
			{
				j++;
				if (!ft_isdigit(c))
					return (false);
			}
			else if (ft_isdigit(c))
			{
				j++;
				if (c == '\0')
					break ;
				if (!ft_isdigit(c) && c != ' ')
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

int	check_input(char **argv)
{

	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j]) != '\0')
		{
			if (ft_isalpha2(argv[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	if (!check_nums(argv, 1, 0))
		return (false);
	return (true);
}

int	check_sorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->num;
	while (stack_a)
	{
		if (i > stack_a->num)
			return (0);
		i = stack_a->num;
		stack_a = stack_a->next;
	}
	return (1);
}

int	check_dup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->num == tmp->num)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}
