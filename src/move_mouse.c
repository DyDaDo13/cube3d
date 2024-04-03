/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:24:26 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/03 12:01:26 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

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
		//printf("Ex : %d | Ey : %d | Mx : %d | My : %d\n", (int)data->enemy[i].x, algo->map_posX, (int)data->enemy[i].y, algo->map_posY);
		if ((int)data->enemy[i].x == algo->map_posX && (int)data->enemy[i].y == algo->map_posY)
		{
			data->enemy[i].texture = -1;
			return (1);
		}
		i++;
	}
	return (0);
}

void	algo_DDA_ennemy(t_algo *algo, t_data *data)
{
	int	stepX;
	int	stepY;

	get_steps(&stepX, &stepY, algo, data);
	while (data->map[algo->map_posY][algo->map_posX] != '1' && data->map[algo->map_posY][algo->map_posX] != 'D')
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
		if (kill_ennemy(algo, data) == 1)
			return ;
	}
}

int	mouse_left_click(int button, int x, int y, t_data *data)
{
	t_algo	algo;
	
	(void)x;
	(void)y;
	if (button == 1)
	{
		data->textures.tex_POV = 1;
		ft_calc_delta(&algo, data, WIN_X / 2);
		algo_DDA_ennemy(&algo, data);
	}
	return (0);
}

