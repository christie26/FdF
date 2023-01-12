/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:45:01 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/12 17:25:10 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int ac, char **av)
{
	t_param	param;
	t_data	img;
	int		fd;
	char	*buf;

	if (ac != 2)
	{
		perror("Error: ");
		return(-1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error: ");
		return(-1);
	}
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 500, 500, "mlx 42");

	img.img = mlx_new_image(param.mlx, 500, 500);
	mlx_put_image_to_window (param.mlx, param.win, img.img, 0, 0);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	buf = get_next_line(fd);
	printf("buf is %s\n", buf);
	
	// map info -> width, height 
	// keep getting next line, while checking map valid
	//


	main_rotate(&img);
	mlx_key_hook(param.win, key_hook, &param);
	mlx_loop(param.mlx);
}
