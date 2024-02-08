/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:55:15 by ozone             #+#    #+#             */
/*   Updated: 2024/02/08 14:22:31 by ozone            ###   ########.fr       */
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

int		find_arg(char c, char **map)
{
	int	i;

	i = 0;
	while (map[i][0] != c)
		i++;
	return (i);
}

int	get_args(t_data *data)
{
	data->textures.NO = get_path(data->map, find_arg('N', data->map));
	if (!data->textures.NO)
		return (1);
	data->textures.SO = get_path(data->map, find_arg('S', data->map));
	if (!data->textures.SO)
		return (1);
	data->textures.WE = get_path(data->map, find_arg('W', data->map));
	if (!data->textures.WE)
		return (1);
	data->textures.EA = get_path(data->map, find_arg('E', data->map));
	if (!data->textures.EA)
		return (1);
	data->textures.C = get_color(data->map, find_arg('C', data->map));
	if (!data->textures.C)
		return (1);
	data->textures.F = get_color(data->map, find_arg('F', data->map));
	if (!data->textures.F)
		return (1);
	return (0);
}
