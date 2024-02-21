/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:24:26 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/21 12:40:28 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	mouse_move(int x, int y, t_data *data)
{
	int		x_distance;
	double	rot_coef;
	(void)y;

	x_distance = 0;
	if (x < (WIN_X / 2))
		x_distance = x - (WIN_X / 2);
	else if (x > (WIN_X / 2))
		x_distance = x - (WIN_X / 2);
	rot_coef = (double)x_distance / (double)SENSIVITY;
	if (data->mouse.mouse_lock == 1)
	{
		ft_rotation(data, rot_coef);
		set_mouse_center_screen(data);
	}
	return (0);
}

