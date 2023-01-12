/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:33:06 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/12 17:31:27 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	rotation_z(double angle, t_cube *cube)
{
	cube->x = cube->x * cos(angle) + cube->y * sin(angle);
	cube->y = cube->x * -sin(angle) + cube->y * cos(angle);
	cube->z = cube->z;
	return ;
}

void	rotation_y(double angle, t_cube *cube)
{
	cube->x = cube->x * cos(angle) - cube->z * sin(angle);
	cube->y = cube->y;
	cube->z = cube->x * sin(angle) + cube->z * cos(angle);
	return ;
}

void	rotation_x(double angle, t_cube *cube)
{
	cube->x = cube->x;
	cube->y = cube->y * cos(angle) + cube->z * sin(angle);
	cube->z = cube->y * -sin(angle) + cube->z * cos(angle);
	return ;
}

void	rotate3d(t_cube *origin, t_plan	*project, double angle_x, double angle_y, double angle_z)
{
	rotation_y(angle_y, origin);
	rotation_x(angle_x, origin);
	rotation_z(angle_z, origin);
	project->x =  (int)(100 * origin->x);
	project->y =  (int)(100 * origin->y);
	printf("plan (%d,%d)\n", project->x, project->y);
	return ;
}

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
		rotate3d(cube_set[i], plan_set[i], angle.x, angle.y, angle.z);
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
