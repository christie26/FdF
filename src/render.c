
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

void	transform_scale(t_data *data, t_cube *cube)
{
	int	i;

	i = 0;	
	while (i < data->map->width * data->map->height)
	{	
		cube[i].x += cube[i].x * data->scale;
		cube[i].y += data->y_mv;
		cube[i].z += data->z_mv;
		i++;
	}
}

int	render(t_data *data)
{
	t_plan	*plan_set;
	t_map	*map;

	map = data->map;
	if (data->status)
		return (0);
	printf("%d~%d %d~%d %d~%d\n",map->x_min, map->x_max, map->y_min, map->y_max, map->z_min, map->z_max);
	transform_move(data, data->cube_set);
	transform_scale(data, data->cube_set);
	transform_rotate(data, data->cube_set);

	plan_set = (t_plan *)malloc(sizeof(t_plan) * (map->width * map->height));
	int	color;
	color = 0xFFFFFF;
	get_plan(data, data->cube_set, plan_set);
	print_center(plan_set, data, color, *map);
	data_reset(data);
	return (0);
}
