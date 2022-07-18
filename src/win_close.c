/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:52:31 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/07/15 14:03:18 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	win_close(t_vars *vars)
{
	// mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit (0);
	return (0);
}