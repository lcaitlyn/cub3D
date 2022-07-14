/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopal <gopal@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:46:17 by gopal             #+#    #+#             */
/*   Updated: 2021/10/19 05:10:11 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sb_str;
	unsigned int	l;

	if (s == NULL)
		return (ft_calloc(0, 0));
	l = ft_strlen(s);
	if (start >= l)
		return (ft_calloc(1, 1));
	if (len > l)
		len = l - start;
	sb_str = ft_calloc(len + 1, 1);
	if (!sb_str)
		return (NULL);
	ft_memcpy(sb_str, &s[start], len);
	return (sb_str);
}
