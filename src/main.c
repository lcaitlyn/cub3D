/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:42:44 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/07/12 13:58:16 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main()
{
	write (1, "strlen hello", 12);
	
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "cub3D");
	mlx_loop(mlx);
	
	return (0);
}
