/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:04:04 by clombard          #+#    #+#             */
/*   Updated: 2022/12/01 12:55:23 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_invalid_base(char *base, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (base[i] == '\0' || len <= 1)
		return (1);
	while (base[j] != '\0')
	{
		if (base[j] == ' ' || (base[j] >= 9 && base[j] <= 13)
			|| base[j] == '+' || base[j] == '-')
			return (1);
		j++;
	}
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
			if (base[i] == base[j++])
				return (1);
		i++;
	}
	return (0);
}

int	ft_is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
	{
		return (1);
	}
	else
		return (0);
}

int	resolve_base(char *base, char match)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == match)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_r_base(char *str, char *base, int len)
{
	int	i;
	int	sign;
	int	ret;
	int	pos;

	sign = 1;
	i = 0;
	ret = 0;
	while (ft_is_space(str[i]) == 1)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1 * sign;
		i++;
	}
	pos = resolve_base(base, str[i]);
	while (pos != -1)
	{
		ret = ret * len;
		ret = ret + pos;
		i++;
		pos = resolve_base(base, str[i]);
	}
	return (ret * sign);
}

int	ft_atoi_base(char *str, char *base)
{
	int	len;
	int	ret;

	ret = 0;
	len = 0;
	while (base[len] != '\0')
		len++;
	if (ft_is_invalid_base(base, len) == 1)
		return (0);
	ret = ft_atoi_r_base(str, base, len);
	return (ret);
}
