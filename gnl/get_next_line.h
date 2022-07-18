/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:28:47 by lcaitlyn          #+#    #+#             */
/*   Updated: 2021/11/20 15:28:48 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <strings.h>
# include <fcntl.h>
# include <stdlib.h>
# include <../libft/inc/libft.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
//int		ft_strlen(const char *s);
char	*ft_strchr(const char *str, int a);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strdup(char *src);

#endif
