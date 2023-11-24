/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:11:50 by rpisano           #+#    #+#             */
/*   Updated: 2023/03/16 16:12:10 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dst_ptr;
	const char	*src_ptr;

	if (!dest && !src)
		return (0);
	dst_ptr = (char *) dest;
	src_ptr = (const char *) src;
	while (n-- > 0)
		*dst_ptr++ = *src_ptr++;
	return (dest);
}
