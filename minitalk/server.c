/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:09:24 by rpisano           #+#    #+#             */
/*   Updated: 2024/02/28 22:22:33 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static pid_t	g_client_info;

static void	ft_stop(void)
{
	kill(g_client_info, SIGUSR1);
	return ;
}

static void	server(int signal, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				i = 8;

	context = NULL;
	g_client_info = info->si_pid;
	c = c | (signal == SIGUSR1);
	if (--i == 0)
	{
		i = 8;
		if (c == 20)
			ft_stop();
		else
			write(1, &c, 1);
		c = 0;
	}
	else
		c = c << 1;
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.__sigaction_u.__sa_sigaction = server;
	sa.sa_flags = SA_SIGINFO;
	printf("Pid: %d\n\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
