/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:41:37 by ozone             #+#    #+#             */
/*   Updated: 2024/04/03 15:41:21 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	enemy_move_dir(t_data *data, int actual_enemy)
{
	double	coef;
	double	cord_dist_x;
	double	cord_dist_y;

	cord_dist_x = (data->pos.p_x - data->enemy[actual_enemy].x);
	cord_dist_y = (data->pos.p_y - data->enemy[actual_enemy].y);
	coef = sqrt(sqr(ENEMY_MOVE_SPEED) / (sqr(cord_dist_x) + sqr(cord_dist_y)));
	if (is_player_hitbox_touched(data, actual_enemy) == 0)
	{
		if (data->map[(int)((cord_dist_y * coef) + data->enemy[actual_enemy].y)]
			[(int)data->enemy[actual_enemy].x] != '1')
			data->enemy[actual_enemy].y += (cord_dist_y * coef);
		if (data->map[(int)data->enemy[actual_enemy].y][(int)((cord_dist_x
				* coef) + data->enemy[actual_enemy].x)] != '1')
			data->enemy[actual_enemy].x += (cord_dist_x * coef);
	}
}

void	enemy_move(t_data *data)
{
	int	actual_enemy;

	actual_enemy = 0;
	while (actual_enemy < data->nb_enemy)
	{
		if (data->enemy[actual_enemy].x >= 0
			&& data->enemy[actual_enemy].y >= 0)
			enemy_move_dir(data, actual_enemy);
		actual_enemy++;
	}
}
