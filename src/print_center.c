
#include "fdf.h"

void	print_sero(t_plan *plan_set, t_data *img, int color, t_map map)
{
	int	col;
	int	row;
	int	i;
	int	j;

	col = 0;
	while (col < map.width)
	{
		row = 0;
		while(row < map.height - 1)
		{
			i = row * map.width + col;
			j = (row + 1) * map.width + col;
			draw_line(img, &(plan_set[i]), &(plan_set[j]), color);
			row++;
		}
		col++;
	}
}

void	print_garo(t_plan *plan_set, t_data *img, int color, t_map map)
{
	int	col;
	int	row;
	int	i;
	int	j;

	row = 0;
	while (row < map.height)
	{
		col = 0;
		while(col < map.width - 1)
		{
			i = row * map.width + col;
			j = row * map.width + col + 1;
			draw_line(img, &(plan_set[i]), &(plan_set[j]), color);
			col++;
		}
		row++;
	}
	
}

void	print_center(t_plan *plan_set, t_data *data, int color, t_map map)
{
	if (data->img)
		mlx_destroy_image(data->mlx,data->img);
	data->img = mlx_new_image(data->mlx, 1000, 800);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	print_sero(plan_set, data, color, map);
	print_garo(plan_set, data, color, map);
}
