/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:52:41 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/04 18:13:07 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include "fdf.h"

void	pixel_put_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		frame_x;
	int		frame_y;
	t_data	img;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	
	img.img = mlx_new_image(mlx_ptr, 500, 500);
	mlx_put_image_to_window (mlx_ptr, win_ptr, img.img, 10, 0);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	frame_x = 0;
	
	while (frame_x < 500)
	{
		frame_y = 0;
		while (frame_y < 500)
		{
			pixel_put_image(&img, frame_x, frame_y, 0xFFA500);
			frame_y += 50;
		}
		frame_x += 50;
	}


	mlx_loop(mlx_ptr);

}
