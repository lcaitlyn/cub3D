/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:57:14 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/08/22 12:55:36 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	map_line_check(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		ft_exit("Error: map line is empty");
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' '
			&& str[i] != 'W' && str[i] != 'E' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != '\n')
			ft_exit(ft_strjoin_f("Error: invalid parameters: ", str, 2));
		i++;
	}
}

void	map_check(t_vars *vars)
{
	int	i;
	int	j;

	i = 1;
	small_map_check(vars);
	border_zero_check(vars);
	while (vars->map[i + 1])
	{
		j = 1;
		while (vars->map[i][j + 1])
		{
			if (vars->map[i][j] == ' ')
				border_void_check(vars, i, j);
			j++;
		}
		i++;
	}
}

void	create_map(t_vars *vars, char *str, int fd)
{
	int	i;

	i = 0;
	vars->map = ft_calloc(sizeof(char *), 101);
	vars->map[0] = str;
	while (str != NULL)
	{
		map_line_check(str);
		if (i > 100)
			ft_exit("Error: map too big\n");
		vars->map[i] = ft_strdup(str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close (fd);
	map_check(vars);
}
