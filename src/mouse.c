/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:44:54 by ozone             #+#    #+#             */
/*   Updated: 2024/04/03 16:22:01 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	set_mouse_center_screen(t_data *data)
{
	data->mouse.origin_x = (WIN_X / 2);
	data->mouse.origin_y = (WIN_Y / 2);
	mlx_mouse_move(data->mlx, data->win,
		data->mouse.origin_x, data->mouse.origin_y);
	return (0);
}
