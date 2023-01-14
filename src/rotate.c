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

void	rotation_z(double angle, t_cube *cube)
{
	double	x;
	double	y;

	x = cube->x;
	y = cube->y;
	cube->x = x * cos(angle) + y * sin(angle);
	cube->y = x * -sin(angle) + y * cos(angle);
	return ;
}

void	rotation_y(double angle, t_cube *cube)
{
	double	x;
	double	z;

	x = cube->x;
	z = cube->z;
	cube->x = x * cos(angle) - z * sin(angle);
	cube->z = x * sin(angle) + z * cos(angle);
	return ;
}

void	rotation_x(double angle, t_cube *cube)
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

void	rotate3d(t_cube *origin, t_plan	*project, double angle_x, double angle_y, double angle_z, t_map *map)
{
//	printf("(%.f,%.f,%.f)\n", origin->x, origin->y, origin->z);
	rotation_y(angle_y, origin);
	rotation_x(angle_x, origin);
	rotation_z(angle_z, origin);
	project->x =  500 + (int)(50 * origin->x);
	project->y =  500 + (int)(50 * origin->y);
	check_limit(*project, map);
//	printf("(%d,%d)\n", project->x, project->y);
	return ;
}

// have to make new function work like this 
void	main_rotate(t_image *img)
{
	t_cube	**cube_set;
	t_plan	**plan_set;
	t_angle	angle;
	double	color;
	int	i;
	
	//don't have to use double pointer
	cube_set = (t_cube **)malloc(sizeof(t_cube *));
	plan_set = (t_plan **)malloc(sizeof(t_plan *));
	i = 0;
	while (i < 8)
	{
		cube_set[i] = (t_cube *)malloc(sizeof(t_cube));
		plan_set[i] = (t_plan *)malloc(sizeof(t_plan));
		i++;
	}
	color = 0xFFFFFF;
	angle.x = 20;
	angle.y = 45;
	angle.z = 0;
	angle.x = angle.x * (PI / 180);
	angle.y = angle.y * (PI / 180);
	angle.z = angle.z * (PI / 180);
	i = 0;
	while (i < 8)
	{
		(cube_set[i])->x = (double)(i % 2);
		(cube_set[i])->y = (double)((i % 4) / 2);
		(cube_set[i])->z = (double)(i / 4);
	//	rotate3d(cube_set[i], plan_set[i], angle.x, angle.y, angle.z);
		printf("planset[%d]=(%d,%d)\n", i, (plan_set[i])->x, (plan_set[i])->y);
		i++;
	}

	i = 0;
	while (i < 8)
	{
		write_pixel_image(img, (plan_set[i])->x, (plan_set[i])->y, color);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		draw_line(img, plan_set[2 * i], plan_set[2 * i + 1], color);
		draw_line(img, plan_set[i], plan_set[i + 4], color);
		if (i < 2)
			draw_line(img, plan_set[i], plan_set[i + 2], color);
		else
			draw_line(img, plan_set[i + 2], plan_set[i + 4], color);
		i++;
	}
}
