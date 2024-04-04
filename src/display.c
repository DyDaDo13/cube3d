/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:36:29 by ozone             #+#    #+#             */
/*   Updated: 2024/04/04 17:04:40 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

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
	else if (key == XK_space)
		data->mouse.mouse_lock *= -1;
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
	data->mouse.mouse_lock = 1;
	ft_init_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_win.img_ptr, 0, 0);
	put_info_on_screen(data);
	mlx_loop_hook(data->mlx, ft_key_moves, data);
	mlx_hook(data->win, 6, (1L << 6), mouse_move, data);
	mlx_hook(data->win, 4, (1L << 2), &mouse_left_click, data);
	mlx_hook(data->win, 2, (1L << 0), ft_key_check, data);
	mlx_hook(data->win, 3, (1L << 1), sprint_off, data);
	mlx_hook(data->win, 17, 0L, ft_stop, data);
	mlx_loop(data->mlx);
	return (0);
}
