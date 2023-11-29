/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:46:36 by rpisano           #+#    #+#             */
/*   Updated: 2022/11/22 17:17:01 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *dest)
{
	unsigned int	count;

	count = 0;
	while (dest[count] != '\0')
		count++;
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	char			*s1;
	char			*s2;
	unsigned int	len_dest;
	unsigned int	remaing;

	s1 = dest;
	s2 = src;
	remaing = size;
	while (remaing-- != 0 && *s1 != '\0')
		s1++;
	len_dest = s1 - dest;
	remaing = size - len_dest;
	if (remaing == 0)
		return (len_dest + ft_strlen(src));
	while (*src != '\0')
	{
		if (remaing > 1)
		{
			*s1++ = *src;
			remaing--;
		}
		src++;
	}
	*s1 = '\0';
	return (len_dest + (src - s2));
}
