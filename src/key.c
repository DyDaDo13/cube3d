/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:45:41 by ozone             #+#    #+#             */
/*   Updated: 2024/04/04 18:41:29 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	replace_before_door(t_data *data)
{
	int		x;
	int		y;

	y = -1;	
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
			if (data->map[y][x] == 'O')
				data->map[y][x] = 'D';
	}
}

void	check_door_spot(t_data *data)
{
	if (data->map[(int)data->pos.p_y][(int)data->pos.p_x] == 'D' && data->door == 0)
	{
		data->map[(int)data->pos.p_y][(int)data->pos.p_x] = 'O';
		data->door = 1;
	}
	if (data->map[(int)data->pos.p_y][(int)data->pos.p_x] != 'O' && data->door == 1)
	{
		replace_before_door(data);
		data->door = 0;
	}
}

void	key_move(int key, t_data *data)
{
	if (key == XK_w)
		data->key_move += 1;
	else if (key == XK_s)
		data->key_move += 2;
	else if (key == XK_d)
		data->key_move += 4;
	else if (key == XK_a)
		data->key_move += 7;
	else if (key == XK_Left)
		data->key_move += 100;
	else if (key == XK_Right)
		data->key_move += 200;
	else if (key == XK_Shift_L)
		if (data->move_speed == MOVE_SPEED)
			data->move_speed *= 2;
}

int	ft_key_check(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_stop(data);
	if (key == 61)
	{
		data->pos.norm_camX = data->pos.norm_camX * 0.99;
		data->pos.norm_camY = data->pos.norm_camY * 0.99;
	}
	if (key == 45)
	{
		data->pos.norm_camX = data->pos.norm_camX * 1.01;
		data->pos.norm_camY = data->pos.norm_camY * 1.01;
	}
	key_move(key, data);
	return (0);
}

int	ft_key_moves(t_data *data)
{
	if (data->key_move == 1)
		ft_move(data, 0);
	else if (data->key_move == 2)
		ft_move(data, 1);
	else if (data->key_move == 4)
		ft_move(data, 2);
	else if (data->key_move == 7)
		ft_move(data, 3);
	else if (data->key_move == 100)
		ft_rotation_right(data);
	else if (data->key_move == 200)
		ft_rotation_left(data);
	else
		move_diag(data);
	if (data->hardmode == 1)
		enemy_move(data);
	check_door_spot(data);
	build_img(data);
	put_info_on_screen(data);
	return (0);
}
