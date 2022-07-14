/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopal <gopal@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 09:14:32 by gopal             #+#    #+#             */
/*   Updated: 2021/10/19 05:04:59 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	sym;

	i = 0;
	str = (unsigned char *) s;
	sym = (unsigned char) c;
	while (n--)
	{
		if (str[i] == sym)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
