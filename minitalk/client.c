/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 23:04:47 by rpisano           #+#    #+#             */
/*   Updated: 2024/02/25 23:12:35 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int semaphore;

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	int	bit;

	bit = 0;
	(void)context;
	semaphore = 1;

	if (signum == SIGUSR2)
		bit++;
	else if (signum == SIGUSR1)

}
