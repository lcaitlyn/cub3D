/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:54:24 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/08/22 13:02:16 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/inc/libft.h"
# include "../mlx/mlx.h"
# include "keys.h"
# include "../gnl/get_next_line.h"

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define WIDTH 1320
# define HEIGHT 800

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*north_wall;
	void	*south_wall;
	void	*east_wall;
	void	*west_wall;
	int		*north_data;
	int		*south_data;
	int		*east_data;
	int		*west_data;
	int		floor_data;
	int		ceiling_data;
}	t_data;

typedef struct s_assets
{
	char	*floor;
	char	*ceiling;
	char	*north_wall;
	char	*south_wall;
	char	*east_wall;
	char	*west_wall;
}	t_assets;

typedef struct s_raycaster
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	int		x;
	int		y;
	int		w;
	int		h;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwalldist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		lineheigt;
	int		drawstart;
	int		drawend;
	int		color;
	double	frametime;
	double	movespeed;
	double	rotspeed;
	double	olddir_x;
	double	oldplane_x;
	int		texwidht;
	int		texheight;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	texpos;
	int		**buffer;
	int		trigger;
}	t_ray;

typedef struct s_minimap
{
	int	size;
	int	bor_x;
	int	bor_y;
	int	x;
	int	y;
	int	i;
	int	j;
}	t_map;

typedef struct s_vars
{
	t_data		img;
	t_assets	assets;
	t_ray		ray;
	t_map		mmap;
	void		*mlx;
	void		*win;
	char		**map;
	int			x;
	int			y;
}	t_vars;

// ft_exit.c
void	ft_exit(char *err);

// init_structs.c
void	init_vars(t_vars *vars);

// check_file.c
int		check_file(char *file, t_vars *vars);
int		check_line(char *str);

// ft_split_len.c
int		ft_split_len(char *arr[]);

// map.c
void	create_map(t_vars *vars, char *str, int fd);

// map_checker.c
void	small_map_check(t_vars *vars);
void	border_zero_check(t_vars *vars);
void	check_we_ea_so_border(t_vars *vars, int *flag);
void	check_east_border(t_vars *vars, int *flag);
void	border_void_check(t_vars *vars, int i, int j);

// player_checker.c
void	find_player_pos(t_vars *vars);

// assets.c
int		c(char *arg);
void	connect_assets(t_vars *vars);
void	check_assets(t_vars *vars);

// my_mlx_pixel_put.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// render.c
void	render_floor_ceilinig(t_vars *vars);
void	get_initial_values(t_vars *vars);
void	dda_preparation(t_vars	*vars);
void	dda_algorithm(t_vars *vars);
void	draw_line_calculations(t_vars *vars);

// movements.c
int		check_space(t_vars *vars, double x, double y);
void	movements_up(t_vars *vars);
void	movements_down(t_vars *vars);
void	movements_right(t_vars *vars);
void	movements_left(t_vars *vars);

// rotation.c
void	rotation_right(t_vars *vars);
void	rotation_left(t_vars *vars);

// commands.c
void	close_win(void);
void	check_esc(t_vars *vars);
void	commands(int keycode, t_vars *vars);
void	mouse_move(int x, int y, t_vars *vars);

// raycaster.c
void	texturing_calculations(t_vars *vars);
void	choose_wall_texture_pt2(t_vars *vars);
void	choose_wall_texture(t_vars *vars);
void	render_walls(t_vars *vars);
void	render_window(t_vars *vars);

#endif