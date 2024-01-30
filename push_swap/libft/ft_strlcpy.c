/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:55:52 by rpisano           #+#    #+#             */
/*   Updated: 2023/03/16 16:56:09 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	n;

	n = 0;
	while (src[n] != '\0')
	{
		n++;
	}
	if (destsize == 0)
		return (n);
	i = 0;
	while (src[i] != '\0' && i < destsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (n);
}
