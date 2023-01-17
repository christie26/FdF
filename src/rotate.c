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

void	check_limit(t_plan project, t_map *map)
{
	if (project.x > map->width_max)
		map->width_max = project.x;
	if (project.x < map->width_min)
		map->width_min = project.x;
	if (project.y > map->height_max)
		map->height_max = project.y;
	if (project.y < map->height_min)
		map->height_min = project.y;
}

void	rotate3d(t_cube *cube, t_plan *plan, t_angle angle, t_map *map)
{
	rotate_y(angle.y, cube);
	rotate_x(angle.x, cube);
	rotate_z(angle.z, cube);
	plan->x =  500 + (int)(50 * cube->x);
	plan->y =  500 + (int)(50 * cube->y);
	check_limit(*plan, map);
	return ;
}
