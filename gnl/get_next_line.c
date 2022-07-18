/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:28:43 by lcaitlyn          #+#    #+#             */
/*   Updated: 2021/11/20 15:28:44 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	buf_next_line(char *buf, char **s)
{
	char	*n;

	n = ft_strchr(buf, '\n');
	*n++ = '\0';
	*s = ft_strjoin(*s, buf);
	*s = ft_strjoin(*s, "\n");
	ft_strncpy(buf, n, ft_strlen(n) + 1);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*s;
	long		last;

	if (read(fd, 0, 0) == -1 || BUFFER_SIZE < 1)
		return (NULL);
	last = 1;
	s = ft_strdup("");
	while (!(ft_strchr(buf, '\n')) && last > 0)
	{
		s = ft_strjoin(s, buf);
		last = read(fd, buf, BUFFER_SIZE);
		buf[last] = '\0';
	}
	if (last < 0 || (last == 0 && s[0] == '\0'))
	{
		free (s);
		return (NULL);
	}
	if (ft_strchr(buf, '\n'))
		buf_next_line(buf, &s);
	return (s);
}
