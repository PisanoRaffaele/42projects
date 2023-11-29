/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:39:09 by rpisano           #+#    #+#             */
/*   Updated: 2022/11/28 10:22:39 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ret;
	int	i;

	if (nb < 0)
		return (0);
	i = 1;
	ret = 1;
	while (i < nb + 1)
	{
		ret = ret * i;
		i++;
	}
	return (ret);
}
