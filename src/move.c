/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylmarti <dylmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:44:24 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/25 08:41:25 by dylmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	ft_move2(t_data *data, int dir)
{
	double	coef;

	coef = 1.0;
	if (sqrt(sqr(data->pos.norm_camx) + sqr(data->pos.norm_camy)) != 1.0)
		coef = 1 / sqrt(sqr(data->pos.norm_camx) + sqr(data->pos.norm_camy));
	if (dir == 2)
	{
		if (check_move(data->map, (data->pos.p_y + ((data->pos.norm_camy * coef)
					* data->move_speed)), data->pos.p_x) == 1)
			data->pos.p_y += (data->pos.norm_camy * coef) * data->move_speed;
		if (check_move(data->map, data->pos.p_y, (data->pos.p_x +
				((data->pos.norm_camx * coef) * data->move_speed))) == 1)
			data->pos.p_x += (data->pos.norm_camx * coef) * data->move_speed;
	}
	else if (dir == 3)
	{
		if (check_move(data->map, (data->pos.p_y - ((data->pos.norm_camy * coef)
					* data->move_speed)), data->pos.p_x) == 1)
			data->pos.p_y -= (data->pos.norm_camy * coef) * data->move_speed;
		if (check_move(data->map, data->pos.p_y, (data->pos.p_x -
				((data->pos.norm_camx * coef) * data->move_speed))) == 1)
			data->pos.p_x -= (data->pos.norm_camx * coef) * data->move_speed;
	}
}

void	ft_move(t_data *data, int dir)
{
	if (dir == 0)
	{
		if (check_move(data->map, (data->pos.p_y + (data->pos.dir_camy
					* data->move_speed)), data->pos.p_x) == 1)
			data->pos.p_y += data->pos.dir_camy * data->move_speed;
		if (check_move(data->map, data->pos.p_y, (data->pos.p_x +
				(data->pos.dir_camx * data->move_speed))) == 1)
			data->pos.p_x += data->pos.dir_camx * data->move_speed;
	}
	else if (dir == 1)
	{
		if (check_move(data->map, (data->pos.p_y - (data->pos.dir_camy
					* data->move_speed)), data->pos.p_x) == 1)
			data->pos.p_y -= data->pos.dir_camy * data->move_speed;
		if (check_move(data->map, data->pos.p_y, (data->pos.p_x -
				(data->pos.dir_camx * data->move_speed))) == 1)
			data->pos.p_x -= data->pos.dir_camx * data->move_speed;
	}
	else
		ft_move2(data, dir);
}

void	ft_rotation(t_data *data, double rot_coef)
{
	double	dirxtemp;
	double	normxtemp;

	dirxtemp = data->pos.dir_camx;
	normxtemp = data->pos.norm_camx;
	data->pos.dir_camx = data->pos.dir_camx * cos(rot_coef)
		- data->pos.dir_camy * sin(rot_coef);
	data->pos.dir_camy = dirxtemp * sin(rot_coef)
		+ data->pos.dir_camy * cos(rot_coef);
	data->pos.norm_camx = data->pos.norm_camx * cos(rot_coef)
		- data->pos.norm_camy * sin(rot_coef);
	data->pos.norm_camy = normxtemp * sin(rot_coef)
		+ data->pos.norm_camy * cos(rot_coef);
}

void	ft_rotation_left(t_data *data)
{
	double	dirxtemp;
	double	normxtemp;

	dirxtemp = data->pos.dir_camx;
	normxtemp = data->pos.norm_camx;
	data->pos.dir_camx = data->pos.dir_camx * cos(ROT_SPEED)
		- data->pos.dir_camy * sin(ROT_SPEED);
	data->pos.dir_camy = dirxtemp * sin(ROT_SPEED)
		+ data->pos.dir_camy * cos(ROT_SPEED);
	data->pos.norm_camx = data->pos.norm_camx * cos(ROT_SPEED)
		- data->pos.norm_camy * sin(ROT_SPEED);
	data->pos.norm_camy = normxtemp * sin(ROT_SPEED)
		+ data->pos.norm_camy * cos(ROT_SPEED);
}

void	ft_rotation_right(t_data *data)
{
	double	dirxtemp;
	double	normxtemp;

	dirxtemp = data->pos.dir_camx;
	normxtemp = data->pos.norm_camx;
	data->pos.dir_camx = data->pos.dir_camx * cos(-ROT_SPEED)
		- data->pos.dir_camy * sin(-ROT_SPEED);
	data->pos.dir_camy = dirxtemp * sin(-ROT_SPEED)
		+ data->pos.dir_camy * cos(-ROT_SPEED);
	data->pos.norm_camx = data->pos.norm_camx * cos(-ROT_SPEED)
		- data->pos.norm_camy * sin(-ROT_SPEED);
	data->pos.norm_camy = normxtemp * sin(-ROT_SPEED)
		+ data->pos.norm_camy * cos(-ROT_SPEED);
}
