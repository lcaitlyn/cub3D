/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:29:29 by lcaitlyn          #+#    #+#             */
/*   Updated: 2021/11/20 15:29:30 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int a)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (void *)0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)a)
		{
			p = (void *)&str[i];
			return (p);
		}
		i++;
	}
	if ((char)a == '\0')
		p = ((void *)&str[i]);
	return (p);
}

//int	ft_strlen(const char *s)
//{
//	int	i;
//
//	i = 0;
//	while (s[i] != '\0')
//		i++;
//	return (i);
//}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	char	*p;
	void	*tmp;

	tmp = (void *)s1;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	p = dest;
	while (*s1 != '\0')
		*dest++ = *s1++;
	while (*s2 != '\0')
		*dest++ = *s2++;
	*dest++ = '\0';
	free (tmp);
	return (p);
}

char	*ft_strdup(char *src)
{
	char	*str;
	char	*p;

	str = (char *)malloc(sizeof(*src) * (ft_strlen(src) + 1));
	if (!str)
		return (NULL);
	p = str;
	while (*src)
	{
		*str++ = *src++;
	}
	*str = '\0';
	return (p);
}
