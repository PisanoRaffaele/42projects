/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:37:26 by rpisano           #+#    #+#             */
/*   Updated: 2023/03/30 00:42:51 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len(const char *s)
{
	if (*s)
		return (1 + len(s + 1));
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * (len(s1) + len(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s1 || *s2)
	{
		if (*s1)
			res[i++] = *s1++;
		else
			res[i++] = *s2++;
	}
	res[i] = '\0';
	return (res);
}
