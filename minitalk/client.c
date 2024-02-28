/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 23:04:47 by rpisano           #+#    #+#             */
/*   Updated: 2024/02/28 22:22:16 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_byte(int pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

static void	send_str(int pid, char *str)
{
	char	c;

	while (*str)
	{
		send_byte(pid, *str++);
		usleep(100);
	}
	c = 20;
	send_byte(pid, c);
}

void	is_received(int signal)
{
	if (signal != SIGUSR1)
		write(1, "\nError\n\n", 8);
	else
		write(1, "\nOk\n\n", 5);
	exit(0);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		printf("Not 3 arguments");
		return (0);
	}
	signal(SIGUSR1, is_received);
	signal(SIGUSR2, is_received);
	pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);
	pause();
	return (0);
}
