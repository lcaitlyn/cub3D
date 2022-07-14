/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopal <gopal@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 06:03:02 by gopal             #+#    #+#             */
/*   Updated: 2021/10/19 05:05:18 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	sym;

	sym = (unsigned char) c;
	while (*s)
	{
		if (sym == *s)
			return ((char *) s);
		s++;
	}
	if (*s == sym)
		return ((char *) s);
	return (0);
}
