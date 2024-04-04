/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:55:15 by ozone             #+#    #+#             */
/*   Updated: 2024/04/04 16:09:48 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

char	*get_path(char **map, int pos)
{
	int		i;
	int		j;
	int		size;
	char	*path;

	i = 0;
	j = -1;
	if (pos == -1)
		return (NULL);
	while (map[pos][i] && map[pos][i] != '.')
		i++;
	size = (ft_strlen(map[pos]) - i);
	path = malloc(sizeof(char) * size + 1);
	path[size] = '\0';
	i--;
	while (map[pos][++i])
		path[++j] = map[pos][i];
	if (access(path, F_OK) != 0)
		return (printf("texture not found\n"), NULL);
	return (path);
}

unsigned int	get_color_path(char **map, int pos)
{
	int				i;
	int				j;
	int				*res;
	unsigned int	res2;

	i = 2;
	j = 0;
	if (pos == -1)
		return ((int)-1);
	res = malloc(sizeof(int *) * 3);
	while (map[pos][i])
	{
		res[j] = ft_atoi(map[pos] + i);
		while (map[pos][i] && (map[pos][i] >= '0' && map[pos][i] <= '9'))
			i++;
		i++;
		j++;
	}
	res2 = get_color((unsigned char)res[0],
			(unsigned char)res[1],
			(unsigned char)res[2]);
	return (free(res), res2);
}

int	find_arg(char c, char f, char **map)
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

void	init_args(t_data *data)
{
	data->textures_path.C = (int)-1;
	data->textures_path.F = (int)-1;
	data->textures_path.no = NULL;
	data->textures_path.so = NULL;
	data->textures_path.we = NULL;
	data->textures_path.ea = NULL;
}

int	get_args(t_data *data)
{
	init_args(data);
	data->textures_path.dor = get_path(data->map, find_arg('D', 'O', data->map));
	data->textures_path.no = get_path(data->map, find_arg('N', 'O', data->map));
	if (!data->textures_path.no)
		return (printf("Error: arg 'no' not found\n"), 1);
	data->textures_path.so = get_path(data->map, find_arg('S', 'O', data->map));
	if (!data->textures_path.so)
		return (printf("Error: arg 'so' not found\n"), 1);
	data->textures_path.we = get_path(data->map, find_arg('W', 'E', data->map));
	if (!data->textures_path.we)
		return (printf("Error: arg 'we' not found\n"), 1);
	data->textures_path.ea = get_path(data->map, find_arg('E', 'A', data->map));
	if (!data->textures_path.ea)
		return (printf("Error: arg 'ea' not found\n"), 1);
	data->textures_path.C = get_color_path(data->map,
			find_arg('C', ' ', data->map));
	if ((int)data->textures_path.C == -1)
		return (printf("Error: arg 'C' not found\n"), 1);
	data->textures_path.F = get_color_path(data->map,
			find_arg('F', ' ', data->map));
	if ((int)data->textures_path.F == -1)
		return (printf("Error: arg 'F' not found\n"), 1);
	if (find_arg('V', '\0', data->map) != -1)
		data->hardmode = 1;
	return (0);
}
