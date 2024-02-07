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

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (perror("Error: Too Many Arguments"), 1);
	data.map = init_map(av[1], &data);
	if (data.map == NULL)
		return (1);
	print_map(data.map);
	return (0);
}