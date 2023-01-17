
#include "fdf.h"

void	transform_move(t_data *data)
{
	int	i;

	i = 0;	
	while (i < data->map->width * data->map->height)
		data->cube_set[i].x += data->x_mv;
	printf("after tranform i is %d\n",i);	
}

int	render(t_data *data)
{
	t_cube	*cube_set;
	t_plan	*plan_set;
	t_map	*map;

	cube_set = data->cube_set;
	map = data->map;
	plan_set = (t_plan *)malloc(sizeof(t_plan) * (map->width * map->height));
	t_angle	angle;
	angle.x = 15;
	angle.y = -20;
	angle.z = 20;
	int	color;
	color = 0xFFFFFF;
	int	i;
	i = -1;
	while (++i < map->width * map->height)
		rotate3d(&(cube_set[i]), &(plan_set[i]), angle, map);
	printf("%d~%d, %d~%d\n",map->width_min, map->width_max, map->height_min, map->height_max);
	print_center(plan_set, data, color, *map);
	return (0);
}
