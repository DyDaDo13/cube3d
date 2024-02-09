/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 18:00:33 by ozone             #+#    #+#             */
/*   Updated: 2024/02/09 22:17:39 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	get_pos(char c, t_data *data)
{
	if (c == 'N')
	{
		data->pos.dir_camX = 0;
		data->pos.dir_camY = -1;
	}
	if (c == 'W')
	{
		data->pos.dir_camX = -1;
		data->pos.dir_camY = 0;
	}
	if (c == 'S')
	{
		data->pos.dir_camX = 0;
		data->pos.dir_camY = 1;
	}
	if (c == 'E')
	{
		data->pos.dir_camX = 1;
		data->pos.dir_camY = 0;
	}
}

void	get_fov(char c, t_data *data)
{
	if (c == 'N')
	{
		data->pos.norm_camX = FOV;
		data->pos.norm_camY = 0;
	}
	if (c == 'W')
	{
		data->pos.norm_camX = 0;
		data->pos.norm_camY = -FOV;
	}
	if (c == 'S')
	{
		data->pos.norm_camX = -FOV;
		data->pos.norm_camY = 0;
	}
	if (c == 'E')
	{
		data->pos.norm_camX = 0;
		data->pos.norm_camY = FOV;
	}
}

void	get_player_vec_camera(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'S'
				|| data->map[y][x] == 'E'
				|| data->map[y][x] == 'W'
				|| data->map[y][x] == 'N')
			{
				data->pos.c = data->map[y][x];
				get_pos(data->map[y][x], data);
				get_fov(data->map[y][x], data);
				return ;
			}
		}
	}
}
