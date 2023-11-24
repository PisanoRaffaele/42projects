/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:59:37 by rpisano           #+#    #+#             */
/*   Updated: 2023/04/02 23:49:20 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_address(uintptr_t n, char *base, int len_base)
{
	if (n >= (unsigned long) len_base)
	{
		ft_putnbr_address(n / len_base, base, len_base);
		ft_putnbr_address(n % len_base, base, len_base);
	}
	else
	{
		if (n <= 9)
			ft_char(n + '0');
		else
			ft_char(n - 10 + 'a');
	}
}

int	len_nbr_address(uintptr_t n, int base)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / base;
	}
	return (len);
}

int	print_address(uintptr_t n)
{
	int	print_length;

	print_length = 0;
	if (n == 0)
		print_length += write(1, PTRNULL, 5);
	else
	{
		print_length += write(1, "0x", 2);
		ft_putnbr_address(n, "0123456789abcdef", 16);
		print_length += len_nbr_address(n, 16);
	}
	return (print_length);
}
