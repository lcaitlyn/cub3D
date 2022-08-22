/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:20:56 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/08/22 12:56:03 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	close_win(void)
{
	exit (0);
}

void	check_esc(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	commands(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		check_esc(vars);
	else if (keycode == KEY_W)
		movements_up(vars);
	else if (keycode == KEY_S)
		movements_down(vars);
	else if (keycode == KEY_D)
		movements_right(vars);
	else if (keycode == KEY_A)
		movements_left(vars);
	else if (keycode == ARROW_LEFT)
		rotation_left(vars);
	else if (keycode == ARROW_RIGHT)
		rotation_right(vars);
}

void	mouse_move(int x, int y, t_vars *vars)
{
	static int	move;

	if (x >= 0 && x <= vars->ray.w && y >= 0 && y <= vars->ray.h)
	{
		if (x > move)
			rotation_right(vars);
		if (x < move)
			rotation_left(vars);
		move = x;
	}
	render_window(vars);
}
