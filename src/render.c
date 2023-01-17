
#include "fdf.h"

void	transform_move(t_data *data, t_cube *cube)
{
	int	i;

	i = 0;	
	while (i < data->map->width * data->map->height)
	{	
		cube[i].x += data->x_mv;
		i++;
	}
}

int	render(t_data *data)
{
	t_cube	*cube_set;
	t_plan	*plan_set;
	t_map	*map;

	cube_set = data->cube_set;
	map = data->map;
	if (data->status)
		return (0);
	transform_move(data, data->cube_set);
//	transform_rotate(data);
//	transform_zoom(data);
	plan_set = (t_plan *)malloc(sizeof(t_plan) * (map->width * map->height));
	int	color;
	color = 0xFFFFFF;
	int	i;
	i = -1;
	while (++i < map->width * map->height)
		rotate3d(data, &(cube_set[i]), &(plan_set[i]));
	printf("%d~%d, %d~%d\n",map->width_min, map->width_max, map->height_min, map->height_max);
	print_center(plan_set, data, color, *map);
	data_reset(data);
	return (0);
}
