/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:10:18 by rpisano           #+#    #+#             */
/*   Updated: 2022/11/22 17:16:38 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*s1;
	char	*s2;

	if (*to_find == '\0')
		return (str);
	s1 = str;
	s2 = to_find;
	while (1 == 1)
	{
		if (*s2 == '\0')
			return ((char *)(s1 - (s2 - to_find)));
		if (*s1 == *s2)
			s2++;
		else
			s2 = to_find;
		if (*s1 == '\0')
			break ;
		s1++;
	}
	return (0);
}
