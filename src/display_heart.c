/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_heart.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:49:41 by ozone             #+#    #+#             */
/*   Updated: 2024/04/04 20:27:19 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	display_heart(t_data *data)
{
	int	x;
	int	y;
	int	x_spr;
	int	y_spr;
	int	add;
	
	data->j = FULLIFE + 1;
	data->pv_cpy = data->pv;
	add = 0;
	while (--data->j > 0)
	{
		y = (WIN_Y - 64) - 1;
		y_spr = -1;
		while ((++y_spr, ++y) < WIN_Y)
		{
			x = add - 1;
			x_spr = -1;
			while ((++x_spr, ++x) < 64 * ((FULLIFE - data->j) + 1))
			{
				if (data->pv_cpy > 0)
				{
					if (take_pix(&data->textures.heart_full,
						x_spr, y_spr) != 0x000000)
					{
						img_pixel_put(&data->img_win, x, y,
							take_pix(&data->textures.heart_full, x_spr, y_spr));
					}
				}
				else
				{
					if (take_pix(&data->textures.heart_empty,
						x_spr, y_spr) != 0x000000)
					{
						img_pixel_put(&data->img_win, x, y,
							take_pix(&data->textures.heart_empty, x_spr, y_spr));
					}
				}
			}
		}
		add += 64;
		data->pv_cpy--;
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
