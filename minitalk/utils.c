/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:32:53 by rpisano           #+#    #+#             */
/*   Updated: 2024/02/28 16:33:59 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *s1)
{
	size_t	i;
	size_t	s2;
	size_t	num;

	i = 0;
	num = 0;
	s2 = 1;
	while ((s1[i] <= 13 && s1[i] >= 9) || s1[i] == ' ')
		i++;
	if (s1[i] == '-' || s1[i] == '+')
	{
		if (s1[i] == '-')
			s2 *= -1;
		i++;
	}
	while (ft_isdigit(s1[i]))
		num = num * 10 + (s1[i++] - '0');
	s2 *= num;
	return (s2);
}