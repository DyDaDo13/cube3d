/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitboxs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:54:10 by ozone             #+#    #+#             */
/*   Updated: 2024/02/24 15:07:59 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

// si A == player
// si B == EnterWindowMask
// a->b

// Donc

// (s_x + p_x) / (s_y + p_y) = vecteur player -> enenmi

// je cherche a avoir une distance fixe avec lenemi

// il me faut donc une hitbox;

// p_x -> s_x | p_y -> s_x

int	is_player_hitbox_touched(t_data *data, int actual_enemy, int x, int y)
{
	double	distance_sp_x;
	double	distance_sp_y;
	distance_sp_x = (data->pos.p_x - data->enemy[actual_enemy].x) * 2;
	distance_sp_y = (data->pos.p_y - data->enemy[actual_enemy].y) * 2;
	if (distance_sp_x < 0)
		distance_sp_x *= -1;
	if (distance_sp_y < 0)
		distance_sp_y *= -1;
	if (x == 0)
	{
		if (distance_sp_y <= HITBOX)
			return (1);
	}
	else if (y == 0)
	{
		if (distance_sp_x <= HITBOX)
			return (1);
	}
	return (0);
}
