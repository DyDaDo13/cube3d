/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:13:55 by dydado13          #+#    #+#             */
/*   Updated: 2024/02/09 12:59:16 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	f_fill(char **tab, t_point *size, int row, int col)
{
	if (row < 0 || col < 0 || !tab[row][col])
		return ;
	if (tab[row][col] == '.' || tab[row][col] == '1')
		return ;
	if (tab[row][col] == ' ')
	{
		tab[row][col] = '.';
		size->i = 1;
	}
	tab[row][col] = '.';
	f_fill(tab, size, row -1, col);
	f_fill(tab, size, row +1, col);
	f_fill(tab, size, row, col - 1);
	f_fill(tab, size, row, col + 1);
}

void	flood_fill(char **tab, t_point *size, t_point *begin, t_data *data)
{
	char	**map;
	int		i;

	(void)data;
	i = -1;
	size->i = 0;
	size->x = 0;
	size->y = 0;
	map = map_dup(tab);
	f_fill(map, size, begin->y, begin->x);
	while (map[++i])
		free(map[i]);
	free(map);
}
