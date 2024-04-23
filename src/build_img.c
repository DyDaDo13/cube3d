/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:16:32 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/23 13:07:52 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	draw_pix(t_data *data, t_algo *algo, int line_to_draw, int x)
{
	int	i;

	algo->start = -line_to_draw / 2 + WIN_Y / 2;
	if (algo->start < 0)
		algo->start = 0;
	algo->end = line_to_draw / 2 + WIN_Y / 2;
	if (algo->end >= WIN_Y)
		algo->end = WIN_Y - 1;
	i = 0;
	algo->x = x;
	while (i < WIN_Y)
	{
		if (i < algo->start)
			img_pixel_put(&data->img_win, x, i, ft_mix_color(
					data->textures_path.c, 0x000000, (double)i
					/ (double)(WIN_Y / 2)));
		else if (i > algo->start && i <= algo->end)
			pix_texture(data, algo, &i);
		else
			img_pixel_put(&data->img_win, x, i, ft_mix_color(
					data->textures_path.f, 0x000000, ((double)i
						/ (double)(WIN_Y / 2)) - 2.0));
		i++;
	}
}

void	get_steps(int *stepX, int *stepY, t_algo *algo, t_data *data)
{
	if (algo->raydir_actx < 0)
	{
		*stepX = -1;
		algo->dist_temp_rayx = (data->pos.p_x - algo->map_posx)
			* algo->delta_distx;
	}
	else
	{
		*stepX = 1;
		algo->dist_temp_rayx = ((algo->map_posx + 1.0) - data->pos.p_x)
			* algo->delta_distx;
	}
	if (algo->raydir_acty < 0)
	{
		*stepY = -1;
		algo->dist_temp_rayy = (data->pos.p_y - algo->map_posy)
			* algo->delta_disty;
	}
	else
	{
		*stepY = 1;
		algo->dist_temp_rayy = ((algo->map_posy + 1.0) - data->pos.p_y)
			* algo->delta_disty;
	}
}

void	algo_dda(t_algo *algo, t_data *data)
{
	int	stepx;
	int	stepy;

	get_steps(&stepx, &stepy, algo, data);
	while (data->map[algo->map_posy][algo->map_posx]
		!= '1' && door_check(data, algo) == 0)
	{
		if (algo->dist_temp_rayx < algo->dist_temp_rayy)
		{
			algo->map_posx += stepx;
			algo->side = 0;
			algo->dist_temp_rayx += algo->delta_distx;
		}
		else
		{
			algo->map_posy += stepy;
			algo->side = 1;
			algo->dist_temp_rayy += algo->delta_disty;
		}
	}
	if (algo->side == 0)
		algo->wall_dist = algo->dist_temp_rayx - algo->delta_distx;
	else
		algo->wall_dist = algo->dist_temp_rayy - algo->delta_disty;
	get_texture(algo, stepx, stepy);
}

void	ft_calc_delta(t_algo *algo, t_data *data, int x)
{
	algo->side = 0;
	algo->wall_dist = 0;
	algo->coef_camx = ((2 * x) / (double)WIN_X) - 1;
	algo->raydir_actx = data->pos.dir_camx
		+ (data->pos.norm_camx * algo->coef_camx);
	algo->raydir_acty = data->pos.dir_camy
		+ (data->pos.norm_camy * algo->coef_camx);
	algo->map_posx = (int)(data->pos.p_x);
	algo->map_posy = (int)(data->pos.p_y);
	algo->delta_distx = sqrt(1 + ((algo->raydir_acty * algo->raydir_acty)
				/ (algo->raydir_actx * algo->raydir_actx)));
	algo->delta_disty = sqrt(((algo->raydir_actx * algo->raydir_actx)
				/ (algo->raydir_acty * algo->raydir_acty)) + 1);
}

void	build_img(t_data *data)
{
	int			x;
	double		dis_wall[WIN_X];
	t_algo		algo;

	x = -1;
	algo.side = 0;
	algo.wall_dist = 0;
	while (++x < WIN_X)
	{
		algo.texture = -1;
		ft_calc_delta(&algo, data, x);
		algo_dda(&algo, data);
		if (algo.coef_camx != 0)
			algo.wall_dist *= sin(atan2(algo.raydir_acty, algo.raydir_actx)
					- atan2(data->pos.norm_camy * algo.coef_camx,
						data->pos.norm_camx * algo.coef_camx));
		if (algo.wall_dist < 0)
			algo.wall_dist *= -1;
		draw_pix(data, &algo, WIN_Y / algo.wall_dist, x);
		dis_wall[x] = algo.wall_dist;
	}
	if (data->hardmode == 1)
		build_sprite(data, dis_wall);
	show_map(data);
	show_pov(data);
	display_heart(data);	
	mlx_put_image_to_window(data->mlx, data->win, data->img_win.img_ptr, 0, 0);
}
