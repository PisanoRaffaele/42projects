/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:39:21 by rpisano           #+#    #+#             */
/*   Updated: 2022/11/28 10:26:48 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power2(int nb, int power)
{
	int	ret;

	if (power == 0)
		return (1);
	else
	{
		ret = nb * ft_recursive_power2(nb, power - 1);
		return (ret);
	}
}

int	ft_recursive_power(int nb, int power)
{
	int	ret;

	if (power < 0)
		return (0);
	ret = 1;
	if (power > 0)
		ret = ft_recursive_power2(nb, power);
	return (ret);
}
