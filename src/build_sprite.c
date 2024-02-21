/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:04:22 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/21 12:04:22 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	ft_max(double *dis, double *max, int enemies)
{
	int		i;
	double	max2;
	int 	index;

	i = 0;
	index = 0;
	max2 = 1.797693e+308;
	while (i < enemies)
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
	temp_order = malloc(sizeof(int) * data->nb_enemis);
	temp_dis = malloc(sizeof(double) * data->nb_enemis);
	while (++i < data->nb_enemis)
	{
		(*order)[i] = i;
		(*dis)[i] = (sqr(data->pos.p_x - data->enemi[i].enemi_pos_x)
			+ sqr(data->pos.p_y - data->enemi[i].enemi_pos_y));
	}
	while (--i >= 0)
	{
		index = ft_max(*dis, &max, data->nb_enemis);
		temp_order[i] = (*order)[index];
		temp_dis[i] = (*dis)[index];
	}
	free_sort_sprite(temp_order, temp_dis, order, dis);
}

void	build_sprite(t_data *data, double *dis_wall)
{
	int		*order_sprite;
	double	*dis_sprite;
	
	order_sprite = malloc(sizeof(int) * data->nb_enemis);
	dis_sprite = malloc(sizeof(double) * data->nb_enemis);
	sort_sprite(data, &order_sprite, &dis_sprite);
	
}
