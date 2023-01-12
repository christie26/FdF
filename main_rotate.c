/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:33:06 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/09 16:46:01 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_cube	*rotation_z(double angle, t_cube *cube)
{
	t_cube	*rotation;
	rotation = (t_cube *)malloc(sizeof(t_cube));
	rotation->x = cube->x * cos(angle) + cube->y * sin(angle);
	rotation->y = cube->x * -sin(angle) + cube->y * cos(angle);
	rotation->z = cube->z;
	free(cube);
	return (rotation);
}

t_cube	*rotation_y(double angle, t_cube *cube)
{
	t_cube	*rotation;
	rotation = (t_cube *)malloc(sizeof(t_cube));
	rotation->x = cube->x * cos(angle) - cube->z * sin(angle);
	rotation->y = cube->y;
	rotation->z = cube->x * sin(angle) + cube->z * cos(angle);
	free(cube);
	return (rotation);
}

t_cube	*rotation_x(double angle, t_cube *cube)
{
	t_cube	*rotation;

	rotation = (t_cube *)malloc(sizeof(t_cube));
	rotation->x = cube->x;
	rotation->y = cube->y * cos(angle) + cube->z * sin(angle);
	rotation->z = cube->y * -sin(angle) + cube->z * cos(angle);
	free(cube);
	return (rotation);
}
/*
void	projection(t_cube *cube, t_plan *plan)
{
	result->x = cube->x;
//	result->x = 100 + 100 * cube->x;
//	result->y = 100 + 100 * cube->y;
	result->y = cube->y;
	printf("(%f,%f)\n", result->x, result->y);
	return (result);
}
*/
void	rotate3d(t_cube *origin, t_plan	*project, double angle_x, double angle_y, double angle_z)
{
	t_cube	*rotated;

	printf("origin(%f,%f,%f)\n", origin->x, origin->y, origin->z);
	rotated = rotation_x(angle_x, origin);
	rotated = rotation_y(angle_y, rotated);
	rotated = rotation_z(angle_z, rotated);
	printf("rotated(%f,%f,%f)\n", rotated->x, rotated->y, rotated->z);
	project->x = rotated->x;
	project->y = rotated->y;
	return ;
}

void	main_rotate(t_data *img)
{
	t_cube	**cube_set;
	t_plan	**plan_set;
	t_angle	angle;
	double	color;
	int	i;

	cube_set = (t_cube **)malloc(sizeof(t_cube *) * 9);
	plan_set = (t_plan **)malloc(sizeof(t_plan *) * 9);
	i = 0;
	while (i++ < 8)
	{
		*cube_set = (t_cube *)malloc(sizeof(t_cube));
		*plan_set = (t_plan *)malloc(sizeof(t_plan));
		(*cube_set)++;
		(*plan_set)++;
	}
	(*cube_set)->x = i % 2;
	printf("check1\n");
	color = 0xFFFFFF;
	angle.x = 0;
	angle.y = 0;
	angle.z = 0;
	printf("check2\n");
	angle.x = angle.x * (PI / 180);
	angle.y = angle.y * (PI / 180);
	angle.z = angle.z * (PI / 180);
	printf("check3\n");
	i = 0;
	while (i < 8)
	{
		printf("check1\n");
	//	set_cube(cube_set[i], 100 * (i % 2), 100 * ((i % 4) / 2), 100 * (i / 4));
		
		(cube_set[i])->x = i % 2;
		(cube_set[i])->y = (i % 4) / 2;
		(cube_set[i])->z = i / 4;
		printf("check2\n");
		rotate3d(cube_set[i], plan_set[i], angle.x, angle.y, angle.z);
		printf("check3\n");
		i++;
	}
	i = 0;
	while (i++ < 8)
	{
		write_pixel_image(img, (*plan_set)->x, (*plan_set)->y, color);
		(*plan_set)++;
	}
	
	
/*
	set_cube(&cube1, 100, 100, 100);
	set_cube(&cube2, 200, 100, 100);
	set_cube(&cube3, 100, 100, 200);
	set_cube(&cube4, 200, 100, 200);
	set_cube(&cube5, 100, 200, 100);
	set_cube(&cube6, 200, 200, 100);
	plan1 = rotate3d(&cube1, angle_x, angle_y, angle_z);
	plan2 = rotate3d(&cube2, angle_x, angle_y, angle_z);
	plan3 = rotate3d(&cube3, angle_x, angle_y, angle_z);
	plan4 = rotate3d(&cube4, angle_x, angle_y, angle_z);
	plan5 = rotate3d(&cube5, angle_x, angle_y, angle_z);
	plan6 = rotate3d(&cube6, angle_x, angle_y, angle_z);

	printf("plan1=(%.2f,%.2f)\n", plan1->x, plan1->y);
	printf("plan2=(%.2f,%.2f)\n", plan2->x, plan2->y);
	printf("plan3=(%.2f,%.2f)\n", plan3->x, plan3->y);
	printf("plan4=(%.2f,%.2f)\n\n", plan4->x, plan4->y);
	
	connect_point(img, plan1, plan2, color);
	connect_point(img, plan3, plan4, color);
	connect_point(img, plan1, plan3, color);
	connect_point(img, plan2, plan4, color);
	connect_point(img, plan1, plan5, color);
	connect_point(img, plan2, plan6, color);
	connect_point(img, plan5, plan6, color);
*/
}

