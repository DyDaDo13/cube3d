/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:57:14 by ozone             #+#    #+#             */
/*   Updated: 2024/04/03 15:57:25 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	check_side(int textx, t_algo *algo)
{
	if (algo->side == 0 && algo->rayDir_actX < 0)
		textx = TEXT_SIZE - textx - 1;
	if (algo->side == 1 && algo->rayDir_actY > 0)
		textx = TEXT_SIZE - textx - 1;
	return (textx);
}
