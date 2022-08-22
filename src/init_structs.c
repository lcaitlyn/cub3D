/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:19:56 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/08/22 12:57:30 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_assets(t_vars *vars)
{
	vars->assets.floor = NULL;
	vars->assets.ceiling = NULL;
	vars->assets.north_wall = NULL;
	vars->assets.south_wall = NULL;
	vars->assets.east_wall = NULL;
	vars->assets.west_wall = NULL;
}

void	init_ray(t_vars *vars)
{
	int		i;

	vars->ray.pos_x = -1;
	vars->ray.pos_y = -1;
	vars->ray.dir_x = -1;
	vars->ray.dir_y = 0;
	vars->ray.plane_x = 0;
	vars->ray.plane_y = -0.66;
	vars->ray.x = 0;
	vars->ray.w = WIDTH;
	vars->ray.h = HEIGHT;
	vars->ray.texwidht = 64;
	vars->ray.texheight = 64;
	vars->ray.buffer = malloc(sizeof(int *) * vars->ray.h);
	if (!vars->ray.buffer)
		exit(1);
	i = 0;
	while (i < vars->ray.h)
	{
		vars->ray.buffer[i] = malloc(sizeof(int) * vars->ray.w);
		if (!vars->ray.buffer[i])
			exit(1);
		i++;
	}
}

void	init_vars(t_vars *vars)
{
	init_assets(vars);
	init_ray(vars);
	vars->map = NULL;
}
