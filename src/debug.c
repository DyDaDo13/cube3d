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
	//int		j;

	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
}

void	print_args(t_data *data)
{
	printf("┌───────────────────────────────────────\n");
	printf("│NO	= %s\n", data->textures_path.NO);
	printf("│SO	= %s\n", data->textures_path.SO);
	printf("│WE	= %s\n", data->textures_path.WE);
	printf("│EA	= %s\n", data->textures_path.EA);
	printf("│C	= %i\n", data->textures_path.C);
	printf("│F	= %i\n", data->textures_path.F);
	printf("├───────────────────────────────────────\n");
	printf("│Player Direction: %c\n", data->pos.c);
	printf("│Player Pos: \e[31mX = %f\e[34mY = %f\e[0m\n", data->pos.p_x, data->pos.p_y);
	printf("├───────────────────────────────────────\n");
	printf("│\e[34mcamX: \t\t%f\n|\e[31mcamY: \t\t%f\e[0m\n",
		data->pos.dir_camX, data->pos.dir_camY);
	printf("│\e[32mcamX_normal: \t%f\n|\e[36mcamY_normal: \t%f\e[0m\n",
		data->pos.norm_camX, data->pos.norm_camY);
	printf("└───────────────────────────────────────\n");
}
