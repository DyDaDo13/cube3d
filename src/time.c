/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 08:38:52 by dylmarti          #+#    #+#             */
/*   Updated: 2024/04/23 16:39:21 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

double	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((double)(current_time.tv_sec)
		+ ((double)current_time.tv_usec / 1000000.0));
}
