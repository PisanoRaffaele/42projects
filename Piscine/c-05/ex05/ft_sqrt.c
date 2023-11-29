/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 08:42:18 by rpisano           #+#    #+#             */
/*   Updated: 2022/11/29 08:16:09 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count(int n)
{
	if (n == 0)
		return (0);
	return (1 + ft_count(n / 10));
}

int	ft_sqrt(int nb)
{
	int	start;
	int	ret;
	int	i;
	int	j;

	start = 1;
	j = 0;
	i = ft_count(nb);
	i = (i - 1) / 2;
	if (nb == 1)
		return (1);
	while (j < i)
	{
		start = start * 10;
		j++;
	}
	ret = 0;
	while (nb / start > start)
		start++;
	if (start * start == nb)
		ret = start;
	return (ret);
}
