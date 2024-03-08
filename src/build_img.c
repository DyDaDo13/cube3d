/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:16:32 by lle-saul          #+#    #+#             */
/*   Updated: 2024/03/06 18:24:56 by lle-saul         ###   ########.fr       */
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
		if (i <= algo->start)
			img_pixel_put(&data->img_win, x, i, data->textures_path.C);
		else if (i > algo->start && i <= algo->end)
			pix_texture(data, algo, &i);
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

/*algo->side == 1 -> wall in y | algo->side == 0 -> wall in x*/
void	algo_DDA(t_algo *algo, t_data *data)
{
	int	stepX;
	int	stepY;

	get_steps(&stepX, &stepY, algo, data);
	while (data->map[algo->map_posY][algo->map_posX] != '1' && door_check(data, algo) == 0)
	{
		if (algo->dist_temp_rayX < algo->dist_temp_rayY)
		{
			algo->map_posX += stepX;
			algo->side = 0;
			algo->dist_temp_rayX += algo->delta_distX;
		}
		else
		{
			algo->map_posY += stepY;
			algo->side = 1;
			algo->dist_temp_rayY += algo->delta_distY;
		}
	}
	if (algo->side == 0)
		algo->wall_dist = algo->dist_temp_rayX - algo->delta_distX;
	else
		algo->wall_dist = algo->dist_temp_rayY - algo->delta_distY;
	get_texture(algo, stepX, stepY);
}

void	ft_calc_delta(t_algo *algo, t_data *data, int x)
{
	algo->side = 0;
	algo->wall_dist = 0;
	algo->Coef_CamX = ((2 * x) / (double)WIN_X) - 1;
	algo->rayDir_actX = data->pos.dir_camX +
		(data->pos.norm_camX * algo->Coef_CamX);
	algo->rayDir_actY = data->pos.dir_camY +
		(data->pos.norm_camY * algo->Coef_CamX);
	algo->map_posX = (int)(data->pos.p_x);
	algo->map_posY = (int)(data->pos.p_y);
	algo->delta_distX = sqrt(1 + ((algo->rayDir_actY * algo->rayDir_actY) /
		(algo->rayDir_actX * algo->rayDir_actX)));
	algo->delta_distY = sqrt(((algo->rayDir_actX * algo->rayDir_actX) /
		(algo->rayDir_actY * algo->rayDir_actY)) + 1);
}

/*a viré
void	print_ennemy(t_data *data)
{
	int	i = 0;
	int	count = 0;
	
	printf("ennemi : ");
	while (i < data->nb_enemy)
	{
		if (data->enemy[i].x < 0 && data->enemy[i].y < 0)
			printf("%d, ", i);
		i++;
	}
	if (count == 0)
		printf("no one !!");
	printf("\n");
}*/

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
		algo_DDA(&algo, data);
		if (algo.Coef_CamX != 0)
			algo.wall_dist *= sin(atan2(algo.rayDir_actY, algo.rayDir_actX)
				- atan2(data->pos.norm_camY * algo.Coef_CamX,
					data->pos.norm_camX * algo.Coef_CamX));
		if (algo.wall_dist < 0)
			algo.wall_dist *= -1;
		draw_pix(data, &algo, WIN_Y / algo.wall_dist, x);
		dis_wall[x] = algo.wall_dist;
	}
	build_sprite(data, dis_wall);
	show_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img_win.img_ptr, 0, 0);
}
