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

int main(int ac, char **av)
{
	t_data	data;
	t_map	*map;
	t_cube	*cube_set;

	if (ac != 2)
	{
		perror("Error : ");
		return(-1);
	}
	map = ft_calloc(1, sizeof(t_map));
	cube_set = get_cube(map, av[1]);

	printf("%d X %d\n", map->width, map->height);
	if (!cube_set)
		exit(1);
	data_init(&data);
	data.cube_set = cube_set;
	data.map = map;
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);	
}
