/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info_on_screen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:11:58 by ozone             #+#    #+#             */
/*   Updated: 2024/04/23 16:42:31 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	show_fps(t_data *data)
{
	char	*str;

	mlx_string_put(data->mlx, data->win, WIN_X - 65, 80, 0x000000,
		"FPS : ");
	str = ft_itoa(data->info.temp);
	if ((int)data->info.temp < 30)
		mlx_string_put(data->mlx, data->win, WIN_X - 30, 80, 0x00ff00, str);
	else if ((int)data->info.temp < 60)
		mlx_string_put(data->mlx, data->win, WIN_X - 30, 80, 0xff9900, str);
	else if ((int)data->info.temp > 60)
		mlx_string_put(data->mlx, data->win, WIN_X - 30, 80, 0xff0000, str);
	free(str);
}

void	put_info_on_screen(t_data *data)
{
	char	*str;

	data->info.fov = (int)((atan(sqrt(sqr(data->pos.norm_camx) + sqr
						(data->pos.norm_camy)) / sqrt(sqr(data->pos.dir_camx)
						+ sqr(data->pos.dir_camy))) * 2) * 180 / 3.14);
	data->info.sensivity = SENSIVITY;
	data->info.speed = MOVE_SPEED * 100;
	str = ft_itoa(data->info.fov);
	mlx_string_put(data->mlx, data->win, WIN_X - 65, 20, 0x000000, "FOV : ");
	mlx_string_put(data->mlx, data->win, WIN_X - 30, 20, 0x0000ff, str);
	free(str);
	str = ft_itoa(data->info.speed);
	mlx_string_put(data->mlx, data->win, WIN_X - 77, 40, 0x000000, "SPEED : ");
	mlx_string_put(data->mlx, data->win, WIN_X - 30, 40, 0x0000ff, str);
	free(str);
	str = ft_itoa(data->info.sensivity);
	mlx_string_put(data->mlx, data->win, WIN_X - 101, 60, 0x000000,
		"SENSIVITY : ");
	mlx_string_put(data->mlx, data->win, WIN_X - 30, 60, 0x0000ff, str);
	free(str);
	show_fps(data);
}
