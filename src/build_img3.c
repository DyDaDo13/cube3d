/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_img3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:45:54 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/04 17:25:48 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	door_check(t_data *data, t_algo *algo)
{
	if (data->map[algo->map_posY][algo->map_posX] == 'D')
	{
		if (algo->side == 0 && algo->dist_temp_rayY > algo->dist_temp_rayX
			- (algo->delta_distX * 0.5))
		{
			algo->texture = 4;
			algo->dist_temp_rayX += (algo->delta_distX * 0.5);
			return (1);
		}
		else if (algo->side == 1 && algo->dist_temp_rayX > algo->dist_temp_rayY
			- (algo->delta_distY * 0.5))
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

void	show_pov2(t_data *data)
{
	if (data->textures.add_POV == 0)
		data->textures.way_POV = 1;
	else if (data->textures.add_POV == 40)
		data->textures.way_POV = 0;
	if (data->textures.way_POV == 1)
		data->textures.add_POV++;
	else if (data->textures.way_POV == 0)
		data->textures.add_POV--;
	if (data->textures.tex_POV > 20)
		data->textures.tex_POV = 0;
	else if (data->textures.tex_POV > 0)
		data->textures.tex_POV++;
	put_info_on_screen(data);
}

void	show_pov(t_data *data)
{
	int	x;
	int	y;
	int	x_spr;
	int	y_spr;

	y = ((WIN_Y - 192) + (data->textures.add_POV / 4)) - 1;
	y_spr = -1;
	while ((++y_spr, ++y) < WIN_Y)
	{
		x = ((WIN_X / 2) - 96) - 1;
		x_spr = -1;
		while ((++x_spr, ++x) < (WIN_X / 2) + 96)
		{
			if (data->textures.tex_POV == 0 && take_pix(&data->textures.POV,
					x_spr / 3, y_spr / 3) != 0x000000)
				img_pixel_put(&data->img_win, x, y,
					take_pix(&data->textures.POV, x_spr / 3, y_spr / 3));
			else if (data->textures.tex_POV > 0
				&& take_pix(&data->textures.shoot_POV, x_spr / 3, y_spr / 3)
				!= 0x000000)
				img_pixel_put(&data->img_win, x, y,
					take_pix(&data->textures.shoot_POV, x_spr / 3, y_spr / 3));
		}
	}
	show_pov2(data);
}
