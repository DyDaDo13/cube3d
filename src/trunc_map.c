/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trunc_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:26:34 by ozone             #+#    #+#             */
/*   Updated: 2024/04/04 15:31:45 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	check_move(char **map, int y, int x)
{
	if (map[y][x] != '\0' && map[y][x] != '1' && map[y][x] != ' ')
		return (1);
	return (0);
}

int	get_trunc_size(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j] == ' ')
			if (data->map[i][j] == '1')
				break ;
		if (data->map[i][j] == '1')
			break ;
	}
	return (i);
}

char	**trunc_map(t_data *data)
{
	int		trunked_size;
	int		full_size;
	char	**new_map;
	int		index[3];

	full_size = ft_strlen2(data->map);
	trunked_size = get_trunc_size(data);
	if (trunked_size == full_size)
		return (free_map(data->map), printf("Error: map not found\n"), NULL);
	new_map = malloc(sizeof(char *) * full_size - trunked_size + 1);
	new_map[full_size - trunked_size] = NULL;
	index[1] = 0;
	index[0] = (trunked_size - 1);
	while (data->map[++index[0]])
	{
		index[2] = ft_strlen(data->map[index[0]]);
		new_map[index[1]] = malloc(sizeof(char) * index[2] + 1);
		new_map[index[1]][index[2]] = '\0';
		ft_strcpy(new_map[index[1]], data->map[index[0]]);
		index[1]++;
	}
	free_map(data->map);
	return (new_map);
}
