/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:41:10 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/08/22 13:14:36 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	c(char *arg)
{
	if (arg != NULL)
		ft_exit("Error: double parameters\n");
	return (0);
}

void	check_assets(t_vars *vars)
{
	if (!vars->assets.north_wall || !vars->assets.south_wall
		|| !vars->assets.east_wall || !vars->assets.west_wall
		|| !vars->assets.ceiling || !vars->assets.floor)
		ft_exit("Error: not enough assets\n");
}

int	find_color(char *str)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	split = ft_split(str, ',');
	if (ft_split_len(split) != 3)
		ft_exit("Error: not enought ceiling args");
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_exit("Error: color component out of range\n");
	ft_free_split(split);
	return (256 * 256 * r + 256 * g + b);
}

void	load_assest(t_vars *vars, t_data *img, t_assets *assets)
{
	int	img_width;
	int	img_height;

	vars->img.north_wall = mlx_xpm_file_to_image(vars->mlx,
			vars->assets.north_wall, &img_width, &img_height);
	vars->img.east_wall = mlx_xpm_file_to_image(vars->mlx,
			vars->assets.east_wall, &img_width, &img_height);
	vars->img.west_wall = mlx_xpm_file_to_image(vars->mlx,
			vars->assets.west_wall, &img_width, &img_height);
	vars->img.south_wall = mlx_xpm_file_to_image(vars->mlx,
			vars->assets.south_wall, &img_width, &img_height);
	if (!vars->img.north_wall || !vars->img.east_wall
		|| !vars->img.west_wall || !vars->img.south_wall)
		ft_exit("Error: wrong assets");
	img->north_data = (int *)mlx_get_data_addr(img->north_wall,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	img->south_data = (int *)mlx_get_data_addr(img->south_wall,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	img->east_data = (int *)mlx_get_data_addr(img->east_wall,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	img->west_data = (int *)mlx_get_data_addr(img->west_wall,
			&img->bits_per_pixel, &img->line_length, &img->endian);
}

void	connect_assets(t_vars *vars)
{
	char	*str;

	load_assest(vars, &vars->img, &vars->assets);
	if (!vars->img.north_wall || !vars->img.south_wall
		|| !vars->img.east_wall || !vars->img.west_wall)
		ft_exit("Error: wrong assets\n");
	vars->img.floor_data = find_color(vars->assets.floor);
	vars->img.ceiling_data = find_color(vars->assets.ceiling);
}
