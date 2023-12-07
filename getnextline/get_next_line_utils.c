/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:33:27 by rpisano           #+#    #+#             */
/*   Updated: 2023/12/07 12:33:32 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	if (*s)
		return (1 + ft_strlen(s + 1));
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	lenght;

	if (!s)
		return (NULL);
	lenght = ft_strlen(s);
	if (lenght <= len)
		sub = (char *)malloc(sizeof(char) * lenght + 1);
	else
		sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (start < lenght && len-- > 0)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *) s);
		s++;
	}
	if (*s == i)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*ret;

	len = ft_strlen((char *)s);
	ret = (char *)malloc(len * sizeof(char) + 1);
	if (ret == NULL)
		return (NULL);
	while (len >= 0)
	{
		ret[len] = s[len];
		len--;
	}
	return (ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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
