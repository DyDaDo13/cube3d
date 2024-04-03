/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:46:34 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/03 12:02:50 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	ft_init_img4(t_data *data, int *i, int *j)
{
	data->textures.enemy1_d.img_ptr = mlx_xpm_file_to_image(data->mlx,
			"textures/sprites/enemy/normal_squeleton/death.xpm", i, j);
	data->textures.enemy1_d.img_pixels = mlx_get_data_addr(data->textures.enemy1_d.img_ptr,
			&data->textures.enemy1_d.bits_pix, &data->textures.enemy1_d.len,
			&data->textures.enemy1_d.endian);
	data->textures.shoot_POV.img_ptr = mlx_xpm_file_to_image(data->mlx,
			"textures/sprites/player/shooting_pov.xpm", i, j);
	data->textures.shoot_POV.img_pixels = mlx_get_data_addr(data->textures.shoot_POV.img_ptr,
			&data->textures.shoot_POV.bits_pix, &data->textures.shoot_POV.len,
			&data->textures.shoot_POV.endian);
}

void	ft_init_img3(t_data *data, int *i, int *j)
{
	data->textures.enemy1.img_ptr = mlx_xpm_file_to_image(data->mlx,
			"textures/sprites/enemy/normal_squeleton/normal_1.xpm", i, j);
	data->textures.enemy1.img_pixels = mlx_get_data_addr(data->textures.enemy1.img_ptr,
			&data->textures.enemy1.bits_pix, &data->textures.enemy1.len,
			&data->textures.enemy1.endian);
	data->textures.enemy2.img_ptr = mlx_xpm_file_to_image(data->mlx,
			"textures/sprites/enemy/normal_squeleton/normal_2.xpm", i, j);
	data->textures.enemy2.img_pixels = mlx_get_data_addr(data->textures.enemy2.img_ptr,
			&data->textures.enemy2.bits_pix, &data->textures.enemy2.len,
			&data->textures.enemy2.endian);
	data->textures.enemy3.img_ptr = mlx_xpm_file_to_image(data->mlx,
			"textures/sprites/enemy/normal_squeleton/normal_3.xpm", i, j);
	data->textures.enemy3.img_pixels = mlx_get_data_addr(data->textures.enemy3.img_ptr,
			&data->textures.enemy3.bits_pix, &data->textures.enemy3.len,
			&data->textures.enemy3.endian);
	data->textures.enemy4.img_ptr = mlx_xpm_file_to_image(data->mlx,
			"textures/sprites/enemy/normal_squeleton/normal_4.xpm", i, j);
	data->textures.enemy4.img_pixels = mlx_get_data_addr(data->textures.enemy4.img_ptr,
			&data->textures.enemy4.bits_pix, &data->textures.enemy4.len,
			&data->textures.enemy4.endian);
	ft_init_img4(data, i, j);
}

void	ft_init_img2(t_data *data, int *i, int *j)
{
	data->textures.EA.img_ptr = mlx_xpm_file_to_image(data->mlx,
			data->textures_path.EA, i, j);
	data->textures.EA.img_pixels = mlx_get_data_addr(data->textures.EA.img_ptr,
			&data->textures.EA.bits_pix, &data->textures.EA.len,
			&data->textures.EA.endian);
	data->img_win.img_ptr = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	data->img_win.img_pixels = mlx_get_data_addr(data->img_win.img_ptr,
			&data->img_win.bits_pix, &data->img_win.len,
			&data->img_win.endian);
	if (data->textures_path.DO)
	{
		data->textures.DO.img_ptr = mlx_xpm_file_to_image(data->mlx,
			data->textures_path.DO, i, j);
		data->textures.DO.img_pixels = mlx_get_data_addr(data->textures.DO.img_ptr,
			&data->textures.DO.bits_pix, &data->textures.DO.len,
			&data->textures.DO.endian);
	}
	data->textures.POV.img_ptr = mlx_xpm_file_to_image(data->mlx,
			"textures/sprites/player/normal_pov.xpm", i, j);
	data->textures.POV.img_pixels = mlx_get_data_addr(data->textures.POV.img_ptr,
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
	data->textures.NO.img_ptr = mlx_xpm_file_to_image(data->mlx,
			data->textures_path.NO, &i, &j);
	data->textures.NO.img_pixels = mlx_get_data_addr(data->textures.NO.img_ptr,
			&data->textures.NO.bits_pix, &data->textures.NO.len,
			&data->textures.NO.endian);
	data->textures.SO.img_ptr = mlx_xpm_file_to_image(data->mlx,
			data->textures_path.SO, &i, &j);
	data->textures.SO.img_pixels = mlx_get_data_addr(data->textures.SO.img_ptr,
			&data->textures.SO.bits_pix, &data->textures.SO.len,
			&data->textures.SO.endian);
	data->textures.WE.img_ptr = mlx_xpm_file_to_image(data->mlx,
			data->textures_path.WE, &i, &j);
	data->textures.WE.img_pixels = mlx_get_data_addr(data->textures.WE.img_ptr,
			&data->textures.WE.bits_pix, &data->textures.WE.len,
			&data->textures.WE.endian);
	data->textures.way_POV = 0;
	data->textures.add_POV = 0;
	data->textures.tex_POV = 0;	
	ft_init_img2(data, &i, &j);
}
