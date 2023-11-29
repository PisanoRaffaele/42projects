/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:39:14 by rpisano           #+#    #+#             */
/*   Updated: 2022/11/28 10:24:22 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial2(int ret, int nb)
{
	ret = ret * nb;
	nb--;
	if (nb > 0)
		return (ft_recursive_factorial2(ret, nb));
	return (ret);
}

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (ft_recursive_factorial2(1, nb));
}
