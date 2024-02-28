/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:54:11 by rpisano           #+#    #+#             */
/*   Updated: 2024/02/28 15:49:27 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*main2(int argc, char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	a = NULL;
	if (argc < 2 || !check_input(argv))
		ft_error();
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

	i = 1;
	a = NULL;
	if (argc <= 2)
		a = main2(argc, argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi2(argv[i++]);
			add_back(&a, new_stack_node(j));
		}
	}
	if (!a || check_dup(a) || !check_input(argv))
	{
		free_stack(&a);
		ft_error();
	}
	if (!check_sorted(a))
		ft_sort(&a);
	free_stack(&a);
	return (0);
}
