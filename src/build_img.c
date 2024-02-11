/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:16:32 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/08 18:22:26 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	draw_pix(t_data *data, int line_to_draw, int side, int x)
{
	int	start;
	int	end;
	int	i;
	int	color;

	start = -line_to_draw / 2 + WIN_Y / 2;
	if (start < 0)
		start = 0;
	end = line_to_draw / 2 + WIN_Y / 2;
	if (end >= WIN_Y)
		end = WIN_Y - 1;
	i = 0;
	if (side == 0)
		color = 0xff0000;
	else
		color = 0xff0000 / 2;
	while (i < WIN_Y)
	{
		if (i <= start)
			img_pixel_put(&data->img_win, x, i, data->textures_path.C);
		else if (i > start && i <= end)
			img_pixel_put(&data->img_win, x, i, color);
		else
			img_pixel_put(&data->img_win, x, i, data->textures_path.F);
		i++;
	}
}

void	get_steps(int *stepX, int *stepY, t_algo *algo, t_data *data)
{
	if (algo->rayDir_actX < 0)
	{
		*stepX = -1;
		algo->dist_temp_rayX = (data->pos.p_x - algo->map_posX) *
			algo->delta_distX;
	}
	else
	{
		*stepX = 1;
		algo->dist_temp_rayX = ((algo->map_posX + 1.0) - data->pos.p_x) *
			algo->delta_distX;
	}
	if (algo->rayDir_actY < 0)
	{
		*stepY = -1;
		algo->dist_temp_rayY = (data->pos.p_y - algo->map_posY) *
			algo->delta_distY;
	}
	else
	{
		*stepY = 1;
		algo->dist_temp_rayY = ((algo->map_posY + 1.0) - data->pos.p_y) *
			algo->delta_distY;
	}
}

void	algo_DDA(t_algo *algo, t_data *data, double *wall_dist, int *side)
{
	int	stepX;
	int	stepY;

	get_steps(&stepX, &stepY, algo, data);
	//printf("deltaX : %f | deltaY : %f\n", algo->rayDir_actX, algo->rayDir_actY);
	//printf("stepX : %d | stepY : %d\n", stepX, stepY);
	while (data->map[algo->map_posY][algo->map_posX] != '1')
	{
		if (algo->dist_temp_rayX < algo->dist_temp_rayY)
		{
			algo->map_posX += stepX;
			*side = 0;
			algo->dist_temp_rayX += algo->delta_distX;
		}
		else
		{
			algo->map_posY += stepY;
			*side = 1;
			algo->dist_temp_rayY += algo->delta_distY;
		}
	}
	if (*side == 0)
		*wall_dist = algo->dist_temp_rayX /*- algo->delta_distX*/;
	else
		*wall_dist = algo->dist_temp_rayY /*- algo->delta_distY*/;
	//printf("walldist = %f\n", *wall_dist);
}

void	ft_calc_delta(t_algo *algo)
{
	if (algo->rayDir_actX == 0)
	{
		algo->delta_distX = sqrt(1 + ((algo->rayDir_actY * algo->rayDir_actY) /
				1e30));
	}
	else
		algo->delta_distX = sqrt(1 + ((algo->rayDir_actY * algo->rayDir_actY) /
				(algo->rayDir_actX * algo->rayDir_actX)));
	if (algo->rayDir_actY == 0)
	{
		algo->delta_distY = sqrt(((algo->rayDir_actX * algo->rayDir_actX) /
			1e30) + 1);
	}
	else
		algo->delta_distY = sqrt(((algo->rayDir_actX * algo->rayDir_actX) /
			(algo->rayDir_actY * algo->rayDir_actY)) + 1);
}

void	build_img(t_data *data)
{
	int			x;
	double		wall_dist;
	int			side;
	t_algo		algo;

	x = 0;
	side = 0;
	while (x < WIN_X)
	{
		algo.Coef_CamX = ((2 * x) / (double)WIN_X) - 1;
		algo.rayDir_actX = data->pos.dir_camX +
			(data->pos.norm_camX * algo.Coef_CamX);
		algo.rayDir_actY = data->pos.dir_camY +
			(data->pos.norm_camX * algo.Coef_CamX);
		//printf("deltaX : %f | deltaY : %f -> %d\n", algo.rayDir_actX, algo.rayDir_actY, x);
		algo.map_posX = (int)(data->pos.p_x);
		algo.map_posY = (int)(data->pos.p_y);
		ft_calc_delta(&algo);
		algo_DDA(&algo, data, &wall_dist, &side);
		draw_pix(data, WIN_Y / wall_dist, side, x);
		x++;
	}
}
