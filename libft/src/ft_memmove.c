/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopal <gopal@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 02:54:24 by gopal             #+#    #+#             */
/*   Updated: 2021/10/19 05:05:05 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ds;
	char	*sr;

	ds = (char *) dst;
	sr = (char *) src;
	if (sr > ds)
		while (len-- && (dst || src))
			*ds++ = *sr++;
	if (sr < ds)
		while (len-- && (dst || src))
			ds[len] = sr[len];
	return ((void *) dst);
}
