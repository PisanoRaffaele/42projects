/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:45:44 by rpisano           #+#    #+#             */
/*   Updated: 2024/02/02 22:56:04 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*main3(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
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
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	int		i;
	int		j;

	b = NULL;
	a = main3(argc, argv);
	if (!a || check_dup(a))
	{
		free_stack(&a);
		ft_error_ch();
	}
	line = get_next_line(0);
	if (!line && !check_sorted(a))
		write(1, "KO\n", 3);
	else if (!line && check_sorted(a))
		write(1, "OK\n", 3);
	else
		ft_checker_sub(&a, &b, line);
	free_stack(&b);
	free_stack(&a);
	return (0);
}
