/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_img2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:55:49 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/09 22:19:39 by dydado13         ###   ########.fr       */
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
		img = &data->textures.NO;
	else if (texture == 1)
		img = &data->textures.WE;
	else if (texture == 2)
		img = &data->textures.SO;
	else
		img = &data->textures.EA;
	offset = (img->len * y) + (x * (img->bits_pix / 8));
	return (*((unsigned int *)(offset + img->img_pixels)));
}

/*NO = 0 | WE = 1 | SO = 2 | EA = 3*/
void	get_texture(t_algo *algo, int stepX, int stepY)
{
	if (algo->texture < 0)
	{
		if (algo->side == 1 && stepX == 1)
			algo->texture = 1;
		else if (algo->side == 1 && stepX == -1)
			algo->texture = 3;
		else if (algo->side == 0 && stepY == -1)
			algo->texture = 0;
		else
			algo->texture = 2;
	}
}

void	pix_texture(t_data *data, t_algo *algo, int *y)
{
	double	wallX;
	int		textX;
	double	step;
	double	textpos;
	int		textY;

	if (algo->side == 0)
		wallX = data->pos.p_y + algo->wall_dist * algo->rayDir_actY;
	else
		wallX = data->pos.p_x + algo->wall_dist * algo->rayDir_actX;
	wallX -= floor((wallX));
	textX = (int)(wallX * (double)(TEXT_SIZE));
	if (algo->side == 0 && algo->rayDir_actX < 0)
		textX = TEXT_SIZE - textX - 1;
	if (algo->side == 1 && algo->rayDir_actY > 0)
		textX = TEXT_SIZE - textX - 1;
	step = 1.0 * TEXT_SIZE / (int)(WIN_Y / algo->wall_dist);
	textpos = (algo->start - WIN_Y / 2 + (int)(WIN_Y / algo->wall_dist) / 2) * step;
	while (*y < algo->end)
	{
		textY = (int)textpos & (TEXT_SIZE - 1);
		textpos += step;
		img_pixel_put(&data->img_win, algo->x, *y, img_take_color(data, textX, textY, algo->texture));
		++*y;
	}
}
