/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_center.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:33:16 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/22 17:25:57 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_sero(t_plan *plan_set, t_data *data, int color, t_map map)
{
	int	col;
	int	row;
	int	i;
	int	j;

	col = 0;
	(void)color;
	while (col < map.width)
	{
		row = 0;
		while (row < map.height - 1)
		{
			i = row * map.width + col;
			j = (row + 1) * map.width + col;
			if (data->color)
				draw_line(data, &(plan_set[i]), &(plan_set[j]), \
				(data->cube_set[i]).color);
			else
				draw_line(data, &(plan_set[i]), &(plan_set[j]), color);
			row++;
		}
		col++;
	}
}

void	print_garo(t_plan *plan_set, t_data *data, int color, t_map map)
{
	int	col;
	int	row;
	int	i;
	int	j;

	row = 0;
	(void)color;
	while (row < map.height)
	{
		col = 0;
		while (col < map.width - 1)
		{
			i = row * map.width + col;
			j = row * map.width + col + 1;
			if (data->color)
				draw_line(data, &(plan_set[i]), &(plan_set[j]), \
				(data->cube_set[i]).color);
			else
				draw_line(data, &(plan_set[i]), &(plan_set[j]), color);
			col++;
		}
		row++;
	}
}

void	get_plan(t_data *data, t_cube *cube, t_plan *plan)
{
	int	i;

	i = 0;
	while (i < data->map->width * data->map->height)
	{
		plan[i].x = 500 + cube[i].x;
		plan[i].y = 400 + cube[i].y;
		i++;
	}
	return ;
}

void	print_center(t_data *data, t_cube *render)
{
	t_plan	*plan_set;
	int		color;

	plan_set = (t_plan *)malloc(sizeof(t_plan) * data->map->size);
	if (!plan_set)
		return ;
	get_plan(data, render, plan_set);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, 1000, 800);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	color = 0xFFFFFF;
	print_sero(plan_set, data, color, *(data->map));
	print_garo(plan_set, data, color, *(data->map));
	free(plan_set);
}
