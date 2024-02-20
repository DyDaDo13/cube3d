/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:36:29 by ozone             #+#    #+#             */
/*   Updated: 2024/02/20 17:36:01 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

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
	//printf("key = %i\n", data->key_move);
	return (0);
}

int	set_mouse_center_screen(t_data *data)
{
	data->mouse.origin_x = (WIN_X / 2);
	data->mouse.origin_y = (WIN_Y / 2);
	mlx_mouse_move(data->mlx, data->win, data->mouse.origin_x, data->mouse.origin_y);
	return (0);
}

int	sprint_off(int key, t_data *data)
{
	if (key == XK_Shift_L)
	{
		if (data->move_speed != MOVE_SPEED)
			data->move_speed = MOVE_SPEED;
	}
	else if (key == XK_w)
		data->key_move -= 1;
	else if (key == XK_s)
		data->key_move -= 2;
	else if (key == XK_d)
		data->key_move -= 4;
	else if (key == XK_a)
		data->key_move -= 7;
	else if (key == XK_Left)
		data->key_move -= 100;
	else if (key == XK_Right)
		data->key_move -= 200;
	return (0);
}

void	move_diag(t_data *data)
{
	if (data->key_move == 5)
	{
		ft_move(data, 0);
		ft_move(data, 2);
	}
	else if (data->key_move == 8)
	{
		ft_move(data, 0);
		ft_move(data, 3);
	}
	else if (data->key_move == 6)
	{
		ft_move(data, 1);
		ft_move(data, 2);
	}
	else if (data->key_move == 9)
	{
		ft_move(data, 1);
		ft_move(data, 3);
	}
}

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
	check_door_spot(data);
	build_img(data);
	return (0);
}

int	ft_display(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (perror("Error"), 1);
	data->win = mlx_new_window(data->mlx, WIN_X, WIN_Y, "Mon Q");
	if (data->win == NULL)
		return (mlx_destroy_display(data->mlx), free(data->mlx), 1);
	data->key_move = 0;
	ft_init_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_win.img_ptr, 0, 0);
	mlx_loop_hook(data->mlx, ft_key_moves, data);
	mlx_hook(data->win, 6, (1L << 6), mouse_move, data);
	mlx_hook(data->win, 2, (1L << 0), ft_key_check, data);
	mlx_hook(data->win, 3, (1L << 1), sprint_off, data);
	mlx_hook(data->win, 17, 0L, ft_stop, data);
	mlx_loop(data->mlx);
	return (0);
}
