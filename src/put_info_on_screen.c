/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info_on_screen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:11:58 by ozone             #+#    #+#             */
/*   Updated: 2024/04/16 14:58:43 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	put_info_on_screen(t_data *data)
{
	char	*str;

	data->info.fov = (int)((atan(sqrt(sqr(data->pos.norm_camX) + sqr
						(data->pos.norm_camY)) / sqrt(sqr(data->pos.dir_camX)
						+ sqr(data->pos.dir_camY))) * 2) * 180 / 3.14);
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
	show_pov(data);
	display_heart(data);
}
