
#include "fdf.h"

void	data_init(t_data *data)
{
	data->x_mv = 0;
	data->y_mv = 0;
	data->z_mv = 0;
	data->x_ro = 15;
	data->y_ro = 45;
	data->z_ro = 15;
	data->status = 0;
	data->scale = 50;	
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 800, "mlx 42");
//	data->img = mlx_new_image(data->mlx, 1000, 800);
//	mlx_put_image_to_window (data->mlx, data->win, data->img, 0, 0);
//	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	return ;
}

void	data_reset(t_data *data)
{
	data->x_mv = 0;
	data->y_mv = 0;
	data->z_mv = 0;
	data->x_ro = 0;
	data->y_ro = 0;
	data->z_ro = 0;
	data->status = 1;	
	data->scale = 1;	
}
