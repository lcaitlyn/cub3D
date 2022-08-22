/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:29:59 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/08/22 12:56:13 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render_floor_ceilinig(t_vars *vars)
{
	vars->ray.y = 0;
	while (vars->ray.y < vars->ray.h)
	{
		vars->ray.x = 0;
		while (vars->ray.x < vars->ray.w)
		{
			vars->ray.color = vars->img.floor_data;
			vars->ray.buffer[vars->ray.y][vars->ray.x] = vars->ray.color;
			vars->ray.color = vars->img.ceiling_data;
			vars->ray.buffer[vars->ray.h - vars->ray.y - 1][vars->ray.x]
				= vars->ray.color;
			vars->ray.x++;
		}
		vars->ray.y++;
	}
	vars->ray.x = 0;
}

void	get_initial_values(t_vars *vars)
{
	vars->ray.camera_x = 2 * vars->ray.x / (double)vars->ray.w - 1;
	vars->ray.raydir_x = vars->ray.dir_x + vars->ray.plane_x
		* vars->ray.camera_x;
	vars->ray.raydir_y = vars->ray.dir_y + vars->ray.plane_y
		* vars->ray.camera_x;
	vars->ray.map_x = (int)vars->ray.pos_x;
	vars->ray.map_y = (int)vars->ray.pos_y;
	if (vars->ray.raydir_x == 0)
		vars->ray.deltadist_x = 1e30;
	else
		vars->ray.deltadist_x = fabs(1 / vars->ray.raydir_x);
	if (vars->ray.raydir_y == 0)
		vars->ray.deltadist_y = 1e30;
	else
		vars->ray.deltadist_y = fabs(1 / vars->ray.raydir_y);
}

void	dda_preparation(t_vars	*vars)
{
	if (vars->ray.raydir_x < 0)
	{
		vars->ray.step_x = -1;
		vars->ray.sidedist_x = (vars->ray.pos_x - vars->ray.map_x)
			* vars->ray.deltadist_x;
	}
	else
	{
		vars->ray.step_x = 1;
		vars->ray.sidedist_x = (vars->ray.map_x + 1 - vars->ray.pos_x)
			* vars->ray.deltadist_x;
	}
	if (vars->ray.raydir_y < 0)
	{
		vars->ray.step_y = -1;
		vars->ray.sidedist_y = (vars->ray.pos_y - vars->ray.map_y)
			* vars->ray.deltadist_y;
	}
	else
	{
		vars->ray.step_y = 1;
		vars->ray.sidedist_y = (vars->ray.map_y + 1 - vars->ray.pos_y)
			* vars->ray.deltadist_y;
	}
}

void	dda_algorithm(t_vars *vars)
{
	dda_preparation(vars);
	vars->ray.hit = 0;
	while (vars->ray.hit == 0)
	{
		if (vars->ray.sidedist_x < vars->ray.sidedist_y)
		{
			vars->ray.sidedist_x += vars->ray.deltadist_x;
			vars->ray.map_x += vars->ray.step_x;
			vars->ray.side = 0;
		}
		else
		{
			vars->ray.sidedist_y += vars->ray.deltadist_y;
			vars->ray.map_y += vars->ray.step_y;
			vars->ray.side = 1;
		}
		if (vars->map[vars->ray.map_x][vars->ray.map_y] != '0')
			vars->ray.hit = 1;
	}
}

void	draw_line_calculations(t_vars *vars)
{
	vars->ray.lineheigt = (int)(vars->ray.h / vars->ray.perpwalldist);
	vars->ray.drawstart = -vars->ray.lineheigt / 2 + vars->ray.h / 2;
	if (vars->ray.drawstart < 0)
		vars->ray.drawstart = 0;
	vars->ray.drawend = vars->ray.lineheigt / 2 + vars->ray.h / 2;
	if (vars->ray.drawend >= vars->ray.h)
		vars->ray.drawend = vars->ray.h - 1;
}
