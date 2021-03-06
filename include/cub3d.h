/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcaitlyn <lcaitlyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:54:24 by lcaitlyn          #+#    #+#             */
/*   Updated: 2022/07/15 14:06:35 by lcaitlyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/inc/libft.h"
#include "../mlx/mlx.h"
#include "keys.h"
#include "../gnl/get_next_line.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

// win_close.c
int	win_close(t_vars *vars);

// key_commands.c
int key_commands(int key, t_vars *vars);
