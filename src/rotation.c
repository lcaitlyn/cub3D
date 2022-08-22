/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:21:37 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/08/22 12:56:00 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotation_right(t_vars *vars)
{
	vars->ray.olddir_x = vars->ray.dir_x;
	vars->ray.dir_x = vars->ray.dir_x * cos(vars->ray.rotspeed)
		- vars->ray.dir_y * sin(vars->ray.rotspeed);
	vars->ray.dir_y = vars->ray.olddir_x * sin(vars->ray.rotspeed)
		+ vars->ray.dir_y * cos(vars->ray.rotspeed);
	vars->ray.oldplane_x = vars->ray.plane_x;
	vars->ray.plane_x = vars->ray.plane_x * cos(vars->ray.rotspeed)
		- vars->ray.plane_y * sin(vars->ray.rotspeed);
	vars->ray.plane_y = vars->ray.oldplane_x * sin(vars->ray.rotspeed)
		+ vars->ray.plane_y * cos(vars->ray.rotspeed);
	render_window(vars);
}

void	rotation_left(t_vars *vars)
{
	vars->ray.olddir_x = vars->ray.dir_x;
	vars->ray.dir_x = vars->ray.dir_x * cos(-vars->ray.rotspeed)
		- vars->ray.dir_y * sin(-vars->ray.rotspeed);
	vars->ray.dir_y = vars->ray.olddir_x * sin(-vars->ray.rotspeed)
		+ vars->ray.dir_y * cos(-vars->ray.rotspeed);
	vars->ray.oldplane_x = vars->ray.plane_x;
	vars->ray.plane_x = vars->ray.plane_x * cos(-vars->ray.rotspeed)
		- vars->ray.plane_y * sin(-vars->ray.rotspeed);
	vars->ray.plane_y = vars->ray.oldplane_x * sin(-vars->ray.rotspeed)
		+ vars->ray.plane_y * cos(-vars->ray.rotspeed);
	render_window(vars);
}
