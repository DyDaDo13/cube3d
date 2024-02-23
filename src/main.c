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

// int	verfy_extention(char *av, char *ext)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (av[i] && av[i] != '.')
// 		i++;
// 	j = 0;
// 	while (av[i] && ext[j])
// 		if (av[i] != ext[j])
// 	return (open(av, O_RDONLY));
// }

// #include "mlx.h"
// #include <stdio.h>

// typedef struct s_data {
//     void *mlx;
//     void *win;
// }              t_data;

int	main(int ac, char **av)
{
	int		fd;
	t_data	data;

	if (ac != 2)
		return (printf("Error: Too Many or Less Arguments\n"), 1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (perror("Error: fd not_open"), 1);
	data.map = init_map(fd, &data);
	if (data.map == NULL)
		return (1);
	data.hardmode = 0;
	if (get_args(&data) == 1)
		return (free_all(&data), 1);
	data.map = trunc_map(&data);
	if (data.map == NULL)
		return (free_all(&data), 1);
	if (check_map_valid(&data) == 1)
		return (free_all(&data), 1);
	if (data.hardmode == 1)
		placing_enemy(&data);
	print_args(&data);
	print_map(data.map);
	printf("----------------------------------------\n");
	ft_display(&data);
	free_all(&data);
	return (0);
}

