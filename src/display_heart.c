/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_heart.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:49:41 by ozone             #+#    #+#             */
/*   Updated: 2024/04/04 20:01:44 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	display_heart(t_data *data)
{
	int	x;
	int	y;
	int	x_spr;
	int	y_spr;
	
	data->j = 2;
	data->pv_cpy = data->pv;
	//mlx_put_image_to_window(data->mlx, data->win, data->textures.heart_empty.img_ptr, 0, 0);
	while (--data->j > 0)
	{
		y = (WIN_Y - 128) - 1;
		y_spr = -1;
		while ((++y, ++y_spr) < WIN_Y)
		{
			x = 0;
			x_spr = -1;
			while (x < (128 * (FULLIFE - data->j)) - 128)
				x++;
			while (x && ++x_spr < 128 * (FULLIFE - data->j))
			{
				printf("pos_x %i, pos_x_spr %i, pos_y %i, pos_y_spr %i\n", x, x_spr, y, y_spr);
				if (data->pv_cpy > 0)
				{
					if (take_pix(&data->textures.heart_full,
						x_spr / 2, y_spr / 2) != 0x000000)
					{
						img_pixel_put(&data->img_win, x, y,
							take_pix(&data->textures.heart_full, x_spr / 2, y_spr / 2));
					}
				}
				else
				{
					if (take_pix(&data->textures.heart_empty,
						x_spr / 2, y_spr / 2) != 0x000000)
					{
						img_pixel_put(&data->img_win, x, y,
							take_pix(&data->textures.heart_empty, x_spr / 2, y_spr / 2));
					}
				}
				data->pv_cpy--;
				x++;
			}
		}
	}
}

// void	show_pov2(t_data *data)
// {
// 	if (data->textures.add_POV == 0)
// 		data->textures.way_POV = 1;
// 	else if (data->textures.add_POV == 40)
// 		data->textures.way_POV = 0;
// 	if (data->textures.way_POV == 1)
// 		data->textures.add_POV++;
// 	else if (data->textures.way_POV == 0)
// 		data->textures.add_POV--;
// 	if (data->textures.tex_POV > 20)
// 		data->textures.tex_POV = 0;
// 	else if (data->textures.tex_POV > 0)
// 		data->textures.tex_POV++;
// }

// void	show_pov(t_data *data)
// {
// 	int	x;
// 	int	y;
// 	int	x_spr;
// 	int	y_spr;

// 	y = ((WIN_Y - 192) + (data->textures.add_POV / 4)) - 1;
// 	y_spr = -1;
// 	while ((++y_spr, ++y) < WIN_Y)
// 	{
// 		x = ((WIN_X / 2) - 96) - 1;
// 		x_spr = -1;
// 		while ((++x_spr, ++x) < (WIN_X / 2) + 96)
// 		{
// 			if (data->textures.tex_POV == 0 && take_pix(&data->textures.POV,
// 					x_spr / 3, y_spr / 3) != 0x000000)
// 				img_pixel_put(&data->img_win, x, y,
// 					take_pix(&data->textures.POV, x_spr / 3, y_spr / 3));
// 			else if (data->textures.tex_POV > 0
// 				&& take_pix(&data->textures.shoot_POV, x_spr / 3, y_spr / 3)
// 				!= 0x000000)
// 				img_pixel_put(&data->img_win, x, y,
// 					take_pix(&data->textures.shoot_POV, x_spr / 3, y_spr / 3));
// 		}
// 	}
// 	show_pov2(data);
// }
