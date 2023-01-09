#include "fdf.h"

int main(void)
{
	t_param	param;
	t_data	img;

	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 500, 500, "mlx 42");

	img.img = mlx_new_image(param.mlx, 500, 500);
	mlx_put_image_to_window (param.mlx, param.win, img.img, 0, 0);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	main_rotate(&img);
	mlx_key_hook(param.win, key_hook, &param);
	mlx_loop(param.mlx);
}
