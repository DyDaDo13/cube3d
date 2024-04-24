/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:57:14 by ozone             #+#    #+#             */
/*   Updated: 2024/04/24 16:04:14 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	ft_max_size(char **str)
{
	int	x;
	int	y;
	int	max;

	y = -1;
	max = 0;
	while (str[++y])
	{
		x = 0;
		while (str[y][x])
			x++;
		if (x > max)
			max = x;
	}
	return (max);
}

int	check_arg_2(t_data *data)
{
	if (check_extention(data->textures_path.no, ".xpm") != 0)
		return (1);
	if (check_extention(data->textures_path.so, ".xpm") != 0)
		return (1);
	if (check_extention(data->textures_path.ea, ".xpm") != 0)
		return (1);
	if (check_extention(data->textures_path.we, ".xpm") != 0)
		return (1);
	data->info.live_ennemy = 0;
	return (0);
}

int	check_extention(char *str, char *ext)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(str);
	if (i - 4 > 0)
	{
		i -= 4;
		while (str[i] == ext[j] && str[i] != '\0' && ext[j] != '\0')
		{
			i++;
			j++;
		}
		if (str[i] == '\0')
			return (0);
		return (printf("error: invalid extention\n"), 1);
	}
	return (printf("error: invalid extention\n"), 1);
}

int	check_side(int textx, t_algo *algo)
{
	if (algo->side == 0 && algo->raydir_actx < 0)
		textx = TEXT_SIZE - textx - 1;
	if (algo->side == 1 && algo->raydir_acty > 0)
		textx = TEXT_SIZE - textx - 1;
	return (textx);
}

void	ft_key_moves2(t_data *data, int *i)
{
	if (data->hardmode == 1)
		enemy_move(data);
	if (data->pv == 0)
		ft_stop(data);
	if (*i == 1000)
		data->mouse.mouse_lock *= -1;
	else if (*i == 1001)
	{
		data->mouse.mouse_lock *= -1;
		*i = 0;
	}
	check_door_spot(data);
}
