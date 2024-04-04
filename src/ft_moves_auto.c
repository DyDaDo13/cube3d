/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_auto.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:55:21 by ozone             #+#    #+#             */
/*   Updated: 2024/02/20 14:00:12 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	move_diag_2(t_data *data)
{
	if (data->key_move == 6 || data->key_move == 206
		|| data->key_move == 106)
	{
		if (data->key_move == 206)
			ft_rotation_left(data);
		else if (data->key_move == 106)
			ft_rotation_right(data);
		ft_move(data, 1);
		ft_move(data, 2);
	}
	else if (data->key_move == 9 || data->key_move == 209
		|| data->key_move == 109)
	{
		if (data->key_move == 209)
			ft_rotation_left(data);
		else if (data->key_move == 109)
			ft_rotation_right(data);
		ft_move(data, 1);
		ft_move(data, 3);
	}
}

void	move_diag(t_data *data)
{
	if (data->key_move == 5 || data->key_move == 205 || data->key_move == 105)
	{
		if (data->key_move == 205)
			ft_rotation_left(data);
		else if (data->key_move == 105)
			ft_rotation_right(data);
		ft_move(data, 0);
		ft_move(data, 2);
	}
	else if (data->key_move == 8
		|| data->key_move == 208 || data->key_move == 108)
	{
		if (data->key_move == 208)
			ft_rotation_left(data);
		else if (data->key_move == 108)
			ft_rotation_right(data);
		ft_move(data, 0);
		ft_move(data, 3);
	}
	move_diag_2(data);
}

void	ft_key_moves2(t_data *data)
{
	if (data->key_move == 4 || data->key_move == 204
		|| data->key_move == 104)
	{
		if (data->key_move == 204)
			ft_rotation_left(data);
		else if (data->key_move == 104)
			ft_rotation_right(data);
		ft_move(data, 2);
	}
	else if (data->key_move == 7 || data->key_move == 207
		|| data->key_move == 107)
	{
		if (data->key_move == 207)
			ft_rotation_left(data);
		else if (data->key_move == 107)
			ft_rotation_right(data);	
		ft_move(data, 3);
	}
	else if (data->key_move == 100)
		ft_rotation_right(data);
	else if (data->key_move == 200)
		ft_rotation_left(data);
	else
		move_diag(data);
}

int	ft_key_moves(t_data *data)
{
	if (data->key_move == 1 || data->key_move == 201 || data->key_move == 101)
	{
		if (data->key_move == 201)
			ft_rotation_left(data);
		else if (data->key_move == 101)
			ft_rotation_right(data);
		ft_move(data, 0);
	}
	else if (data->key_move == 2 || data->key_move == 202
		|| data->key_move == 102)
	{
		if (data->key_move == 202)
			ft_rotation_left(data);
		else if (data->key_move == 102)
			ft_rotation_right(data);
		ft_move(data, 1);
	}
	ft_key_moves2(data);
	build_img(data);
	return (0);
}
