/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 13:13:55 by dydado13          #+#    #+#             */
/*   Updated: 2024/04/24 16:22:30 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	check_around(char **tab, int row, int col)
{
	if (tab[row][col] && tab[row][col] == '0')
	{
		if (!tab[row][col + 1] || col - 1 < 0)
			return (1);
		if ((row + 1 < ft_strlen2(tab) && ft_strlen(tab[row + 1]) > col)
			&& (!tab[row + 1][col] || row - 1 < 0))
			return (1);
	}
	return (0);
}

void	f_fill(char **tab, t_point *size, int row, int col)
{
	if (row < 0 || col < 0 || row >= ft_strlen2(tab)
		|| col >= ft_strlen(tab[row]))
		return ;
	if (!tab[row][col])
		return ;
	if (check_around(tab, row, col) == 1)
		size->i = 1;
	if (tab[row][col] && (tab[row][col] == '.' || tab[row][col] == '1'))
		return ;
	if (tab[row][col] && (tab[row][col] == ' '))
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
