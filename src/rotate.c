/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:33:06 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/13 16:44:14 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	rotate_z(double angle, t_cube *cube)
{
	double	x;
	double	y;

	x = cube->x;
	y = cube->y;
	cube->x = x * cos(angle) + y * sin(angle);
	cube->y = x * -sin(angle) + y * cos(angle);
	return ;
}

void	rotate_y(double angle, t_cube *cube)
{
	double	x;
	double	z;

	x = cube->x;
	z = cube->z;
	cube->x = x * cos(angle) - z * sin(angle);
	cube->z = x * sin(angle) + z * cos(angle);
	return ;
}

void	rotate_x(double angle, t_cube *cube)
{
	double	y;
	double	z;

	y = cube->y;
	z = cube->z;
	cube->y = y * cos(angle) + z * sin(angle);
	cube->z = y * -sin(angle) + z * cos(angle);
	return ;
}

void	check_limit(t_plan plan, t_map *map)
{
	if (plan.x > map->width_max)
		map->width_max = plan.x;
	if (plan.x < map->width_min)
		map->width_min = plan.x;
	if (plan.y > map->height_max)
		map->height_max = plan.y;
	if (plan.y < map->height_min)
		map->height_min = plan.y;
}

void	rotate3d(t_data *data, t_cube *cube, t_plan *plan)
{
//	printf("check\n");
	rotate_y(data->y_ro, cube);
	rotate_x(data->x_ro, cube);
	rotate_z(data->z_ro, cube);
	plan->x =  500 + (int)(50 * cube->x);
	plan->y =  500 + (int)(50 * cube->y);
	check_limit(*plan, data->map);
	return ;
}
