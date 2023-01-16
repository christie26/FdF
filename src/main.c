/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:45:01 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/16 17:11:14 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	char	**tab;
	t_data	*data;
	t_map	map;
	t_cube	*cube_set;
	t_plan	*plan_set;

	if (ac != 2)
	{
		perror("Error : ");
		return(-1);
	}
	// read map & set cube	
	tab = open_file(&map, av[1]);
	if (!tab)
		exit(1);
	cube_set = (t_cube *)malloc(sizeof(t_cube) * (map.width * map.height));
	make_cube(cube_set, tab, map);
	
	data = data_init();
	
	// set plan & print
	plan_set = (t_plan *)malloc(sizeof(t_plan) * (map.width * map.height));
	t_angle	angle;
	angle.x = 15;
	angle.y = -20;
	angle.z = 20;
	int	color;
	color = 0xFFFFFF;
	int	i;
	i = -1;	
	while (++i < map.width * map.height)
		rotate3d(&(cube_set[i]), &(plan_set[i]), angle.x, angle.y, angle.z, &map);
	printf("%d~%d, %d~%d\n",map.width_min, map.width_max, map.height_min, map.height_max);
	
	print_center(plan_set, data, color, map);
	mlx_key_hook(data->win, key_hook, &data);
	mlx_loop(data->mlx);
}
