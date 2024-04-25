/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:24:26 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/24 10:29:15 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	set_mouse_center_screen(t_data *data)
{
	data->mouse.origin_x = (WIN_X / 2);
	data->mouse.origin_y = (WIN_Y / 2);
	mlx_mouse_move(data->mlx, data->win,
		data->mouse.origin_x, data->mouse.origin_y);
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	int		x_distance;
	double	rot_coef;

	(void)y;
	x_distance = 0;
	if (x < (WIN_X / 2))
		x_distance = x - (WIN_X / 2);
	else if (x > (WIN_X / 2))
		x_distance = x - (WIN_X / 2);
	rot_coef = (double)x_distance / (double)SENSIVITY;
	if (data->mouse.mouse_lock == 1)
	{
		ft_rotation(data, rot_coef);
		set_mouse_center_screen(data);
	}
	return (0);
}

int	kill_ennemy(t_algo *algo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_enemy)
	{
		if ((int)data->enemy[i].x == algo->map_posx
			&& (int)data->enemy[i].y == algo->map_posy)
		{
			data->enemy[i].texture = -1;
			data->info.live_ennemy -= 1;
			return (1);
		}
		i++;
	}
	return (0);
}

void	algo_dda_ennemy(t_algo *algo, t_data *data)
{
	int	stepx;
	int	stepy;

	get_steps(&stepx, &stepy, algo, data);
	while (data->map[algo->map_posy][algo->map_posx]
		!= '1' && data->map[algo->map_posy][algo->map_posx] != 'D')
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
		if (kill_ennemy(algo, data) == 1)
			return ;
	}
}

int	mouse_left_click(int button, int x, int y, t_data *data)
{
	t_algo	algo;

	(void)x;
	(void)y;
	if (button == 1 && data->hardmode == 1)
	{
		data->textures.tex_pov = 1;
		ft_calc_delta(&algo, data, WIN_X / 2);
		algo_dda_ennemy(&algo, data);
	}
	return (0);
}
