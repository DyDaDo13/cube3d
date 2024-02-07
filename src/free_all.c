/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:35:32 by dydado13          #+#    #+#             */
/*   Updated: 2024/02/07 22:22:01 by ozone            ###   ########.fr       */
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
	{
		free_map(data->map);
		free(data->textures.EA);
		free(data->textures.WE);
		free(data->textures.NO);
		free(data->textures.SO);
		free(data->textures.C);
		free(data->textures.F);
		//free(data->map);
	}
}
