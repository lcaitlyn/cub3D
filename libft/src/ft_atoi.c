/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopal <gopal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:59:01 by gopal             #+#    #+#             */
/*   Updated: 2022/06/01 09:03:47 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int n)
{
	return (n == '\t' || n == '\n' || n == '\v'
		|| n == '\f' || n == '\r' || n == ' ');
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -sign;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		num = num * 10 + *str++ - '0';
	return (sign * num);
}
