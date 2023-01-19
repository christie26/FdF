
#include "fdf.h"

void	transform_move(t_data *data, t_cube *cube)
{
	int	i;

	i = 0;
	while (i < data->map->width * data->map->height)
	{	
		cube[i].x += data->x_mv;
		cube[i].y += data->y_mv;
		cube[i].z += data->z_mv;
		i++;
	}
}

void	transform_init(t_data *data, t_cube *cube)
{
	int	i;

	i = 0;
	while (i < data->map->width * data->map->height)
	{	
		cube[i].x -= data->x;
		cube[i].y -= data->y;
		cube[i].z -= data->z;
		i++;
	}
}

void	transform_scale(t_data *data, t_cube *cube, int flag)
{
	int	i;

	i = 0;
	if (data->scale == 1)
		return ;
	while (i < data->map->width * data->map->height)
	{
		if (flag == 1)
		{
			cube[i].x = cube[i].x * data->scale;
			cube[i].y = cube[i].y * data->scale;
		}
		cube[i].z = cube[i].z * data->scale;
		i++;
	}
//	data->scale = 1;
}

void	top_view(t_data *data)
{
	data->x_ro = -30;
	data->y_ro = 0;
	data->z_ro = 30;
	// haven't finished
}

int	render(t_data *data)
{
	t_plan	*plan_set;
	t_map	*map;
	int		color;

	map = data->map;
	if (!data->status)
		return (0);
	if (data->status == 3)
		top_view(data);
	transform_init(data, data->cube_set);
	data->x = data->x_mv / 2;
	data->y = data->y_mv / 2;
	data->z = data->z_mv / 2;
	transform_scale(data, data->cube_set, data->status);
	transform_rotate(data, data->cube_set);
	transform_move(data, data->cube_set);
	plan_set = (t_plan *)malloc(sizeof(t_plan) * (map->width * map->height));
	color = 0xFFFFFF;
	get_plan(data, data->cube_set, plan_set);
	print_center(plan_set, data, color, *map);
	data_reset(data);
	return (0);
}
