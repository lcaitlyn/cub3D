/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 15:25:39 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/08/22 13:01:58 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_walls(t_vars *vars, char *str)
{
	char	**argv;

	if (ft_strlen(str) == 0)
		return (0);
	argv = ft_split(str, ' ');
	if (!ft_strncmp(argv[0], "NO ", 2) && !c(vars->assets.north_wall))
		vars->assets.north_wall = ft_strdup(argv[1]);
	else if (!ft_strncmp(argv[0], "SO ", 2) && !c(vars->assets.south_wall))
		vars->assets.south_wall = ft_strdup(argv[1]);
	else if (!ft_strncmp(argv[0], "WE ", 2) && !c(vars->assets.west_wall))
		vars->assets.west_wall = ft_strdup(argv[1]);
	else if (!ft_strncmp(argv[0], "EA ", 2) && !c(vars->assets.east_wall))
		vars->assets.east_wall = ft_strdup(argv[1]);
	else if (!ft_strncmp(argv[0], "F ", 1) && !c(vars->assets.floor))
		vars->assets.floor = ft_strdup(argv[1]);
	else if (!ft_strncmp(argv[0], "C ", 1) && !c(vars->assets.ceiling))
		vars->assets.ceiling = ft_strdup(argv[1]);
	else
	{
		ft_free_split(argv);
		return (1);
	}
	ft_free_split(argv);
	return (0);
}

int	check_line(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0' || ft_strlen(str) == 0)
		return (1);
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' '
			&& str[i] != 'W' && str[i] != 'E' && str[i] != 'N'
			&& str[i] != 'S' && str[i] != '\n')
			ft_exit(ft_strjoin_f("Error: invalid parameters: ", str, 2));
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_map_line(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0' || ft_strlen(str) == 0)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

void	check_file_argv(int fd, t_vars *vars)
{
	char	*str;

	str = get_next_line(fd);
	while (str != NULL)
	{
		if (check_walls(vars, str) && is_map_line(str))
		{
			check_assets(vars);
			return (create_map(vars, str, fd));
		}
		free(str);
		str = get_next_line(fd);
	}
}

void	check_file(char *file, t_vars *vars)
{
	int	fd;

	if (ft_strlen(file) < 5
		|| !ft_strnstr(file + ft_strlen(file) - 4, ".cub", 4))
		ft_exit("Error! Need map .cub");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_exit("Error! Arg is not file");
	check_file_argv(fd, vars);
	small_map_check(vars);
	find_player_pos(vars);
}
