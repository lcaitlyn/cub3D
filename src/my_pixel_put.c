#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, char *color)
{
	int	i;

	i = y * data->line_length + x * (data->bits_per_pixel / 8);
	data->addr[i] = (char)color[2];
	data->addr[++i] = (char)color[1];
	data->addr[++i] = (char)color[0];
	data->addr[++i] = 0;
}
