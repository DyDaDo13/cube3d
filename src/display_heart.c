/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_heart.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:49:41 by ozone             #+#    #+#             */
/*   Updated: 2024/04/16 14:42:36 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	display_heart_loop(t_data *data, t_point *var)
{
	var->x = var->d - 1;
	var->i = -1;
	while ((++var->i, ++var->x) < 64 * ((FULLIFE - data->j) + 1))
	{
		if (data->pv_cpy > 0)
		{
			if (take_pix(&data->textures.heart_full,
					var->i, var->j) != 0x000000)
			{
				img_pixel_put(&data->img_win, var->x, var->y,
					take_pix(&data->textures.heart_full, var->i, var->j));
			}
		}
		else
		{
			if (take_pix(&data->textures.heart_empty,
					var->i, var->j) != 0x000000)
			{
				img_pixel_put(&data->img_win, var->x, var->y,
					take_pix(&data->textures.heart_empty, var->i, var->j));
			}
		}
	}
}

/*var.y & x = y & x | var.i & j = x_spr & y_spr | var.d = add*/
void	display_heart(t_data *data)
{
	t_point	var;

	data->j = FULLIFE + 1;
	data->pv_cpy = data->pv;
	var.d = 0;
	while (--data->j > 0)
	{
		var.y = (WIN_Y - 64) - 1;
		var.j = -1;
		while ((++var.j, ++var.y) < WIN_Y)
			display_heart_loop(data, &var);
		var.d += 64;
		data->pv_cpy--;
	}
}
