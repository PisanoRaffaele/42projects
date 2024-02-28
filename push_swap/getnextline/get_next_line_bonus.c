/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:27:51 by rpisano           #+#    #+#             */
/*   Updated: 2023/12/07 10:24:21 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_new_line(char *s)
{
	int		i;
	char	*backup;

	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0' || s[1] == '\0')
		return (0);
	backup = ft_substr(s, i + 1, ft_strlen(s) - i);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	s[i + 1] = '\0';
	return (backup);
}

char	*ft_read_line(int fd, char *buf, char *s)
{
	int		n;
	char	*temp;

	n = 1;
	while (n != 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
			return (NULL);
		else if (n == 0)
			break ;
		buf[n] = '\0';
		if (!s)
			s = ft_strdup("");
		temp = s;
		s = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str[256];
	char		*ret;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 256)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ret = ft_read_line(fd, buf, str[fd]);
	free(buf);
	buf = NULL;
	if (!ret)
		return (NULL);
	str[fd] = ft_new_line(ret);
	return (ret);
}
