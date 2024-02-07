/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozone <ozone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:21:41 by ozone             #+#    #+#             */
/*   Updated: 2024/02/07 15:21:41 by ozone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (printf("Error: Too Many or Less Arguments\n"), 1);
	data.map = init_map(av[1], &data);
	if (data.map == NULL)
		return (1);
	// if (validate_file(&data) == 1)
	// 	return (1);
	get_args(&data);
	data.map = trunc_map(&data);
	init_game(&data);
	//print_args(&data);
	//print_map(data.map);
	free_all(&data);
	return (0);
}
