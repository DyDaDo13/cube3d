/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:46:34 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/08 14:46:34 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

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
	ft_init_img2(data, &i, &j);
}
