/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_img2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:55:49 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/16 14:16:10 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

unsigned int	get_color(unsigned char R, unsigned char G, unsigned char B)
{
	unsigned int	dec;

	dec = (R << 16) | (G << 8) | B;
	return (dec);
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->len * y) + (x * (img->bits_pix / 8));
	*((unsigned int *)(offset + img->img_pixels)) = color;
}

unsigned int	img_take_color(t_data *data, int x, int y, int texture)
{
	int		offset;
	t_img	*img;

	if (texture == 0)
		img = &data->textures.no;
	else if (texture == 1)
		img = &data->textures.we;
	else if (texture == 2)
		img = &data->textures.so;
	else if (texture == 4)
		img = &data->textures.dor;
	else
		img = &data->textures.ea;
	offset = (img->len * y) + (x * (img->bits_pix / 8));
	return (*((unsigned int *)(offset + img->img_pixels)));
}

void	get_texture(t_algo *algo, int stepX, int stepY)
{
	if (algo->texture < 0)
	{
		if (algo->side == 0 && stepX == 1)
			algo->texture = 3;
		else if (algo->side == 0 && stepX == -1)
			algo->texture = 1;
		else if (algo->side == 1 && stepY == -1)
			algo->texture = 0;
		else
			algo->texture = 2;
	}
}

void	pix_texture(t_data *data, t_algo *algo, int *y)
{
	double	wallx;
	int		textx;
	double	step;
	double	textpos;
	int		texty;

	if (algo->side == 0)
		wallx = data->pos.p_y + algo->wall_dist * algo->raydir_acty;
	else
		wallx = data->pos.p_x + algo->wall_dist * algo->raydir_actx;
	wallx -= floor((wallx));
	textx = (int)(wallx * (double)(TEXT_SIZE));
	textx = check_side(textx, algo);
	step = 1.0 * TEXT_SIZE / (int)(WIN_Y / algo->wall_dist);
	textpos = (algo->start - WIN_Y / 2
			+ (int)(WIN_Y / algo->wall_dist) / 2) * step;
	*y -= 1;
	while (++*y < algo->end)
	{
		texty = (int)textpos & (TEXT_SIZE - 1);
		textpos += step;
		img_pixel_put(&data->img_win, algo->x, *y, ft_mix_color(
				img_take_color(data, textx, texty, algo->texture),
				0x000000, algo->wall_dist / 10));
	}
}
