/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:35:32 by dydado13          #+#    #+#             */
/*   Updated: 2024/02/08 11:52:11 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	free_map(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_list(t_map **map)
{
	t_map	*tmp;

	tmp = *map;
	while ((*map))
	{
		tmp = (*map)->next;
		free((*map));
		(*map) = tmp;
	}
}

void	free_all(t_data *data)
{
	if (data->map)
		free_map(data->map);
	if (data->textures_path.EA)
		free(data->textures_path.EA);
	if (data->textures_path.WE)
		free(data->textures_path.WE);
	if (data->textures_path.NO)
		free(data->textures_path.NO);
	if (data->textures_path.SO)
		free(data->textures_path.SO);
	// if (data->textures_path.C)
	// 	free(data->textures_path.C);
	// if (data->textures_path.F)
	// 	free(data->textures_path.F);
}
