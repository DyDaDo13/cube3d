/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-saul <lle-saul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:24:46 by lle-saul          #+#    #+#             */
/*   Updated: 2024/04/25 17:09:35 by lle-saul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	ft_lenxd(char *str)
{
	int	i;
	int	space;

	space = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			space ++;
		if (str[i] == '.' || str[i] == '/' || str[i] == '~')
			break ;
		i++;
	}
	if (space == 1)
		return (i);
	return (0);
}

int	ft_color_check1(char *str)
{
	int	i;
	int	det;
	int	virg;

	det = 0;
	i = 1;
	virg = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != ','
			&& !(str[i] >= '0' && str[i] <= '9') && str[i] != '\n')
			det++;
		if (str[i] == ',')
			virg++;
		i++;
	}
	if (det != 0 || virg != 2)
		return (1);
	return (0);
}
