/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:13:55 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/25 07:51:05 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	check_around(char **tab, int row, int col)
{
	if (tab[row][col] && tab[row][col] == '0')
	{
		if (tab[row][col + 1] == '2' || tab[row][col - 1] == '2')
			return (1);
		if (tab[row + 1][col] == '2' || tab[row - 1][col] == '2')
			return (1);
	}
	return (0);
}

void	f_fill(char **tab, t_point *size, int row, int col)
{
	if (check_around(tab, row, col) == 1)
		size->i = 1;
	if (tab[row][col] && (tab[row][col] == '.' || tab[row][col] == '1'
		|| tab[row][col] == '2'))
		return ;
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
	find_p(map, begin, data);
	f_fill(map, size, begin->y, begin->x);
	while (map[++i])
		free(map[i]);
	free(map);
}
