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
	data->x_mv = - (data->map->x_max - data->map->x_min) / 2;
	data->y_mv = - (data->map->y_max - data->map->y_min) / 2;
	data->z_mv = - (data->map->z_max - data->map->z_min) / 2;
	transform_move(data, cube);
	while (i < data->map->width * data->map->height)
	{
		rotate_y(data->y_ro, &cube[i]);
		rotate_x(data->x_ro, &cube[i]);
		rotate_z(data->z_ro, &cube[i]);
		i++;
	}
	data->x_mv = (data->map->x_max - data->map->x_min) / 2;
	data->y_mv = (data->map->y_max - data->map->y_min) / 2;
	data->z_mv = (data->map->z_max - data->map->z_min) / 2;
	transform_move(data, cube);
	return ;
}
