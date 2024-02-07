/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:21:41 by ozone             #+#    #+#             */
/*   Updated: 2024/02/07 15:21:41 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"


// char	**get_map(int fd)
// {

// }

// char	**init_map(char *path_map, t_data *data)
// {
// 	int	fd;

// 	fd = open(path_map, O_RDONLY);
// 	if (fd == -1)
// 		return (perror("Error: No such file or directory"), NULL);
// 	data->map = get_map();
// }

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

void	get_args(t_data *data)
{
	data->textures.NO = get_path(data->map, 0);
	//printf("0987765%s\n", data->textures.NO);
	data->textures.SO = get_path(data->map, 1);
	data->textures.WE = get_path(data->map, 2);
	data->textures.EA = get_path(data->map, 3);
	data->textures.C = get_color(data->map, 5);
	//printf("C = %i,%i,%i\n", data->textures.C[0], data->textures.C[1], data->textures.C[2]);
	data->textures.F = get_color(data->map, 6);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (perror("Error: Too Many Arguments"), 1);
	data.map = init_map(av[1], &data);
	if (data.map == NULL)
		return (1);
	get_args(&data);
	print_args(&data);
	//print_map(data.map);
	return (0);
}