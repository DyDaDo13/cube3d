/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:19:20 by lle-saul          #+#    #+#             */
/*   Updated: 2024/02/08 19:19:50 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

char	**map_dup(char **tab)
{
	char    **cpy;
	int		x;
	int		y;

	y = ft_strlen2(tab);
	cpy = malloc(sizeof(char*) * (y + 1));
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
	y = -1;
	while (tab[++y])
	{
		x = -1;
		while (map[y][++x])
			cpy[y][x] = map[y][x];
	}
	return (cpy);
}
