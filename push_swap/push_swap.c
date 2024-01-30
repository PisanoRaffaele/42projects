/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:54:11 by rpisano           #+#    #+#             */
/*   Updated: 2024/01/30 18:22:18 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*main2(char **argv)
{
	t_stack *a;
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	a = NULL;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi2(tmp[i]);
		add_back(&a, new_stack_node(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	if (argc < 2 || !check_input(argv))
		return (-1);
	if (argc == 2)
		main2(argv);
	else
	{
		i = 1;
		a = NULL;
		while (i < argc)
		{
			j = ft_atoi2(argv[i++]);
			add_back(&a, new_stack_node(j));
		}
	}
	if (a && !check_dup(a) && !check_sorted(a))
		ft_sort(&a);
	free_stack(&a);
	return (0);
}
