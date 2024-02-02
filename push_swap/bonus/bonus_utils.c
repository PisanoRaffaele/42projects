/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 22:47:30 by rpisano           #+#    #+#             */
/*   Updated: 2024/02/02 22:53:41 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error_ch(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_check_sub(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		ft_rev_rot(a, 1, 'a');
	else if (line[2] == 'b')
		ft_rev_rot(b, 1, 'b');
	else if (line[2] == 'r')
		ft_rrr(a, b, 1);
}

// This function reads the line and checks if the command is valid.
// If it is, it executes the command.
char	*ft_check(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_swap(a, 1, 'a');
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_swap(b, 1, 'b');
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_push(a, b, 1, 'a');
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_push(b, a, 1, 'b');
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_rotate(a, 1, 'a');
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rotate(b, 1, 'b');
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_check_sub(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ft_rr(a, b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_ss(a, b, 1);
	else
		ft_error_ch();
	return (get_next_line(0));
}

// This function checks the validity of the commands and stack.
// If it is valid, and the stack_a is sorted, the program prints "OK".
void	ft_checker_sub(t_stack **a, t_stack **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_check(a, b, line);
		free(tmp);
	}
	if (*b)
		write(1, "KO\n", 3);
	else if (!ft_checksorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}
