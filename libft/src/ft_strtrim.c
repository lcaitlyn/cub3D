/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopal <gopal@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 14:05:56 by gopal             #+#    #+#             */
/*   Updated: 2021/10/19 05:10:09 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*s1_cpy;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	s1_cpy = (char *) s1;
	while (*s1_cpy && ft_strchr(set, *s1_cpy))
	{
		s1_cpy++;
		start++;
	}
	if (!*s1_cpy)
		return (ft_calloc(1, 1));
	s1_cpy = (char *) s1 + ft_strlen(s1) - 1;
	while (ft_strchr(set, *s1_cpy))
	{
		s1_cpy--;
		end--;
	}
	len = end - start + 1;
	return (ft_substr(s1, start, len));
}
