/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:45:01 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/13 17:28:35 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	t_param	param;
	t_image	img;
	int		fd;
	char	**tab;
	t_map	map;
	t_cube	*cube_set;
	t_plan	*plan_set;

	if (ac != 2)
	{
		perror("Error : ");
		return(-1);
	}
	// check .fdf 
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error : ");
		return(-1);
	}

	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 500, 500, "mlx 42");
	img.img = mlx_new_image(param.mlx, 500, 500);
	mlx_put_image_to_window (param.mlx, param.win, img.img, 0, 0);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	tab = read_map(fd, &map);
	
	printf("%d,%d,%d\n", map.width, map.height, map.width*map.height);
	cube_set = (t_cube *)malloc(sizeof(t_cube) * (map.width * map.height));
	make_cube(cube_set, tab, map);

	t_angle	angle;
	angle.x = 20;
	angle.y = 45;
	angle.z = 0;
	int	color;
	color = 0xFFFFFF;

	plan_set = (t_plan *)malloc(sizeof(t_plan) * (map.width * map.height));

//	main_rotate(&img);
	mlx_key_hook(param.win, key_hook, &param);
	mlx_loop(param.mlx);
}
