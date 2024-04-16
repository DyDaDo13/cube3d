/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:57:14 by ozone             #+#    #+#             */
/*   Updated: 2024/04/04 15:31:45 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	check_side(int textx, t_algo *algo)
{
	if (algo->side == 0 && algo->raydir_actx < 0)
		textx = TEXT_SIZE - textx - 1;
	if (algo->side == 1 && algo->raydir_acty > 0)
		textx = TEXT_SIZE - textx - 1;
	return (textx);
}
