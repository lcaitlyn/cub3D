/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 12:25:46 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/08/22 12:56:37 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	texturing_calculations(t_vars *vars)
{
	if (vars->ray.side == 0)
		vars->ray.wall_x = vars->ray.pos_y
			+ vars->ray.perpwalldist * vars->ray.raydir_y;
	else
		vars->ray.wall_x = vars->ray.pos_x
			+ vars->ray.perpwalldist * vars->ray.raydir_x;
	vars->ray.wall_x -= floor(vars->ray.wall_x);
	vars->ray.tex_x = (int)(vars->ray.wall_x * (double)(vars->ray.texwidht));
	if (vars->ray.side == 0 && vars->ray.raydir_x > 0)
		vars->ray.tex_x = vars->ray.texwidht - vars->ray.tex_x - 1;
	if (vars->ray.side == 1 && vars->ray.raydir_y < 0)
		vars->ray.tex_x = vars->ray.texwidht - vars->ray.tex_x - 1;
	vars->ray.step = 1.0 * vars->ray.texheight / vars->ray.lineheigt;
	vars->ray.texpos = (vars->ray.drawstart - vars->ray.h / 2
			+ vars->ray.lineheigt / 2) * vars->ray.step;
	vars->ray.y = vars->ray.drawstart;
}

void	choose_wall_texture_pt2(t_vars *vars)
{
	if (vars->ray.side == 1)
	{
		if (vars->ray.raydir_y > 0)
			vars->ray.color = vars->img.north_data[vars->ray.texheight
				* vars->ray.tex_y + vars->ray.tex_x];
		else
			vars->ray.color = vars->img.south_data[vars->ray.texheight
				* vars->ray.tex_y + vars->ray.tex_x];
	}
	else
	{
		if (vars->ray.raydir_x > 0)
			vars->ray.color = vars->img.west_data[vars->ray.texheight
				* vars->ray.tex_y + vars->ray.tex_x];
		else
			vars->ray.color = vars->img.east_data[vars->ray.texheight
				* vars->ray.tex_y + vars->ray.tex_x];
	}
}

void	choose_wall_texture(t_vars *vars)
{
	while (vars->ray.y < vars->ray.drawend)
	{
		vars->ray.tex_y = (int)vars->ray.texpos & (vars->ray.texheight - 1);
		vars->ray.texpos += vars->ray.step;
		vars->ray.color = vars->img.north_data[vars->ray.texheight
			* vars->ray.tex_y + vars->ray.tex_x];
		choose_wall_texture_pt2(vars);
		vars->ray.buffer[vars->ray.y][vars->ray.x] = vars->ray.color;
		vars->ray.y++;
	}
}

void	render_walls(t_vars *vars)
{
	vars->ray.y = 0;
	while (vars->ray.y < vars->ray.h)
	{
		vars->ray.x = 0;
		while (vars->ray.x < vars->ray.w)
		{
			my_mlx_pixel_put(&vars->img, vars->ray.x, vars->ray.y,
				vars->ray.buffer[vars->ray.y][vars->ray.x]);
			vars->ray.x++;
		}
		vars->ray.y++;
	}
}

void	render_window(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	render_floor_ceilinig(vars);
	while (vars->ray.x < vars->ray.w)
	{
		get_initial_values(vars);
		dda_algorithm(vars);
		if (vars->ray.side == 0)
			vars->ray.perpwalldist = (vars->ray.sidedist_x
					- vars->ray.deltadist_x);
		else
			vars->ray.perpwalldist = (vars->ray.sidedist_y
					- vars->ray.deltadist_y);
		draw_line_calculations(vars);
		texturing_calculations(vars);
		choose_wall_texture(vars);
		vars->ray.x++;
	}
	render_walls(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->img.img);
}
