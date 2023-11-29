/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:56:46 by rpisano           #+#    #+#             */
/*   Updated: 2022/11/29 08:00:52 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	*name;

	name = argv[0];
	while (*name != '\0')
	{
		if (argc > 0)
			write(1, name, 1);
		name++;
	}
	write(1, "\n", 1);
}
