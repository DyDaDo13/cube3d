/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:30:56 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/19 14:41:31 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	destroy_all_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->textures.EA.img_ptr);
	mlx_destroy_image(data->mlx, data->textures.WE.img_ptr);
	mlx_destroy_image(data->mlx, data->textures.NO.img_ptr);
	mlx_destroy_image(data->mlx, data->textures.SO.img_ptr);
	mlx_destroy_image(data->mlx, data->img_win.img_ptr);
}

int	ft_stop(t_data *data)
{
	destroy_all_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_all(data);
	exit(0);
	return (0);
}

int	take_pix(t_img *img, int x, int y)
{
	int	offset;
	
	offset = (img->len * y) + (x * (img->bits_pix / 8));
	return (*((unsigned int *)(offset + img->img_pixels)));
}

void	trace_line(t_img *img, t_pos start, t_point dis, int color)
{
	int		step;
	double	x_step;
	double	y_step;
	int		i;

	if (abs(dis.x) > abs(dis.y))
		step = abs(dis.x);
	else
		step = abs(dis.y);
	x_step = (double)dis.x / (double)step;
	y_step = (double)dis.y / (double)step;
	i = 0;
	while (i < step)
	{
		start.p_x += x_step;
		start.p_y += y_step;
		if (start.p_x >= 20 && start.p_y >= 20 && start.p_x < ((MINI_MAP_SIZE
			* MINI_MAP_COEF_LEN) + 20.0) && start.p_y < ((MINI_MAP_SIZE
			* MINI_MAP_COEF_LEN) + 20.0))
			img_pixel_put(img, (int)start.p_x, (int)start.p_y, color);
		i++;
	}
}
