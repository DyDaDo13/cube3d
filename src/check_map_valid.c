/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:13:58 by ozone             #+#    #+#             */
/*   Updated: 2024/02/19 13:42:17 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	check_player(t_data *data)
{
	int	x;
	int	y;
	int	player;

	y = -1;
	player = 0;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'N'
				|| data->map[y][x] == 'S'
				|| data->map[y][x] == 'W'
				|| data->map[y][x] == 'E')
				player++;
		}
	}
	if (player != 1)
		return (1);
	return (0);
}

void	find_p(char **map, t_point *P, t_data *data)
{
	int			i;
	int			j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N'
				|| map[i][j] == 'S'
				|| map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				P->x = j;
				P->y = i;
				data->pos.p_y = i;
				data->pos.p_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	is_path_valid(char **map, t_data *data)
{
	t_point	*size;
	t_point	*begin;

	size = malloc(sizeof(t_point));
	begin = malloc(sizeof(t_point));
	if (size == NULL || begin == NULL)
		return (1);
	find_p(map, begin, data);
	flood_fill(map, size, begin, data);
	if (size->i == 1)
		return (free(size), free(begin), 1);
	return (free(size), free(begin), 0);
}

int	check_elements(t_data *data)
{
	int	x;
	int	y;
	int	things;

	y = -1;
	things = 0;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] != '1'
				&& data->map[y][x] != '0'
				&& data->map[y][x] != ' '
				&& data->map[y][x] != 'S'
				&& data->map[y][x] != 'W'
				&& data->map[y][x] != 'E'
				&& data->map[y][x] != 'N')
				things++;
		}
	}
	if (things != 0)
		return (1);
	return (0);
}

int	check_map_valid(t_data *data)
{
	if (check_elements(data) == 1)
		return (printf("Error: unrecongnized element\n"), 1);
	if (check_player(data) == 1)
		return (printf("Error: invalid object in map 'PLAYER'\n"), 1);
	if (is_path_valid(data->map, data) == 1)
		return (printf("Error: invalid object in map 'WALLS'\n"), 1);
	get_player_vec_camera(data);
	data->move_speed = MOVE_SPEED;
	data->map_lenX = ft_strlen(data->map[0]);
	data->map_lenY = ft_strlen2(data->map);
	return (0);
}
