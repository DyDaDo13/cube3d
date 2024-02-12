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

/*NO = 0 | WE = 1 | SO = 2 | EA = 3*/
void	get_texture(t_algo *algo, int stepX, int stepY)
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

int	pix_texture(t_data *data, t_algo *algo, int x, double wall_dist)
{
	double	wallX;
	//int		texX;

	(void)x;
	if (algo->side == 0)
		wallX = data->pos.p_y + wall_dist * algo->dist_temp_rayY;
	else
		wallX = data->pos.p_x + wall_dist * algo->dist_temp_rayX;
	wallX -= floor((wallX));
	//texX = int(wallX * TEXT_SIZE);
	//if (side == 0 && algo->dist_temp_rayX > 0)
//		texX = TEXT_SIZE - text
	return (1);
}
