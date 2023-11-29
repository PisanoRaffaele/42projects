/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:25:13 by rpisano           #+#    #+#             */
/*   Updated: 2022/11/22 10:16:48 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_alphanumeric(char c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	return (0);
}

int	ft_first(char *str, int i)
{
	if (str[i] >= 97 && str[i] <= 122)
	{
		str[i] = str[i] - 32;
	}
	return (0);
}

void	ft_lower(char *str, int i)
{
	if (str[i] >= 65 && str[i] <= 90)
	{
		str[i] = str[i] + 32;
	}
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		first;

	i = 0;
	first = 1;
	while (str[i] != '\0')
	{
		if (ft_is_alphanumeric(str[i]) == 1)
		{
			if (first == 1)
			{
				first = ft_first(str, i);
			}
			else
			{
				ft_lower(str, i);
			}
		}
		else
		{
			first = 1;
		}
		i++;
	}
	return (str);
}
