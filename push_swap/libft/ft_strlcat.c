/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:46:17 by rpisano           #+#    #+#             */
/*   Updated: 2023/03/16 15:47:20 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = ft_strlen(dst);
	j = ft_strlen((char *)src);
	x = 0;
	if (size <= i)
		x = j + size;
	else
		x = j + i;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
		dst[i++] = src[j++];
	if (j > 0)
		dst[i] = '\0';
	return (x);
}
