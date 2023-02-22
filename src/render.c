/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:33:26 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/22 17:28:17 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	heat_map(t_data *data)
{
	int		i;
	double	start;
	double	range;
	double	z;

	start = data->map->z_min;
	range = data->map->z_max - data->map->z_min;
	i = 0;
	while (i < data->map->size)
	{
		z = data->cube_set[i].z;
		if (start <= z && z < start + range * 0.25)
			data->cube_set[i].color = FIRSTCOLOR;
		else if (start + range * 0.25 <= z && z < start + range * 0.5)
			data->cube_set[i].color = SECONDCOLOR;
		else if (start + range * 0.5 <= z && z < start + range * 0.75)
			data->cube_set[i].color = THIRDCOLOR;
		else
			data->cube_set[i].color = FORTHCOLOR;
		i++;
	}
}

int	render(t_data *data)
{
	t_cube	*render;

	if (!data || !data->status)
		return (0);
	if (data->status == TOPVIEW)
		top_view(data);
	if (data->color)
		heat_map(data);
	render = transform_init(data, data->cube_set);
	if (!render)
		return (0);
	transform_scale(data, render);
	transform_rotate(data, render);
	transform_move(data, render);
	print_center(data, render);
	free(render);
	data->status = 0;
	return (0);
}
