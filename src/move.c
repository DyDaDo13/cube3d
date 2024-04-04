/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:44:24 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/04 15:31:45 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	ft_move2(t_data *data, int dir)
{
	if (dir == 2)
	{
		if (data->map[(int)(data->pos.p_y + (data->pos.norm_camY
					* data->move_speed))][(int)(data->pos.p_x)] != '1')
			data->pos.p_y += data->pos.norm_camY * data->move_speed;
		if (data->map[(int)(data->pos.p_y)][(int)(data->pos.p_x +
				(data->pos.norm_camX * data->move_speed))] != '1')
			data->pos.p_x += data->pos.norm_camX * data->move_speed;
	}
	else if (dir == 3)
	{
		if (data->map[(int)(data->pos.p_y - (data->pos.norm_camY
					* data->move_speed))][(int)(data->pos.p_x)] != '1')
			data->pos.p_y -= data->pos.norm_camY * data->move_speed;
		if (data->map[(int)(data->pos.p_y)][(int)(data->pos.p_x -
				(data->pos.norm_camX * data->move_speed))] != '1')
			data->pos.p_x -= data->pos.norm_camX * data->move_speed;
	}
}

void	ft_move(t_data *data, int dir)
{
	if (dir == 0)
	{
		if (data->map[(int)(data->pos.p_y + (data->pos.dir_camY
					* data->move_speed))][(int)(data->pos.p_x)] != '1')
			data->pos.p_y += data->pos.dir_camY * data->move_speed;
		if (data->map[(int)(data->pos.p_y)][(int)(data->pos.p_x +
				(data->pos.dir_camX * data->move_speed))] != '1')
			data->pos.p_x += data->pos.dir_camX * data->move_speed;
	}
	else if (dir == 1)
	{
		if (data->map[(int)(data->pos.p_y - (data->pos.dir_camY
					* data->move_speed))][(int)(data->pos.p_x)] != '1')
			data->pos.p_y -= data->pos.dir_camY * data->move_speed;
		if (data->map[(int)(data->pos.p_y)][(int)(data->pos.p_x -
				(data->pos.dir_camX * data->move_speed))] != '1')
			data->pos.p_x -= data->pos.dir_camX * data->move_speed;
	}
	else
		ft_move2(data, dir);
}

void	ft_rotation(t_data *data, double rot_coef)
{
	double	dirxtemp;
	double	normxtemp;

	dirxtemp = data->pos.dir_camX;
	normxtemp = data->pos.norm_camX;
	data->pos.dir_camX = data->pos.dir_camX * cos(rot_coef)
		- data->pos.dir_camY * sin(rot_coef);
	data->pos.dir_camY = dirxtemp * sin(rot_coef)
		+ data->pos.dir_camY * cos(rot_coef);
	data->pos.norm_camX = data->pos.norm_camX * cos(rot_coef)
		- data->pos.norm_camY * sin(rot_coef);
	data->pos.norm_camY = normxtemp * sin(rot_coef)
		+ data->pos.norm_camY * cos(rot_coef);
}

void	ft_rotation_left(t_data *data)
{
	double	dirxtemp;
	double	normxtemp;

	dirxtemp = data->pos.dir_camX;
	normxtemp = data->pos.norm_camX;
	data->pos.dir_camX = data->pos.dir_camX * cos(ROT_SPEED)
		- data->pos.dir_camY * sin(ROT_SPEED);
	data->pos.dir_camY = dirxtemp * sin(ROT_SPEED)
		+ data->pos.dir_camY * cos(ROT_SPEED);
	data->pos.norm_camX = data->pos.norm_camX * cos(ROT_SPEED)
		- data->pos.norm_camY * sin(ROT_SPEED);
	data->pos.norm_camY = normxtemp * sin(ROT_SPEED)
		+ data->pos.norm_camY * cos(ROT_SPEED);
}

void	ft_rotation_right(t_data *data)
{
	double	dirxtemp;
	double	normxtemp;

	dirxtemp = data->pos.dir_camX;
	normxtemp = data->pos.norm_camX;
	data->pos.dir_camX = data->pos.dir_camX * cos(-ROT_SPEED)
		- data->pos.dir_camY * sin(-ROT_SPEED);
	data->pos.dir_camY = dirxtemp * sin(-ROT_SPEED)
		+ data->pos.dir_camY * cos(-ROT_SPEED);
	data->pos.norm_camX = data->pos.norm_camX * cos(-ROT_SPEED)
		- data->pos.norm_camY * sin(-ROT_SPEED);
	data->pos.norm_camY = normxtemp * sin(-ROT_SPEED)
		+ data->pos.norm_camY * cos(-ROT_SPEED);
}
