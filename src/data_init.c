
#include "fdf.h"

t_data	*data_init(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	data->x_mv = 0;
	data->y_mv = 0;
	data->z_mv = 0;
	data->x_ro = 15;
	data->y_ro = -20;
	data->z_ro = 20;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 1000, "mlx 42");
	data->img = mlx_new_image(data->mlx, 1000, 1000);
	mlx_put_image_to_window (data->mlx, data->win, data->img, 0, 0);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	return (data);
}

