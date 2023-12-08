/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:54:11 by rpisano           #+#    #+#             */
/*   Updated: 2023/12/08 15:00:30 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_valid_input(int argc, char **argv)
{
	int		i;
	int		j;
	char	*str;

	i = 1;
	while (i < argc)
	{
		str = argv[i];
		j = 0;
		while (str[j])
		{
			if (!ft_isdigit(str[j]) && str[j] != '-')
				return (0);
			if(str[j] == '-' && j != 0)
				return (0);
			if(j > 0 && str[j - 1] == '-' && !ft_isdigit(str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!is_valid_input(argc, argv))
		return (0);
	
	return (0);
}
