/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopal <gopal@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:16:30 by gopal             #+#    #+#             */
/*   Updated: 2021/10/19 05:05:25 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		l;
	int		i;
	char	*dest;

	i = 0;
	l = ft_strlen(src);
	dest = malloc(sizeof(*src) * (l + 1));
	if (dest == NULL)
		return (NULL);
	while (i < l)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
