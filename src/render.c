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
	if (data->scale == 1 && data->z_scale == 1)
		return ;
	while (i < data->map->width * data->map->height)
	{
		cube[i].x = cube[i].x * data->scale;
		cube[i].y = cube[i].y * data->scale;
		cube[i].z = cube[i].z * data->scale;
		cube[i].z = cube[i].z * data->z_scale;
		i++;
	}
}

t_cube	*transform_init(t_data *data, t_cube *cube)
{
	int		i;
	t_cube	*render;

	i = 0;
	render = (t_cube *)malloc(sizeof(t_cube) * data->map->size);
	if (!render)
		return (0);
	while (i < data->map->width * data->map->height)
	{	
		render[i].x = cube[i].x - data->x;
		render[i].y = cube[i].y - data->y;
		render[i].z = cube[i].z - data->z;
		i++;
	}
	return (render);
}

void	top_view(t_data *data)
{
	data->x_ro = 0;
	data->y_ro = 0;
	data->z_ro = 0;
}

int	render(t_data *data)
{
	t_cube	*render;

	if (!data || !data->status)
		return (0);
	if (data->status == 2)
		top_view(data);
	render = transform_init(data, data->cube_set);
	if (!render)
		return (0);
	transform_scale(data, render);
	transform_rotate(data, render);
	transform_move(data, render);
	print_center(data, render);
	data->status = 0;
	return (0);
}
