/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:41:51 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/17 15:41:51 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

float	interpolate(float c1, float c2, float pourcent)
{
	return (c1 + (c2 - c1) * pourcent);
}

unsigned int	ft_mix_color(int color1, int color2, float pourcent)
{
	t_point			RGB_1;
	t_point			RGB_2;
	t_point			RGB_final;
	unsigned int	res;

	RGB_1.i = (color1 >> 16) & 0xFF;
	RGB_1.x = (color1 >> 8) & 0xFF;
	RGB_1.y = color1 & 0xFF;
	RGB_2.i = (color2 >> 16) & 0xFF;
	RGB_2.x = (color2 >> 8) & 0xFF;
	RGB_2.y = color2 & 0xFF;
	RGB_final.i = (int)interpolate(RGB_1.i, RGB_2.i, pourcent);
	RGB_final.x = (int)interpolate(RGB_1.x, RGB_2.x, pourcent);
	RGB_final.y = (int)interpolate(RGB_1.y, RGB_2.y, pourcent);
	res = (RGB_final.i << 16) | (RGB_final.x << 8) | RGB_final.y;
	return (res);
}

void	show_map2(t_data *data, int x, int y, t_pos *pos_map)
{
	int	middle;

	middle = ((MINI_MAP_SIZE * MINI_MAP_COEF_LEN) / 2) + 20;
	if (x < 20 + 5 || x >= 20 + ((MINI_MAP_SIZE * MINI_MAP_COEF_LEN) - 5))
		img_pixel_put(&data->img_win, x, y, ft_mix_color(take_pix
			(&data->img_win, x, y), 0x433D37, 0.5));
	else if (y < 20 + 5 || y >= 20 + ((MINI_MAP_SIZE * MINI_MAP_COEF_LEN) - 5))
		img_pixel_put(&data->img_win, x, y, ft_mix_color(take_pix
			(&data->img_win, x, y), 0x433D37, 0.5));
	else
	{
		if (x >= middle - 5 && y >= middle - 5 && x < middle + 5 && y <
		middle + 5)
			img_pixel_put(&data->img_win, x, y, 0xFA5D00);
		else if ((pos_map->p_x >= 0 && pos_map->p_y >= 0) &&
			(pos_map->p_x < data->map_lenX && pos_map->p_y < data->map_lenY)
			&& data->map[(int)pos_map->p_y][(int)pos_map->p_x] == '1')
			img_pixel_put(&data->img_win, x, y, ft_mix_color(take_pix
				(&data->img_win, x, y), 0xF03A1A, 0.5));
		else
			img_pixel_put(&data->img_win, x, y, ft_mix_color(take_pix
				(&data->img_win, x, y), 0xC3C0BD, 0.5));
		pos_map->p_x += pos_map->angle;
	}
}

void	draw_FOV(t_data *data)
{
	t_point	dis;
	t_pos	start;

	start.p_x = (double)((MINI_MAP_SIZE * MINI_MAP_COEF_LEN) / 2) + 20.0;
	start.p_y = (double)((MINI_MAP_SIZE * MINI_MAP_COEF_LEN) / 2) + 20.0;
	dis.x = (((((MINI_MAP_SIZE * MINI_MAP_COEF_LEN) / 2) + 20)
		+ (data->pos.dir_camX * 1)) + (data->pos.norm_camX * 1)) - start.p_x;
	dis.y = (((((MINI_MAP_SIZE * MINI_MAP_COEF_LEN) / 2) + 20)
		+ (data->pos.dir_camY * 1)) + (data->pos.norm_camY * 1)) - start.p_y;
	change_dis(&dis, start, data, 0);
	trace_line(&data->img_win, start, dis, 0xFA5D00);
	dis.x = (((((MINI_MAP_SIZE * MINI_MAP_COEF_LEN) / 2) + 20)
		+ (data->pos.dir_camX * 1)) - (data->pos.norm_camX * 1)) - start.p_x;
	dis.y = (((((MINI_MAP_SIZE * MINI_MAP_COEF_LEN) / 2) + 20)
		+ (data->pos.dir_camY * 1)) - (data->pos.norm_camY * 1)) - start.p_y;
	change_dis(&dis, start, data, 1);
	trace_line(&data->img_win, start, dis, 0xFA5D00);
}

/*pos_map.angle = step*/
void	show_map(t_data *data)
{
	int		x;
	int		y;
	double	Xstart;
	t_pos	pos_map;

	y = 20;
	Xstart = data->pos.p_x - (double)((MINI_MAP_COEF_LEN / 2) - 1) - 0.7;
	pos_map.p_y = data->pos.p_y - (double)((MINI_MAP_COEF_LEN / 2) - 1) - 0.7;
	pos_map.angle = (double)1 / (double)MINI_MAP_SIZE;
	while (y < (MINI_MAP_SIZE * MINI_MAP_COEF_LEN) + 20)
	{
		x = 20;
		pos_map.p_x = Xstart;
		while (x < (MINI_MAP_SIZE * MINI_MAP_COEF_LEN) + 20)
		{
			show_map2(data, x, y, &pos_map);
			x++;
		}
		if (y >= 20 + 5 && y < 20 + ((MINI_MAP_SIZE * MINI_MAP_COEF_LEN) - 5))
			pos_map.p_y += pos_map.angle;
		y++;
	}
	draw_FOV(data);
}

