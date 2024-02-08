/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:36:29 by ozone             #+#    #+#             */
/*   Updated: 2024/02/07 22:45:24 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->len * y) + (x * (img->bits_pix / 8));	
	*((unsigned int *)(offset + img->img_pixels)) = color;
}

int	ft_stop(t_data *data)
{
	//destroy_all_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_all(data);
	exit(0);
	return (0);
}

int	ft_key_check(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_stop(data);
	return (0);
}

int	ft_display(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (perror("Error"), 1);
	data->win = mlx_new_window(data->mlx, WIN_X, WIN_Y, "Mon Q");
	if (data->win == NULL)
		return (mlx_destroy_display(data->mlx), free(data->mlx), 1);
	ft_init_img(data);
	build_img(data);
	mlx_hook(data->win, 3, (1L << 0) + (1L << 1), ft_key_check, data);
	mlx_hook(data->win, 17, 0L, ft_stop, data);
	mlx_loop(data->mlx);
	return (0);
}