/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopal <gopal@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 01:58:07 by gopal             #+#    #+#             */
/*   Updated: 2021/10/19 05:05:03 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ds;
	char	*sr;

	ds = (char *) dst;
	sr = (char *) src;
	while (n-- && (ds || sr))
		ds[n] = sr[n];
	return ((void *) dst);
}
