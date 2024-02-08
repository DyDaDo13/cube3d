/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:09:51 by ozone             #+#    #+#             */
/*   Updated: 2024/02/07 15:11:02 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	print_map(char **map)
{
	int		i;

	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
}

void	print_args(t_data *data)
{
	printf("NO = %s\n", data->textures_path.NO);
	printf("SO = %s\n", data->textures_path.SO);
	printf("WE = %s\n", data->textures_path.WE);
	printf("EA = %s\n", data->textures_path.EA);
	printf("C = %i,%i,%i\n", data->textures_path.C[0],
		data->textures_path.C[1], data->textures_path.C[2]);
	printf("F = %i,%i,%i\n", data->textures_path.F[0],
		data->textures_path.F[1], data->textures_path.F[2]);
}
