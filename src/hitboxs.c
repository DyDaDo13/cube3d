/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitboxs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:54:10 by ozone             #+#    #+#             */
/*   Updated: 2024/04/03 15:58:19 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	is_player_hitbox_touched(t_data *data, int actual_enemy)
{
	double	dist_sp;

	dist_sp = sqrt(sqr(data->enemy[actual_enemy].x - data->pos.p_x)
			+ sqr(data->enemy[actual_enemy].y - data->pos.p_y));
	if (dist_sp <= HITBOX)
		return (1);
	return (0);
}
