/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopal <gopal@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:04:17 by gopal             #+#    #+#             */
/*   Updated: 2021/10/19 05:09:37 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (len_src + 1 < dstsize)
		ft_memcpy(dst, src, len_src + 1);
	else if (dstsize > 0)
	{
		ft_memcpy(dst, src, dstsize);
		dst[dstsize - 1] = '\0';
	}
	return (len_src);
}
