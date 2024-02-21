/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemi_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:41:37 by ozone             #+#    #+#             */
/*   Updated: 2024/02/21 12:27:01 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

/*

x = can't see
1 = wall
0 = can see;
V = enemy pos;

enemy_distance trigger == 5;

enemy_vision_trigger

0xx000000
00000000x
0001000xx
000000xxx
0000V1xxx
000100xxx
0xx0000xx
xxx00000x
xx0000000

*/


// int		can_see_player(t_data *data, int actual_enemy)
// {
// 	int		x;
// 	int		y;
	
// 	x = data->enemi[actual_enemy].enemi_pos_x;
// 	y = data->enemi[actual_enemy].enemi_pos_y;
	
// 	//data->map[y][x];
// 	//printf("%c | x = %i | y = %i\n", data->map[y][x], x, y);
// 	return (0);
// }

// move_enemi_up(t_data *data, int actual_enemy)
// {
// 	if (data->map[(int)data->enemi[actual_enemy].enemi_pos_y][(int)data->enemi[actual_enemy].enemi_pos_x] != '1')
// 			data->enemi[actual_enemy].enemi_pos_y -= ENEMY_MOVE_SPEED;
// }

// void	random_movements(t_data *data, int actual_enemy)
// {
// 	int	random_nb;

// 	random_nb = rand() % 10;
// 	if (random_nb == 0)
// 		move_enemi_up(data, actual_enemy);
// 	else if (random_nb == 1)
// 		move_enemi_down(data, actual_enemy);
// 	else if (random_nb == 2)
// 		move_enemi_left(data, actual_enemy);
// 	else if (random_nb == 3)
// 		move_enemi_right(data, actual_enemy);
// 	else if (random_nb == 4)
// 		move_enemi_up_right(data, actual_enemy);
// 	else if (random_nb == 5)
// 		move_enemi_up_left(data, actual_enemy);
// 	else if (random_nb == 6)
// 		move_enemi_down_left(data, actual_enemy);
// 	else if (random_nb == 7)
// 		move_enemi_down_right(data, actual_enemy);
// 	return ;
// }

// void	enemy_AI(t_data *data)
// {
// 	int	actual_enemy;

// 	actual_enemy = -1;
// 	while (++actual_enemy < data->nb_enemis)
// 	{
// 		if (can_see_player(data, actual_enemy) == 1)
// 			return ;
// 		else
// 			random_movements(data, actual_enemy);
// 	}
// 	return ;
// }