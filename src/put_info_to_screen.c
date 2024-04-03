/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_info_to_screen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:02:16 by ozone             #+#    #+#             */
/*   Updated: 2024/04/03 16:39:26 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	put_info_on_screen(t_data *data)
{
	int		fov;
	char	*temp;

	fov = (int)((atan(sqrt(sqr(data->pos.norm_camX)
						+ sqr(data->pos.norm_camY))
					/ sqrt(sqr(data->pos.dir_camX)
						+ sqr(data->pos.dir_camY))) * 2) * 180 / 3.14);
	temp = ft_itoa(fov);
	mlx_string_put(data->mlx, data->win, WIN_X - 60, 20, 0x000000, "FOV :");
	mlx_string_put(data->mlx, data->win, WIN_X - 25, 20, 0x0000ff, temp);
	free(temp);
}
