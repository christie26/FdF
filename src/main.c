/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:45:01 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/19 12:45:39 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_map	*map;
	t_cube	*cube_set;

	if (ac != 2)
	{
		perror("Error : ");
		return (-1);
	}
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (0);
	cube_set = get_cube(map, av[1]);
	if (!cube_set)
		exit(1);
	data_init(&data, map);
	data.map = map;
	data.cube_set = cube_set;
	mlx_hook(data.win, 2, 0, key_press, &data);
	mlx_hook(data.win, 17, 0, win_close, 0);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
