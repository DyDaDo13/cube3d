/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:30:56 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/16 15:06:58 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	destroy_all_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->textures.ea.img_ptr);
	mlx_destroy_image(data->mlx, data->textures.we.img_ptr);
	mlx_destroy_image(data->mlx, data->textures.no.img_ptr);
	mlx_destroy_image(data->mlx, data->textures.so.img_ptr);
	if (data->textures_path.dor)
		mlx_destroy_image(data->mlx, data->textures.dor.img_ptr);
	if (data->hardmode == 1)
	{
		mlx_destroy_image(data->mlx, data->textures.enemy1.img_ptr);
		mlx_destroy_image(data->mlx, data->textures.enemy2.img_ptr);
		mlx_destroy_image(data->mlx, data->textures.enemy3.img_ptr);
		mlx_destroy_image(data->mlx, data->textures.enemy4.img_ptr);
		mlx_destroy_image(data->mlx, data->textures.enemy1_d.img_ptr);
	}
	mlx_destroy_image(data->mlx, data->textures.pov.img_ptr);
	mlx_destroy_image(data->mlx, data->textures.shoot_pov.img_ptr);
	mlx_destroy_image(data->mlx, data->textures.heart_empty.img_ptr);
	mlx_destroy_image(data->mlx, data->textures.heart_full.img_ptr);
	mlx_destroy_image(data->mlx, data->img_win.img_ptr);
}

int	ft_stop(t_data *data)
{
	destroy_all_images(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_all(data);
	if (data->enemy)
		free(data->enemy);
	exit(0);
	return (0);
}

int	take_pix(t_img *img, int x, int y)
{
	int	offset;

	if (x < 0 || y < 0)
		return (0);
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

void	draw_mini_map_pix(t_data *data, int x, int y, t_pos *pos_map)
{
	int	len;

	if ((int)pos_map->p_y >= 0)
		len = ft_strlen(data->map[(int)pos_map->p_y]);
	else
		len = 0;
	if ((pos_map->p_x >= 0 && pos_map->p_y >= 0)
		&& (pos_map->p_x < len && pos_map->p_y < data->map_leny)
		&& data->map[(int)pos_map->p_y][(int)pos_map->p_x] == '1')
		img_pixel_put(&data->img_win, x, y, ft_mix_color(take_pix
				(&data->img_win, x, y), 0xF03A1A, 0.5));
	if ((pos_map->p_x >= 0 && pos_map->p_y >= 0)
		&& (pos_map->p_x < len && pos_map->p_y < data->map_leny)
		&& data->map[(int)pos_map->p_y][(int)pos_map->p_x] == 'D')
		img_pixel_put(&data->img_win, x, y, ft_mix_color(take_pix
				(&data->img_win, x, y), 0x5D83F5, 0.5));
	else
		img_pixel_put(&data->img_win, x, y, ft_mix_color(take_pix
				(&data->img_win, x, y), 0xC3C0BD, 0.5));
}
