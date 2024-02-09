/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:44:24 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/09 12:47:12 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	ft_move(t_data *data, int dir)
{
	if (dir == 0)
	{
		if (data->map[(int)(data->pos.p_y + (data->pos.dir_camY *
				MOVE_SPEED))][(int)(data->pos.p_x)] != '1')
			data->pos.p_y += data->pos.dir_camY * MOVE_SPEED;
		if (data->map[(int)(data->pos.p_y)][(int)(data->pos.p_x +
				(data->pos.dir_camX * MOVE_SPEED))] != '1')
			data->pos.p_x += data->pos.dir_camX * MOVE_SPEED;
	}
	else
	{
		if (data->map[(int)(data->pos.p_y - (data->pos.dir_camY *
				MOVE_SPEED))][(int)(data->pos.p_x)] != '1')
			data->pos.p_y -= data->pos.dir_camY * MOVE_SPEED;
		if (data->map[(int)(data->pos.p_y)][(int)(data->pos.p_x -
				(data->pos.dir_camX * MOVE_SPEED))] != '1')
			data->pos.p_x -= data->pos.dir_camX * MOVE_SPEED;
	}
}

void	ft_rotation_left(t_data *data)
{
	double	dirXtemp;
	double	normXtemp;

	dirXtemp = data->pos.dir_camX;
	normXtemp = data->pos.norm_camX;
	data->pos.dir_camX = data->pos.dir_camX * cos(ROT_SPEED) -
		data->pos.dir_camY * sin(ROT_SPEED);
	data->pos.dir_camY = dirXtemp * sin(ROT_SPEED) +
		data->pos.dir_camY * cos(ROT_SPEED);
	data->pos.dir_camX = data->pos.norm_camX * cos(ROT_SPEED) -
		data->pos.norm_camY * sin(ROT_SPEED);
	data->pos.dir_camY = normXtemp * sin(ROT_SPEED) +
		data->pos.norm_camY * cos(ROT_SPEED);
}

void	ft_rotation_right(t_data *data)
{
	double	dirXtemp;
	double	normXtemp;

	dirXtemp = data->pos.dir_camX;
	normXtemp = data->pos.norm_camX;
	data->pos.dir_camX = data->pos.dir_camX * cos(-ROT_SPEED) -
		data->pos.dir_camY * sin(-ROT_SPEED);
	data->pos.dir_camY = dirXtemp * sin(-ROT_SPEED) +
		data->pos.dir_camY * cos(-ROT_SPEED);
	data->pos.dir_camX = data->pos.norm_camX * cos(-ROT_SPEED) -
		data->pos.norm_camY * sin(-ROT_SPEED);
	data->pos.dir_camY = normXtemp * sin(-ROT_SPEED) +
		data->pos.norm_camY * cos(-ROT_SPEED);
}
