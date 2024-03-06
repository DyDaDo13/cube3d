/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:41:37 by ozone             #+#    #+#             */
/*   Updated: 2024/03/06 18:30:21 by lle-saul         ###   ########.fr       */
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
	
// 	x = data->enemy[actual_enemy].x;
// 	y = data->enemy[actual_enemy].y;
	
// 	//data->map[y][x];
// 	//printf("%c | x = %i | y = %i\n", data->map[y][x], x, y);
// 	return (0);
// }

// move_enemy_up(t_data *data, int actual_enemy)
// {
// 	if (data->map[(int)data->enemy[actual_enemy].y][(int)data->enemy[actual_enemy].x] != '1')
// 			data->enemy[actual_enemy].y -= ENEMY_MOVE_SPEED;
// }

// void	random_movements(t_data *data, int actual_enemy)
// {
// 	int	random_nb;

// 	random_nb = rand() % 10;
// 	if (random_nb == 0)
// 		move_enemy_up(data, actual_enemy);
// 	else if (random_nb == 1)
// 		move_enemy_down(data, actual_enemy);
// 	else if (random_nb == 2)
// 		move_enemy_left(data, actual_enemy);
// 	else if (random_nb == 3)
// 		move_enemy_right(data, actual_enemy);
// 	else if (random_nb == 4)
// 		move_enemy_up_right(data, actual_enemy);
// 	else if (random_nb == 5)
// 		move_enemy_up_left(data, actual_enemy);
// 	else if (random_nb == 6)
// 		move_enemy_down_left(data, actual_enemy);
// 	else if (random_nb == 7)
// 		move_enemy_down_right(data, actual_enemy);
// 	return ;
// }

// void	enemy_AI(t_data *data)
// {
// 	int	actual_enemy;

// 	actual_enemy = -1;
// 	while (++actual_enemy < data->nb_enemy)
// 	{
// 		if (can_see_player(data, actual_enemy) == 1)
// 			return ;
// 		else
// 			random_movements(data, actual_enemy);
// 	}
// 	return ;
// }

void	enemy_move_dir(t_data *data, int actual_enemy)
{
	double	coef;
	double	cord_dist_x;
	double	cord_dist_y;

	cord_dist_x = (data->pos.p_x - data->enemy[actual_enemy].x);
	cord_dist_y = (data->pos.p_y - data->enemy[actual_enemy].y);
	coef = sqrt(sqr(ENEMY_MOVE_SPEED) / (sqr(cord_dist_x) + sqr(cord_dist_y)));
	//printf("m_x = %f\nm_y = %f\ncoef = %f\n", (data->enemy[0].x - (cord_dist_x * coef)), (data->enemy[0].y - (cord_dist_y * coef)), coef);
	if (is_player_hitbox_touched(data, actual_enemy) == 0)
	{
		if (data->map[(int)((cord_dist_y * coef) + data->enemy[actual_enemy].y)][(int)data->enemy[actual_enemy].x] != '1')
			data->enemy[actual_enemy].y += (cord_dist_y * coef);
		if (data->map[(int)data->enemy[actual_enemy].y][(int)((cord_dist_x * coef) + data->enemy[actual_enemy].x)] != '1')
			data->enemy[actual_enemy].x += (cord_dist_x * coef);	
	}
	// else if (data->map[-((int)((cord_dist_y * coef) + data->enemy[actual_enemy].y))][(int)data->enemy[actual_enemy].x] != '1' && is_player_hitbox_touched(data, actual_enemy, 0, 1) == 1)
	// 	data->enemy[actual_enemy].y -= (cord_dist_y * coef);
	
	// else if (data->map[(int)data->enemy[actual_enemy].y][-((int)((cord_dist_x * coef) + data->enemy[actual_enemy].x))] != '1' && is_player_hitbox_touched(data, actual_enemy, 1, 0) == 1)
	// 	data->enemy[actual_enemy].x -= (cord_dist_x * coef);

}

void	enemy_move(t_data *data)
{
	int	actual_enemy;

	actual_enemy = 0;
	while (actual_enemy < data->nb_enemy)
	{
		if (data->enemy[actual_enemy].x >= 0 && data->enemy[actual_enemy].y >= 0)
			enemy_move_dir(data, actual_enemy);
		actual_enemy++;
	}
}