/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:19:20 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/24 19:39:34 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

char	**make_border(char **cpy, char **tab)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (ft_strlen2(tab) + 2))
	{
		x = -1;
		while (++x < (ft_max_size(tab) + 2))
		{
			if (y == 0 || y == (ft_strlen2(tab) + 1))
				cpy[y][x] = '2';
			else if (x == 0 || x == (ft_max_size(tab) + 1))
				cpy[y][x] = '2';
			else
				cpy[y][x] = ' ';
		}
	}
	return (cpy);
}

char	**extra(char **cpy, char **tab)
{
	int	xb;
	int	xs;
	int	yb;
	int	ys;

	cpy = make_border(cpy, tab);
	yb = 0;
	ys = -1;
	while (++yb, tab[++ys])
	{
		xs = -1;
		xb = 0;
		while (++xb, tab[ys][++xs])
		{
			if (tab[ys][xs] == 'D')
				cpy[yb][xb] = '0';
			else if (tab[ys][xs] == ' ')
				cpy[yb][xb] = '2';
			else
				cpy[yb][xb] = tab[ys][xs];
			while (xs + 1 == ft_strlen(tab[ys]) && xb++ < ft_max_size(tab))
				cpy[yb][xb] = '2';
		}
	}
	return (cpy);
}

char	**map_dup(char **tab)
{
	char	**cpy;
	int		y;

	y = ft_strlen2(tab) + 2;
	cpy = malloc(sizeof(char *) * (y + 1));
	cpy[y] = NULL;
	y = -1;
	while (++y < (ft_strlen2(tab) + 2))
	{
		cpy[y] = malloc(sizeof(char) * (ft_max_size(tab) + 3));
		cpy[y][ft_max_size(tab) + 2] = '\0';
	}
	cpy = extra(cpy, tab);
	return (cpy);
}
