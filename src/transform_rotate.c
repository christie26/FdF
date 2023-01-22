/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:33:06 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/19 12:28:06 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	transform_rotate(t_data *data, t_cube *cube)
{
	int	i;

	i = 0;
	while (i < data->map->size)
	{
		rotate_y(data->y_ro * PI / 180, &cube[i]);
		rotate_x(data->x_ro * PI / 180, &cube[i]);
		rotate_z(data->z_ro * PI / 180, &cube[i]);
		i++;
	}
	return ;
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
