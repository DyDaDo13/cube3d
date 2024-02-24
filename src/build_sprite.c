/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:04:22 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/23 16:50:41 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	ft_max(double *dis, double *max, int enemyes)
{
	int		i;
	double	max2;
	int 	index;

	i = 0;
	index = 0;
	max2 = 1.797693e+308;
	while (i < enemyes)
	{
		if (max2 > dis[i] && *max < dis[i])
		{
			max2 = dis[i];
			index = i;
		}
		i++;
	}
	*max = dis[index];
	return (index);
}

void	free_sort_sprite(int *t_order, double *t_dis, int **order, double **dis)
{
	free(*order);
	free(*dis);
	*order = t_order;
	*dis = t_dis;
}

void	sort_sprite(t_data *data, int **order, double **dis)
{
	int		i;
	double	max;
	int		*temp_order;
	double	*temp_dis;
	int		index;

	i = -1;
	max = 0;
	temp_order = malloc(sizeof(int) * data->nb_enemy);
	temp_dis = malloc(sizeof(double) * data->nb_enemy);
	while (++i < data->nb_enemy)
	{
		(*order)[i] = i;
		(*dis)[i] = (sqr(data->pos.p_x - data->enemy[i].x)
			+ sqr(data->pos.p_y - data->enemy[i].y));
	}
	while (--i >= 0)
	{
		index = ft_max(*dis, &max, data->nb_enemy);
		temp_order[i] = (*order)[index];
		temp_dis[i] = (*dis)[index];
	}	
	free_sort_sprite(temp_order, temp_dis, order, dis);
}

/*draw.y : drawStartY | draw.i : drawEndY | spr->side : spriteHeight
draw.x : drawStartX | draw.j : drawEndX | spr->side : spriteWidth*/
void	build_sprite2(t_data *data, t_algo *spr, double *dis_wall)
{
	t_point	draw;

	spr->side = abs((int)(WIN_Y / spr->dist_temp_rayY));
	draw.y = -spr->side / 2 + WIN_Y / 2;
	if (draw.y < 0)
		draw.y = 0;
	draw.i = spr->side / 2 + WIN_Y / 2;
	if (draw.i >= WIN_Y)
		draw.i = WIN_Y - 1;
	draw.x = -spr->side / 2 + spr->end;
	if (draw.x < 0)
		draw.x = 0;
	draw.j = spr->side / 2 + spr->end;
	if (draw.j >= WIN_X)
		draw.j = WIN_X - 1;
	draw_sprite(data, &draw, spr, dis_wall);
}

/*ray_dirX & Y : Sprite_posX & Y | Coef_camX : coef matrix
dist_temp_rayX & Y : Sprite_pos X & Y trans | spr.end : spriteScreenX*/
void	build_sprite(t_data *data, double *dis_wall)
{
	int		*order_sprite;
	double	*dis_sprite;
	t_algo	spr;
	
	(void)dis_wall;
	order_sprite = malloc(sizeof(int) * data->nb_enemy);
	dis_sprite = malloc(sizeof(double) * data->nb_enemy);
	sort_sprite(data, &order_sprite, &dis_sprite);
	spr.x = -1;
	while (++spr.x < data->nb_enemy)
	{
		//printf("sprposX : %f | sprposY : %f | X : %d\n", data->enemy[order_sprite[spr.x]].x, data->enemy[order_sprite[spr.x]].y, spr.x);
		spr.rayDir_actX = data->enemy[order_sprite[spr.x]].x - data->pos.p_x;
		spr.rayDir_actY = data->enemy[order_sprite[spr.x]].y - data->pos.p_y;
		spr.Coef_CamX = 1.0 / (data->pos.norm_camX * data->pos.dir_camY
			- data->pos.dir_camX * data->pos.norm_camY);
		spr.dist_temp_rayX = spr.Coef_CamX * ((data->pos.dir_camY * spr.rayDir_actX) - (data->pos.dir_camX * spr.rayDir_actY));
		spr.dist_temp_rayY = spr.Coef_CamX * ((-data->pos.norm_camY * spr.rayDir_actX) + (data->pos.norm_camX * spr.rayDir_actY));
		spr.end = (int)((WIN_X / 2) * (1 + spr.dist_temp_rayX / spr.dist_temp_rayY));
		build_sprite2(data, &spr, dis_wall);
	}
	free(order_sprite);
	free(dis_sprite);
}
