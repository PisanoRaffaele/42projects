/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisano <rpisano@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 09:29:18 by rpisano           #+#    #+#             */
/*   Updated: 2023/12/07 12:51:51 by rpisano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd, char *buf, char *backup)
{
	int		read_ret;
	char	*temp;

	read_ret = 1;
	while (read_ret != 0)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1)
			return (0);
		else if (read_ret == 0)
			break ;
		buf[read_ret] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr (buf, '\n'))
			break ;
	}
	return (backup);
}

static char	*extract(char *s)
{
	size_t	i;
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

char	*get_next_line(int fd)
{
	char		*ret;
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	ret = ft_read(fd, buf, backup);
	free(buf);
	buf = NULL;
	if (!ret)
		return (NULL);
	backup = extract(ret);
	return (ret);
}
