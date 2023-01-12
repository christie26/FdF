/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:52:41 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/12 14:10:42 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	write_pixel_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_param *param)
{
	printf("This key's keycode is %d\n", keycode);
	if (keycode == ESC)
	{
		mlx_destroy_window(param->mlx, param->win);
		exit(EXIT_SUCCESS);
	}
	else
		printf("It's not ESC\n");
	return (0);
}

int	main(void)
{
	int		frame_x;
	int		frame_y;
	t_param	param;
	t_line	*line;
	t_data	img;

	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 500, 500, "mlx 42");

	img.img = mlx_new_image(param.mlx, 500, 500);
	mlx_put_image_to_window (param.mlx, param.win, img.img, 10, 0);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	frame_x = 0;
	while (frame_x < 500)
	{
		frame_y = 0;
		while (frame_y < 500)
		{
			if (frame_x % 50 == 0 || frame_y % 50 == 0)
				write_pixel_image(&img, frame_x, frame_y, 0x0044FF);
			frame_y += 1;
		}
		frame_x += 1;
	}
	line = tmp_set_line(10, 20, 300, 400);
	printf("set (%f,%f),(%f,%f)\n", line->start->x, line->start->y, line->end->x, line->end->y);
	draw_line(&img, line, 0x77CCFF);

	mlx_key_hook(param.win, key_hook, &param);
	mlx_loop(param.mlx);

}
