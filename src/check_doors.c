/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:11:46 by ozone             #+#    #+#             */
/*   Updated: 2024/02/19 17:12:20 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	check_around_2(char **map, int x, int y)
{
	int	count_doors;

	count_doors = 0;
	if (map[y + 1][x] && map[y + 1][x] == '1')
		count_doors++;
	else
		count_doors = 0;
	if (map[y - 1][x] && map[y - 1][x] == '1')
		count_doors++;
	else
		count_doors = 0;
	return (count_doors);
}

int	check_around1(char **map, int x, int y)
{
	int	count_doors;

	count_doors = 0;
	if (map[y][x + 1] && map[y][x + 1] == '1')
		count_doors++;
	else
		count_doors = 0;
	if (map[y][x - 1] && map[y][x - 1] == '1')
		count_doors++;
	else
		count_doors = 0;
	if (count_doors == 2)
		return (0);
	if (check_around_2(map, x, y) == 2)
		return (0);
	return (1);
}

int	is_door_valid(char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'D')
				if (check_around1(map, x, y) == 1)
					return (1);
	}
	return (0);
}