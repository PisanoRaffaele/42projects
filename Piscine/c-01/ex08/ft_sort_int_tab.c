/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:26:43 by rpisano           #+#    #+#             */
/*   Updated: 2022/11/21 10:45:09 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int		min;
	int		i;
	int		j;
	int		pos_min;

	i = 0;
	while (i < size)
	{
		min = tab[i];
		j = i;
		pos_min = j;
		while (j < size)
		{
			if (tab[j] < min)
			{
				min = tab[j];
				pos_min = j;
			}
			j++;
		}
		tab[pos_min] = tab[i];
		tab[i] = min;
		i++;
	}
}
