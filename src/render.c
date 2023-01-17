
#include "fdf.h"

void	transform_move(t_data *data, t_cube *cube)
{
	int	i;

	i = 0;	
	printf("x_mv=%d\n",data->x_mv);
	while (i < data->map->width * data->map->height)
	{	
		cube[i].x += data->x_mv;
		i++;
		printf("%.f\n", data->cube_set[i].x);
	}
	printf("after tranform i is %d\n",i);
}

int	render(t_data *data)
{
	t_cube	*cube_set;
	t_plan	*plan_set;
	t_map	*map;

	cube_set = data->cube_set;
	map = data->map;

	transform_move(data, cube_set);	


	plan_set = (t_plan *)malloc(sizeof(t_plan) * (map->width * map->height));
	int	color;
	color = 0xFFFFFF;
	int	i;
	i = -1;
	while (++i < map->width * map->height)
		rotate3d(data, &(cube_set[i]), &(plan_set[i]));
	printf("%d~%d, %d~%d\n",map->width_min, map->width_max, map->height_min, map->height_max);
	print_center(plan_set, data, color, *map);
	return (0);
}
