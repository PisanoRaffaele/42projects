/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:49:14 by rpisano           #+#    #+#             */
/*   Updated: 2023/03/29 20:49:16 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long int n, char *base)
{
	long int	len_base;

	len_base = (long int) ft_strlen(base);
	if (n >= len_base)
	{
		ft_putnbr_base(n / len_base, base);
		ft_putchar_fd(base[n % len_base], 1);
	}
	else if (n >= 0 && n < len_base)
		ft_putchar_fd(base[n % len_base], 1);
	else if (n < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr_base(-n, base);
	}
}
