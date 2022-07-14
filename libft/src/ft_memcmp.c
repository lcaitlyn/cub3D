/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopal <gopal@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 09:28:40 by gopal             #+#    #+#             */
/*   Updated: 2021/10/19 05:05:01 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char *) s1;
	str2 = (char *) s2;
	while (n && (*str1 == *str2))
	{
		str1++;
		str2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *) str1 - *(unsigned char *) str2);
}
