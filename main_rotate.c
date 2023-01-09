/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:33:06 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/09 16:33:10 by yoonsele         ###   ########.fr       */
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
	return (rotation);
}

t_cube	*rotation_y(double angle, t_cube *cube)
{
	t_cube	*rotation;
	rotation = (t_cube *)malloc(sizeof(t_cube));
	rotation->x = cube->x * cos(angle) - cube->z * sin(angle);
	rotation->y = cube->y;
	rotation->z = cube->x * sin(angle) + cube->z * cos(angle);
	return (rotation);
}

t_cube	*rotation_x(double angle, t_cube *cube)
{
	t_cube	*rotation;

	rotation = (t_cube *)malloc(sizeof(t_cube));
	rotation->x = cube->x;
	rotation->y = cube->y * cos(angle) + cube->z * sin(angle);
	rotation->z = cube->y * -sin(angle) + cube->z * cos(angle);
	return (rotation);
}

t_plan	*projection(t_cube *cube)
{
	t_plan	*result;
	result = (t_plan *)malloc(sizeof(t_plan));
	result->x = cube->x;
	result->y = cube->y;
	return (result);
}

t_plan	*rotate3d(t_cube *origin, double angle_x, double angle_y, double angle_z)
{
	t_cube	*rotated;
	t_plan	*projected;

	rotated = rotation_x(angle_x, origin);
	rotated = rotation_y(angle_y, rotated);
	rotated = rotation_z(angle_z, rotated);
	projected = projection(rotated);
	return (projected);
}

void	main_rotate(t_data *img)
{
	t_cube	cube1;
	t_cube	cube2;
	t_cube	cube3;
	t_cube	cube4;
	t_plan	*plan1;
	t_plan	*plan2;
	t_plan	*plan3;
	t_plan	*plan4;
	double	angle_x;
	double	angle_y;
	double	angle_z;
	int	color;

	color = 0xFFFFFF;
	angle_x = 45;
	angle_y = 45;
	angle_z = -45;
	angle_x = angle_x * (PI / 180);
	angle_y = angle_y * (PI / 180);
	angle_z = angle_z * (PI / 180);
	set_cube(&cube1, 100, 100, 100);
	set_cube(&cube2, 200, 100, 100);
	set_cube(&cube3, 100, 100, 200);
	set_cube(&cube4, 200, 100, 200);
	plan1 = rotate3d(&cube1, angle_x, angle_y, angle_z);
	plan2 = rotate3d(&cube2, angle_x, angle_y, angle_z);
	plan3 = rotate3d(&cube3, angle_x, angle_y, angle_z);
	plan4 = rotate3d(&cube4, angle_x, angle_y, angle_z);

	printf("plan1=(%.2f,%.2f)\n", plan1->x, plan1->y);
	printf("plan2=(%.2f,%.2f)\n", plan2->x, plan2->y);
	printf("plan3=(%.2f,%.2f)\n", plan3->x, plan3->y);
	printf("plan4=(%.2f,%.2f)\n\n", plan4->x, plan4->y);
//	write_pixel_image(img, plan1->x, plan1->y, 0xFFFFFF);
//	write_pixel_image(img, plan2->x, plan2->y, 0xFFFFFF);
//	write_pixel_image(img, plan3->x, plan3->y, 0xFFFFFF);
//	write_pixel_image(img, plan4->x, plan4->y, 0xFFFFFF);
	connect_point(img, plan1, plan2, color);
	connect_point(img, plan3, plan4, color);
	connect_point(img, plan1, plan3, color);
	connect_point(img, plan2, plan4, color);

}

