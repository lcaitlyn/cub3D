/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopal <gopal@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 05:02:53 by gopal             #+#    #+#             */
/*   Updated: 2021/10/19 05:05:06 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*s;
	unsigned char	sym;

	s = (char *) b;
	sym = (unsigned char) c;
	while (len--)
		s[len] = sym;
	return (b);
}
