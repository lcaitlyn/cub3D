/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:20:51 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/08/22 12:55:54 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_space(t_vars *vars, double x, double y)
{
	double	rad_x;
	double	rad_y;
	double	rad;

	rad = 0.2;
	rad_x = -rad;
	rad_y = -rad;
	while (rad_x <= 0.2)
	{
		rad_y = -rad;
		while (rad_y <= 0.2)
		{
			if (vars->map[(int)(x + rad_x)][(int)(y + rad_y)] != '0')
				return (1);
			rad_y += rad;
		}
		rad_x += rad;
	}
	return (0);
}

void	movements_up(t_vars *vars)
{
	if (!check_space(vars, vars->ray.pos_x + vars->ray.dir_x
			* vars->ray.movespeed, vars->ray.pos_y))
		vars->ray.pos_x += vars->ray.dir_x * vars->ray.movespeed;
	if (!check_space(vars, vars->ray.pos_x, vars->ray.pos_y
			+ vars->ray.dir_y * vars->ray.movespeed))
		vars->ray.pos_y += vars->ray.dir_y * vars->ray.movespeed;
	render_window(vars);
}

void	movements_down(t_vars *vars)
{
	if (!check_space(vars, vars->ray.pos_x - vars->ray.dir_x
			* vars->ray.movespeed, vars->ray.pos_y))
		vars->ray.pos_x -= vars->ray.dir_x * vars->ray.movespeed;
	if (!check_space(vars, vars->ray.pos_x, vars->ray.pos_y
			- vars->ray.dir_y * vars->ray.movespeed))
		vars->ray.pos_y -= vars->ray.dir_y * vars->ray.movespeed;
	render_window(vars);
}

void	movements_right(t_vars *vars)
{
	if (!check_space(vars, vars->ray.pos_x + vars->ray.plane_x
			* vars->ray.movespeed, vars->ray.pos_y))
		vars->ray.pos_x += vars->ray.plane_x * vars->ray.movespeed;
	if (!check_space(vars, vars->ray.pos_x, vars->ray.pos_y
			+ vars->ray.plane_y * vars->ray.movespeed))
		vars->ray.pos_y += vars->ray.plane_y * vars->ray.movespeed;
	render_window(vars);
}

void	movements_left(t_vars *vars)
{
	if (!check_space(vars, vars->ray.pos_x - vars->ray.plane_x
			* vars->ray.movespeed, vars->ray.pos_y))
		vars->ray.pos_x -= vars->ray.plane_x * vars->ray.movespeed;
	if (!check_space(vars, vars->ray.pos_x, vars->ray.pos_y
			- vars->ray.plane_y * vars->ray.movespeed))
		vars->ray.pos_y -= vars->ray.plane_y * vars->ray.movespeed;
	render_window(vars);
}
