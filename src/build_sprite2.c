/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_sprite2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:16:39 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/06 19:22:21 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	act_text(t_data *data, t_algo *spr)
{
	if (data->enemy[spr->start].texture >= 0)
	{
		if (data->enemy[spr->start].act_text > TIME_ACT_TEXT)
		{
			data->enemy[spr->start].act_text = 0;
			data->enemy[spr->start].texture++;
			if (data->enemy[spr->start].texture >= NB_TEXT_SPRITE)
				data->enemy[spr->start].texture = 0;
		}
		else
			data->enemy[spr->start].act_text++;
	}
	else
	{
		if (data->enemy[spr->start].act_text > TIME_ACT_TEXT)
		{
			data->enemy[spr->start].x = (double)-1;
			data->enemy[spr->start].y = (double)-1;
		}
		else
			data->enemy[spr->start].act_text++;
	}
}

t_img	*sel_tex_spr(t_data *data, int tex)
{
	if (tex == 0)
		return (&data->textures.enemy1);
	else
		return (&data->textures.enemy_death);
}

void	draw_sprite(t_data *data, t_point *draw, t_algo *spr, double *dis_wall)
{
	int	Xdraw;
	int	Ydraw;
	int	texX;
	int	texY;
	int	dis;

	Xdraw = draw->x;
	while (Xdraw < draw->j)
	{
		texX = (int)(256 * (Xdraw - (-spr->side / 2 + spr->end)) * TEXT_SIZE / spr->side) / 256;
		if (spr->dist_temp_rayY > 0 && Xdraw > 0 && Xdraw < WIN_X && spr->dist_temp_rayY < dis_wall[Xdraw])
		{
			Ydraw = draw->y;
			while (Ydraw < draw->i)
			{
				dis = (Ydraw) * 256 - WIN_Y * 128 + spr->side * 128;
				texY = ((dis * TEXT_SIZE) / spr->side) / 256;
				if (take_pix(sel_tex_spr(data, data->enemy[spr->start].texture), texX, texY) != 0x000000)
					img_pixel_put(&data->img_win, Xdraw, Ydraw, take_pix(sel_tex_spr(data, data->enemy[spr->start].texture), texX, texY));
				Ydraw++;
			}
		}
		Xdraw++;
	}
}

int	get_nb_sprite(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < data->nb_enemy)
	{
		//printf("salut : %d\n", i);
		if (data->enemy[i].x >= (double)0 && data->enemy[i].y >= (double)0)
			count++;
		i++;
	}
	return (count);
}

int	sort_sprite2(t_data *data, int **order, double **dis)
{
	int	index;
	int	i;

	i = -1;
	index = 0;
	while (++i < data->nb_enemy)
	{
		if (data->enemy[i].x >= 0 && data->enemy[i].y >= 0)
		{
			(*order)[index] = i;
			(*dis)[index] = (sqr(data->pos.p_x - data->enemy[i].x)
				+ sqr(data->pos.p_y - data->enemy[i].y));
			index++;
		}
	}
	return (index);
}
