/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:49:44 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/19 12:31:01 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	data_init(t_data *data, t_map *map)
{
	data->x_mv = 0;
	data->y_mv = 0;
	data->z_mv = 0;
	data->x_ro = 30;
	data->y_ro = 0;
	data->z_ro = -30;
	data->status = 0;
	data->scale = 1;
	data->x = (map->x_max - map->x_min) / 2;
	data->y = (map->y_max - map->y_min) / 2;
	data->z = (map->z_max - map->z_min) / 2;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 800, "mlx 42");
	data->img = 0;
	return ;
}

void	data_reset(t_data *data)
{
	data->x_mv = 0;
	data->y_mv = 0;
	data->z_mv = 0;
	data->x_ro = 0;
	data->y_ro = 0;
	data->z_ro = 0;
	data->status = 1;
	data->scale = 1;
}
