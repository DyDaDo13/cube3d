/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dydado13 <dydado13@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:19:20 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/24 16:28:04 by dydado13         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

char	**extra(char **cpy, char **tab)
{
	int	y;
	int	x;

	y = -1;
	while (tab[++y])
	{
		x = -1;
		while (tab[y][++x])
		{
			if (tab[y][x] == 'D')
				cpy[y][x] = '0';
			else
				cpy[y][x] = tab[y][x];
		}
	}
	return (cpy);
}

char	**map_dup(char **tab)
{
	char	**cpy;
	int		x;
	int		y;

	y = ft_strlen2(tab);
	cpy = malloc(sizeof(char *) * (y + 1));
	cpy[y] = NULL;
	y = -1;
	while (tab[++y])
	{
		x = -1;
		while (tab[y][++x])
			continue ;
		cpy[y] = malloc(sizeof(char) * (x + 1));
		cpy[y][x] = '\0';
	}
	cpy = extra(cpy, tab);
	return (cpy);
}
