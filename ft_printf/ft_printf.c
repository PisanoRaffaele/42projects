/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:59:25 by rpisano           #+#    #+#             */
/*   Updated: 2023/04/02 16:59:28 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	aux_printf(va_list var, const char str)
{
	int		count;

	count = 0;
	if (str == 's')
		count += ft_write(va_arg(var, char *));
	else if (str == 'c')
		count += ft_char(va_arg(var, int));
	else if (str == 'd' || str == 'i')
		count += aux_nbr_base(va_arg(var, int), str);
	else if (str == 'u')
		count += aux_nbr_base(va_arg(var, unsigned int), str);
	else if (str == 'x' || str == 'X')
		count += aux_nbr_base(va_arg(var, int), str);
	else if (str == 'p')
		count += print_address(va_arg(var, uintptr_t));
	else
		count += ft_char(str);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	var;

	i = 0;
	count = 0;
	va_start(var, str);
	while (str[i] != '%')
		count += ft_char(str[i++]);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count += aux_printf(var, str[i]);
		}
		else
			count += ft_char(str[i]);
		i++;
	}
	va_end(var);
	return (count);
}
