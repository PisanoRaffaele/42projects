/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 16:59:32 by rpisano           #+#    #+#             */
/*   Updated: 2023/04/02 23:41:50 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# define PTRNULL "(nil)"

int		ft_printf(const char *s, ...);
int		aux_nbr_base(long int n, char c);
int		len_nbr_base(long int n, int base);
void	ft_putnbr_base(long int n, char *base, int len_base);
int		ft_write(char *s);
int		ft_char(char c);
int		aux_printf(va_list var, const char s);
int		print_address(uintptr_t n);
int		len_nbr_address(uintptr_t n, int base);
void	ft_putnbr_address(uintptr_t n, char *base, int len_base);

#endif
