/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:13:07 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/08/22 13:15:10 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	strjoin_cleaner(char *s1, char *s2, int need_free)
{
	if (need_free == 1)
		free (s1);
	else if (need_free == 2)
		free (s2);
	else if (need_free == 3)
	{
		free (s1);
		free (s2);
	}
}

char	*ft_strjoin_f(char *s1, char *s2, int need_free)
{
	char	*dest;
	char	*p;
	void	*tmp;
	void	*tmp2;

	tmp = (void *)s1;
	tmp2 = (void *)s2;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	p = dest;
	while (s1 && *s1 != '\0')
		*dest++ = *s1++;
	while (s2 && *s2 != '\0')
		*dest++ = *s2++;
	*dest++ = '\0';
	strjoin_cleaner(tmp, tmp2, need_free);
	return (p);
}
