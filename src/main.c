/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:42:44 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/08/22 12:43:29 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	raycaster(t_vars *vars)
{
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "cub3d");
	render_window(vars);
	vars->ray.frametime = 0.03;
	vars->ray.movespeed = vars->ray.frametime * 5;
	vars->ray.rotspeed = vars->ray.frametime * 3;
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
		ft_exit("Error! Need map ./cub3d maps/map.cub");
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		ft_exit("Error! mlx init failed\n");
	init_vars(&vars);
	check_file(argv[1], &vars);
	connect_assets(&vars);
	raycaster(&vars);
	mlx_hook(vars.win, 6, 1L << 6, (void *)&mouse_move, &vars);
	mlx_hook(vars.win, 2, 1L << 0, (void *)&commands, &vars);
	mlx_hook(vars.win, 17, 0, (void *)&close_win, 0);
	mlx_loop(vars.mlx);
	return (0);
}
