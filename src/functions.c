/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:25:43 by ozone             #+#    #+#             */
/*   Updated: 2024/02/07 22:26:02 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	ft_atoi(const char *nptr)
{
	char	*str;
	int		i;
	int		sign;
	int		nb;

	i = 0;
	nb = 0;
	sign = 1;
	str = (char *)nptr;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	nb = nb * sign;
	return (nb);
}

size_t	ft_strcpy(char *dst, char *src)
{
	size_t	j;
	size_t	len;

	len = ft_strlen(src);
	j = -1;
	while (src[++j])
		dst[j] = src[j];
	return (len);
}
