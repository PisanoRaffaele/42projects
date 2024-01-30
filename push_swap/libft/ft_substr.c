/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:01:58 by rpisano           #+#    #+#             */
/*   Updated: 2023/03/16 17:02:02 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
