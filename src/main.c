/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:42:44 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/07/15 13:56:11 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	
	int fd = open(argv[1], O_RDONLY);
	char *str;
	int i = 0;
	str = "1";
	char *str1 = ft_strdup("");
	while (str)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		i++;
		str1 = ft_strjoin(str1, str);
		free(str);
	}
	write(1, str1, ft_strlen(str1));
//	char **arr;
//	arr = (char **)ft_calloc(sizeof(char *), i + 1);
//	str = "1";
//	int j = -1;
//	while (arr[i])
//		write (1, arr[i], ft_strlen(arr[i++]));
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 800, 600, "cub3D");
	mlx_hook(vars->win, 17, 0, win_close, vars);
	mlx_hook(vars->win, 2, 0, key_commands, vars);
	
	
		
	
	mlx_loop(vars->mlx);
	return (0);
}
