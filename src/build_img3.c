/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_img3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:45:54 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/06 17:56:02 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	door_check(t_data *data, t_algo *algo)
{
	if (data->map[algo->map_posY][algo->map_posX] == 'D')
	{
		if (algo->side == 0 && algo->dist_temp_rayY > algo->dist_temp_rayX - (algo->delta_distX * 0.5))
		{
			algo->texture = 4;
			algo->dist_temp_rayX += (algo->delta_distX * 0.5);
			return (1);
		}
		else if (algo->side == 1 && algo->dist_temp_rayX > algo->dist_temp_rayY - (algo->delta_distY * 0.5))
		{
			algo->texture = 4;
			algo->dist_temp_rayY += (algo->delta_distY * 0.5);
			return (1);
		}
	}
	return (0);
}

void	draw_crossair(t_data *data)
{
	img_pixel_put(&data->img_win, (WIN_X / 2), (WIN_Y / 2) - 3, 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2), (WIN_Y / 2) - 2, 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2), (WIN_Y / 2) - 1, 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2) - 1, (WIN_Y / 2), 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2) - 2, (WIN_Y / 2), 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2) - 3, (WIN_Y / 2), 0xffffff);
	img_pixel_put(&data->img_win, WIN_X / 2, WIN_Y / 2, 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2), (WIN_Y / 2) + 3, 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2), (WIN_Y / 2) + 2, 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2), (WIN_Y / 2) + 1, 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2) + 1, (WIN_Y / 2), 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2) + 2, (WIN_Y / 2), 0xffffff);
	img_pixel_put(&data->img_win, (WIN_X / 2) + 3, (WIN_Y / 2), 0xffffff);
}
