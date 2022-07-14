/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gopal <gopal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 02:39:29 by gopal             #+#    #+#             */
/*   Updated: 2022/03/30 02:42:41 by gopal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_pop(t_list **list)
{
	t_list	*top;

	top = NULL;
	if (list && *list)
	{
		top = *list;
		*list = (*list)->next;
	}
	return (top);
}
