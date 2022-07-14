/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopal <gopal@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 08:05:18 by gopal             #+#    #+#             */
/*   Updated: 2021/10/19 05:10:07 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*found;
	char	*p;

	c = (unsigned char) c;
	if (c == '\0')
		return (ft_strchr(s, '\0'));
	found = NULL;
	p = ft_strchr(s, c);
	while (p != NULL)
	{
		found = p;
		s = p + 1;
		p = ft_strchr(s, c);
	}
	return ((char *) found);
}
