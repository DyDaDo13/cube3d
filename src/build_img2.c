/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_img2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 11:55:49 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/09 12:05:40 by ozone            ###   ########.fr       */
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
