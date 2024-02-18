/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:25:43 by ozone             #+#    #+#             */
/*   Updated: 2024/02/07 22:26:02 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		i;
	int		sign;
	int		nb;

	i = 0;
	nb = 0;
	sign = 1;
	str = (char *)nptr;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb = nb * sign;
	return (nb);
}

size_t	ft_strcpy(char *dst, char *src)
{
	size_t	j;
	size_t	len;

	len = ft_strlen(src);
	j = -1;
	while (src[++j])
		dst[j] = src[j];
	return (len);
}

void	change_dis(t_point *dis, t_pos start, t_data *data, int cases)
{
	int	i;

	i = 2;
	if (cases == 0)
	{
		while (sqrt((dis->x * dis->x) + (dis->y * dis->y)) < 20)
		{
			dis->x = (((((MINI_MAP_SIZE * MINI_MAP_COEF_LEN) / 2) + 20)
				+ (data->pos.dir_camX * i)) + (data->pos.norm_camX * i)) - start.p_x;
			dis->y = (((((MINI_MAP_SIZE * MINI_MAP_COEF_LEN) / 2) + 20)
				+ (data->pos.dir_camY * i)) + (data->pos.norm_camY * i)) - start.p_y;
			i++;
		}
	}
	else
	{
		while (sqrt((dis->x * dis->x) + (dis->y * dis->y)) < 20)
		{
			dis->x = (((((MINI_MAP_SIZE * MINI_MAP_COEF_LEN) / 2) + 20)
				+ (data->pos.dir_camX * i)) - (data->pos.norm_camX * i)) - start.p_x;
			dis->y = (((((MINI_MAP_SIZE * MINI_MAP_COEF_LEN) / 2) + 20)
				+ (data->pos.dir_camY * i)) - (data->pos.norm_camY * i)) - start.p_y;
			i++;
		}
	}
}
