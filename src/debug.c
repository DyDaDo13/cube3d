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

int	get_map_lenx(char **map)
{
	int	x;
	int	y;
	int	max_size;

	y = -1;
	max_size = 0;
	while (map[++y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if (max_size < x)
			max_size = x;
	}
	return (max_size);
}

void	print_enemy_movement(t_data *data, int actual_enemy)
{
	int	x;
	int	y;

	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (y == (int)data->pos.p_y
				&& x == (int)data->pos.p_x)
				printf("\e[1;92mP\e[0m");
			else if (y == (int)data->enemy[actual_enemy].y
				&& x == (int)data->enemy[actual_enemy].x)
				printf("\e[1;91mV\e[0m");
			else
				printf("%c", data->map[y][x]);
		}
		printf("\n");
	}
	printf("\n");
}

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
	printf("│no	= %s\n", data->textures_path.no);
	printf("│so	= %s\n", data->textures_path.so);
	printf("│we	= %s\n", data->textures_path.we);
	printf("│ea	= %s\n", data->textures_path.ea);
	printf("│c	= %i\n", data->textures_path.c);
	printf("│f	= %i\n", data->textures_path.f);
	printf("│dor	= %s\n", data->textures_path.dor);
	printf("├───────────────────────────────────────\n");
	printf("│Map height = \e[1;94m%i\e[0m\n", data->map_height);
	printf("│Map width = \e[1;91m%i\e[0m\n", data->map_width);
	printf("│Player Direction: %c\n", data->pos.c);
	printf("│Player Pos: \e[1;91mX = %f\e[1;94m Y = %f\e[0m\n",
		data->pos.p_x, data->pos.p_y);
	if (data->hardmode == 1)
		printf("│HARDCORE MODE \e[1;91mON\e[0m\n");
	else
		printf("│HARDCORE MODE \e[1;92mOFF\e[0m\n");
	printf("│NB enemy: %i\n", data->nb_enemy);
	printf("├───────────────────────────────────────\n");
	printf("│\e[1;93mcamX_dir:\t%f\t| \e[1;91mcamY_dir:\t%f\e[0m\n",
		data->pos.dir_camx, data->pos.dir_camy);
	printf("│\e[1;92mcamX_normal:\t%f\t| \e[1;96mcamY_normal:\t%f\e[0m\n",
		data->pos.norm_camx, data->pos.norm_camy);
	printf("└───────────────────────────────────────\n");
}
