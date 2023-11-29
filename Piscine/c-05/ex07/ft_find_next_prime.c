/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:19:56 by rpisano           #+#    #+#             */
/*   Updated: 2022/11/29 08:58:55 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;
	int	ret;

	i = 3;
	ret = 1;
	if ((nb % 2 == 0 || nb % 3 == 0) && nb > 3)
		return (0);
	if ((nb % 5 == 0 || nb % 7 == 0) && nb > 7)
		return (0);
	if ((nb % 11 == 0 || nb % 13 == 0) && nb > 13)
		return (0);
	if ((nb % 17 == 0 || nb % 19 == 0) && nb > 19)
		return (0);
	if ((nb % 23 == 0 || nb % 29 == 0) && nb > 29)
		return (0);
	while (i <= nb / 29)
	{
		if (nb % i == 0)
		{
			ret = 0;
		}
		i++;
	}
	return (ret);
}

int	ft_find_next_prime(int nb)
{
	int	ret;
	int	i;

	if (nb < 0)
		return (0);
	else if (nb == 1)
		return (2);
	ret = 0;
	i = nb;
	while (1)
	{
		if (ft_is_prime(i) == 1)
			return (i);
		i++;
	}
}
