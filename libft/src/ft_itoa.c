/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopal <gopal@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 21:48:07 by gopal             #+#    #+#             */
/*   Updated: 2021/11/02 16:52:37 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill_str(char *str, long n, long len)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (len > 0)
	{
		str[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

static int	ft_calc_len(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		is_minus;
	long	n_copy;

	is_minus = 0;
	n_copy = n;
	if (n < 0)
	{
		is_minus = 1;
		n_copy = -n_copy;
	}
	len = ft_calc_len(n_copy) + is_minus;
	str = ft_calloc(len + 1, sizeof(int));
	if (!str)
		return (NULL);
	str = ft_fill_str(str, n_copy, len);
	if (is_minus)
		str[0] = '-';
	return (str);
}
