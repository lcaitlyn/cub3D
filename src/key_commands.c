/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:04:15 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/07/15 14:05:07 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int key_commands(int key, t_vars *vars)
{
    if (key == KEY_ESC)
		win_close(vars);
	// if (key == KEY_C)
	// 	vars->color_shift++;
	// if (key == KEY_PLUS || key == NUM_PAD_PLUS)
	// 	vars->max_iteration++;
	// if ((key == KEY_MINUS || key == NUM_PAD_MINUS) && vars->max_iteration > 2)
	// 	vars->max_iteration--;
	// if (key == KEY_SPACE)
	// 	vars->mouse++;
	// if (key == KEY_R)
	// 	set_default(vars);
	// if (key == ARROW_UP || key == ARROW_DOWN
	// 	|| key == ARROW_LEFT || key == ARROW_RIGHT)
	// 	key_move(key, vars);
	// if (key == KEY_H)
	// 	help(vars);
	// else
	// 	draw_fractal(vars);
	return (0);
}