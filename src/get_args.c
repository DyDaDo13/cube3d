/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:55:15 by ozone             #+#    #+#             */
/*   Updated: 2024/02/08 14:50:12 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

char	*get_path(char **map, int pos)
{
	int		i;
	int		j;
	int		size;
	char	*path;

	i = 2;
	j = -1;
	size = ft_strlen(map[pos]) - 3;
	path = malloc(sizeof(char) * size + 1);
	path[size] = '\0';
	while (map[pos][++i])
		path[++j] = map[pos][i];
	return (path);
}

int	*get_color(char **map, int pos)
{
	int	i;
	int	j;
	int	*res;

	i = 2;
	j = 0;
	if (pos == -1)
		return (NULL);
	res = malloc(sizeof(int *) * 3);
	while (map[pos][i])
	{
		res[j] = ft_atoi(map[pos] + i);
		while (map[pos][i] && (map[pos][i] >= '0' && map[pos][i] <= '9'))
			i++;
		i++;
		j++;
	}
	return (res);
}

int		find_arg(char c, char f, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] == c && map[i][1] == f)
			return (i);
		i++;
	}
	return (-1);
}

int	get_args(t_data *data)
{
	data->textures.NO = get_path(data->map, find_arg('N', 'O', data->map));
	if (!data->textures.NO)
		return (printf("Error: arg 'NO' not found\n"), 1);
	data->textures.SO = get_path(data->map, find_arg('S', 'O', data->map));
	if (!data->textures.SO)
		return (printf("Error: arg 'SO' not found\n"), 1);
	data->textures.WE = get_path(data->map, find_arg('W', 'E', data->map));
	if (!data->textures.WE)
		return (printf("Error: arg 'WE' not found\n"), 1);
	data->textures.EA = get_path(data->map, find_arg('E', 'A', data->map));
	if (!data->textures.EA)
		return (printf("Error: arg 'EA' not found\n"), 1);
	data->textures.C = get_color(data->map, find_arg('C', ' ', data->map));
	if (!data->textures.C)
		return (printf("Error: arg 'C' not found\n"), 1);
	data->textures.F = get_color(data->map, find_arg('F', ' ', data->map));
	if (!data->textures.F)
		return (printf("Error: arg 'F' not found\n"), 1);
	return (0);
}
