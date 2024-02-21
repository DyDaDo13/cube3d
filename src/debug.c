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
	int		y;
	int		x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '1')
				printf("\e[1;90m1\e[0m");
			else if (map[y][x] == ' ')
				printf(" ");
			else if (map[y][x] == '0')
				printf("0");
			else if (map[y][x] == 'E' || map[y][x] == 'W'
				|| map[y][x] == 'S' || map[y][x] == 'N')
				printf("\e[1;94m%c\e[0m", map[y][x]);
			else if (map[y][x] == 'D')
				printf("\e[1;93mD\e[0m");
			else if (map[y][x] == 'V')
				printf("\e[1;91mV\e[0m");
		}
		printf("\n");
	}
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
	printf("│DO	= %s\n", data->textures_path.DO);
	printf("├───────────────────────────────────────\n");
	printf("│Map height = \e[1;94m%i\e[0m\n", data->map_height);
	printf("│Map wifth = \e[1;91m%i\e[0m\n", data->map_width);
	printf("│Player Direction: %c\n", data->pos.c);
	printf("│Player Pos: \e[1;91mX = %f\e[1;94m Y = %f\e[0m\n",
		data->pos.p_x, data->pos.p_y);
	if (data->hardmode == 1)
		printf("│HARDCORE MODE \e[1;91mON\e[0m\n");
	else
		printf("│HARDCORE MODE \e[1;92mOFF\e[0m\n");
	printf("│NB enemi: %i\n", data->nb_enemis);
	printf("├───────────────────────────────────────\n");
	printf("│\e[1;93mcamX_dir:\t%f\t| \e[1;91mcamY_dir:\t%f\e[0m\n",
		data->pos.dir_camX, data->pos.dir_camY);
	printf("│\e[1;92mcamX_normal:\t%f\t| \e[1;96mcamY_normal:\t%f\e[0m\n",
		data->pos.norm_camX, data->pos.norm_camY);
	printf("└───────────────────────────────────────\n");
}
