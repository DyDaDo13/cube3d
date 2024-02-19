/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:36:29 by ozone             #+#    #+#             */
/*   Updated: 2024/02/19 10:24:55 by ozone            ###   ########.fr       */
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
	else if (key == XK_w)
		ft_move(data, 0);
	else if (key == XK_s)
		ft_move(data, 1);
	else if (key == XK_d)
		ft_move(data, 2);
	else if (key == XK_a)
		ft_move(data, 3);
	else if (key == XK_Left)
		ft_rotation_right(data);
	else if (key == XK_Right)
		ft_rotation_left(data);
	//printf("dirx : %f | dirY : %f\n", data->pos.dir_camX, data->pos.dir_camY);	
	build_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_win.img_ptr, 0, 0);
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
	ft_init_img(data);
	mlx_mouse_hide(data->mlx, data->win);
	build_img(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_win.img_ptr, 0, 0);
	mlx_hook(data->win, 3, (1L << 0) + (1L << 1), ft_key_check, data);
	mlx_hook(data->win, 17, 0L, ft_stop, data);
	mlx_loop(data->mlx);
	return (0);
}