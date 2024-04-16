/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:41:37 by ozone             #+#    #+#             */
/*   Updated: 2024/04/16 14:51:19 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	enemy_move_dir(t_data *data, int actual_enemy, double coef)
{
	double		cord_dist_x;
	double		cord_dist_y;
	static int	invincibinity = 100;

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
	else
	{
		if (invincibinity == 100 && data->pv > 0)
			data->pv -= 1;
		if (invincibinity > 0)
			invincibinity--;
		else
			invincibinity = 100;
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
			enemy_move_dir(data, actual_enemy, 0.0);
		actual_enemy++;
	}
}
