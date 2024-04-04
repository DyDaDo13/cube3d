/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:46:34 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/04 17:31:39 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	ft_init_img4(t_data *data, int *i, int *j)
{
	data->textures.enemy1_d.img_ptr = mlx_xpm_file_to_image(data->mlx,
			"textures/sprites/enemy/normal_squeleton/death.xpm", i, j);
	data->textures.enemy1_d.img_pixels
		= mlx_get_data_addr(data->textures.enemy1_d.img_ptr,
			&data->textures.enemy1_d.bits_pix, &data->textures.enemy1_d.len,
			&data->textures.enemy1_d.endian);
	data->textures.shoot_POV.img_ptr = mlx_xpm_file_to_image(data->mlx,
			"textures/sprites/player/shooting_pov.xpm", i, j);
	data->textures.shoot_POV.img_pixels
		= mlx_get_data_addr(data->textures.shoot_POV.img_ptr,
			&data->textures.shoot_POV.bits_pix, &data->textures.shoot_POV.len,
			&data->textures.shoot_POV.endian);
}

void	ft_init_img3(t_data *data, int *i, int *j)
{
	data->textures.enemy1.img_ptr = mlx_xpm_file_to_image(data->mlx,
			"textures/sprites/enemy/normal_squeleton/normal_1.xpm", i, j);
	data->textures.enemy1.img_pixels
		= mlx_get_data_addr(data->textures.enemy1.img_ptr,
			&data->textures.enemy1.bits_pix, &data->textures.enemy1.len,
			&data->textures.enemy1.endian);
	data->textures.enemy2.img_ptr = mlx_xpm_file_to_image(data->mlx,
			"textures/sprites/enemy/normal_squeleton/normal_2.xpm", i, j);
	data->textures.enemy2.img_pixels
		= mlx_get_data_addr(data->textures.enemy2.img_ptr,
			&data->textures.enemy2.bits_pix, &data->textures.enemy2.len,
			&data->textures.enemy2.endian);
	data->textures.enemy3.img_ptr = mlx_xpm_file_to_image(data->mlx,
			"textures/sprites/enemy/normal_squeleton/normal_3.xpm", i, j);
	data->textures.enemy3.img_pixels
		= mlx_get_data_addr(data->textures.enemy3.img_ptr,
			&data->textures.enemy3.bits_pix, &data->textures.enemy3.len,
			&data->textures.enemy3.endian);
	data->textures.enemy4.img_ptr = mlx_xpm_file_to_image(data->mlx,
			"textures/sprites/enemy/normal_squeleton/normal_4.xpm", i, j);
	data->textures.enemy4.img_pixels
		= mlx_get_data_addr(data->textures.enemy4.img_ptr,
			&data->textures.enemy4.bits_pix, &data->textures.enemy4.len,
			&data->textures.enemy4.endian);
	ft_init_img4(data, i, j);
}

void	ft_init_img2(t_data *data, int *i, int *j)
{
	data->textures.ea.img_ptr = mlx_xpm_file_to_image(data->mlx,
			data->textures_path.ea, i, j);
	data->textures.ea.img_pixels = mlx_get_data_addr(data->textures.ea.img_ptr,
			&data->textures.ea.bits_pix, &data->textures.ea.len,
			&data->textures.ea.endian);
	data->img_win.img_ptr = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	data->img_win.img_pixels = mlx_get_data_addr(data->img_win.img_ptr,
			&data->img_win.bits_pix, &data->img_win.len,
			&data->img_win.endian);
	if (data->textures_path.dor)
	{
		data->textures.dor.img_ptr = mlx_xpm_file_to_image(data->mlx,
				data->textures_path.dor, i, j);
		data->textures.dor.img_pixels
			= mlx_get_data_addr(data->textures.dor.img_ptr,
				&data->textures.dor.bits_pix, &data->textures.dor.len,
				&data->textures.dor.endian);
	}
	data->textures.POV.img_ptr = mlx_xpm_file_to_image(data->mlx,
			"textures/sprites/player/normal_pov.xpm", i, j);
	data->textures.POV.img_pixels
		= mlx_get_data_addr(data->textures.POV.img_ptr,
			&data->textures.POV.bits_pix, &data->textures.POV.len,
			&data->textures.POV.endian);
	ft_init_img3(data, i, j);
}

void	ft_init_img(t_data *data)
{
	int	i;
	int	j;

	j = 64;
	i = 64;
	data->textures.no.img_ptr = mlx_xpm_file_to_image(data->mlx,
			data->textures_path.no, &i, &j);
	data->textures.no.img_pixels = mlx_get_data_addr(data->textures.no.img_ptr,
			&data->textures.no.bits_pix, &data->textures.no.len,
			&data->textures.no.endian);
	data->textures.so.img_ptr = mlx_xpm_file_to_image(data->mlx,
			data->textures_path.so, &i, &j);
	data->textures.so.img_pixels = mlx_get_data_addr(data->textures.so.img_ptr,
			&data->textures.so.bits_pix, &data->textures.so.len,
			&data->textures.so.endian);
	data->textures.we.img_ptr = mlx_xpm_file_to_image(data->mlx,
			data->textures_path.we, &i, &j);
	data->textures.we.img_pixels = mlx_get_data_addr(data->textures.we.img_ptr,
			&data->textures.we.bits_pix, &data->textures.we.len,
			&data->textures.we.endian);
	data->textures.way_POV = 0;
	data->textures.add_POV = 0;
	data->textures.tex_POV = 0;
	data->pv = 5;
	ft_init_img2(data, &i, &j);
}
