/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:56:28 by rpisano           #+#    #+#             */
/*   Updated: 2023/03/30 00:43:16 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countarray(char const *s, char c)
{
	int	i;
	int	array;

	i = 0;
	array = 0;
	if (!s)
		return (0);
	if (s[i] && s[i] != c)
		array++;
	if (s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			array++;
		i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	array;
	size_t	start;
	char	**str;

	j = 0;
	i = 0;
	array = ft_countarray(s, c);
	str = malloc((array + 1) * sizeof(char *));
	if (!str || !s)
		return (NULL);
	while (s[i] && j < array)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		str[j] = ft_substr(s, start, i - start);
		j++;
	}
	str[j] = NULL;
	return (str);
}
