/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:16:14 by ozone             #+#    #+#             */
/*   Updated: 2024/02/20 19:25:41 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/cube3d.h"

void	get_size_map(t_data *data)
{
	int		y;
	int		x;

	y = -1;
	while (data->map[++y])
	{
		x = 0;
		while (data->map[y][x])
			x++;
	}
	data->map_width = x;
	data->map_height = y;
}

int	check_pos(char pos)
{
	if (pos == 'E' || pos == 'W' || pos == 'S' || pos == 'N')
		return (1);
	else if (pos == '1' || pos == 'D' || pos == ' ')
		return (1);
	return (0);
}

void	placing_enemis(t_data *data)
{
	int		y;
	int		x;
	int		rand_x;
	int		rand_y;
	int		moy;
	
	srand(time(NULL));
	get_size_map(data);
	moy = ((data->map_width + data->map_height) / 6);
	while (moy > 0)
	{
		y = -1;
		while (data->map[++y])
		{
			x = -1;
			while (data->map[y][++x])
			{
				rand_x = (rand() % data->map_width);
				rand_y = (rand() % data->map_height);
				if (check_pos(data->map[rand_y][rand_x]) == 0 && moy > 0)
				{
					data->map[rand_y][rand_x] = 'V';
					moy--;
				}
			}
		}
	}
}
