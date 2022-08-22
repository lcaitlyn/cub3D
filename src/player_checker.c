/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:23:35 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/08/22 12:56:30 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_player_direction(char dir, t_vars *vars)
{
	if (dir == 'N')
	{
		vars->ray.dir_x = 1;
		vars->ray.dir_y = 0;
		vars->ray.plane_x = 0;
		vars->ray.plane_y = 0.66;
	}
	if (dir == 'W')
	{
		vars->ray.dir_x = 0;
		vars->ray.dir_y = -1;
		vars->ray.plane_x = 0.66;
		vars->ray.plane_y = 0;
	}
	if (dir == 'E')
	{
		vars->ray.dir_x = 0;
		vars->ray.dir_y = 1;
		vars->ray.plane_x = -0.66;
		vars->ray.plane_y = 0;
	}
}

void	player_pos_check(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'N' || vars->map[y][x] == 'S'
				|| vars->map[y][x] == 'E' || vars->map[y][x] == 'W')
	{
		if (vars->ray.pos_x > 0 || vars->ray.pos_y > 0)
			ft_exit("Error: too many player positions\n");
		get_player_direction(vars->map[y][x], vars);
		vars->ray.pos_x = y + 0.5;
		vars->ray.pos_y = x + 0.5;
		vars->map[y][x] = '0';
	}
}

void	find_player_pos(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			player_pos_check(vars, x, y);
			x++;
		}
		y++;
	}
	if (vars->ray.pos_x < 0 || vars->ray.pos_y < 0)
		ft_exit("Error: no designated player position\n");
}
