/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:45:01 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/13 17:32:20 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	int		fd;
	char	**tab;
	t_param	param;
	t_image	img;
	t_map	map;
	t_cube	*cube_set;
	t_plan	*plan_set;

	if (ac != 2)
	{
		perror("Error : ");
		return(-1);
	}
	// have to add 'check .fdf'
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error : ");
		return(-1);
	}

	// init mlx 
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 1000, 1000, "mlx 42");
	img.img = mlx_new_image(param.mlx, 1000, 1000);
	mlx_put_image_to_window (param.mlx, param.win, img.img, 0, 0);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// read map	
	tab = read_map(fd, &map);
	printf("width:%d,height:%d,dots:%d\n", map.width, map.height, map.width*map.height);

	// set cube
	cube_set = (t_cube *)malloc(sizeof(t_cube) * (map.width * map.height));
	make_cube(cube_set, tab, map);
	// check result of cube
//	for (int i = 0; i < map.width * map.height; i++)
//		printf("(%.f,%.f,%.f)\n",cube_set[i].x, cube_set[i].y, cube_set[i].z);

	// set plan
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

	// print center
	print_center(plan_set, &img, color, map);
	mlx_key_hook(param.win, key_hook, &param);
	mlx_loop(param.mlx);
}
