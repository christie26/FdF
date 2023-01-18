/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:33:06 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/18 17:35:32 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
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
*/
/*
int	get_iso_x(t_data *data, t_cube cube)
{
	double	iso_x;
	int		result;

	iso_x = (cube.x - cube.z) * cos(ISO);
	result = iso_x;
	(void)data;
//	result = iso_x - data->map->width_min + 50;
	return (result);
}

int	get_iso_y(t_data *data, t_cube cube)
{
	double	iso_y;
	int		result;

	iso_y = (cube.x + cube.z) * sin(ISO) - cube.y;
	result = iso_y;
	(void)data;
//	result = -iso_y - data->map->height_min + 50;
	return (result);
}
*/

void	get_plan(t_data *data, t_cube *cube, t_plan *plan)
{
	int	i;

	i = 0;
	while (i < data->map->width * data->map->height)
	{
		plan[i].x = 500 + cube[i].x;
		plan[i].y = 400 + cube[i].y;
	//	printf("%d,%d\n", plan[i].x, plan[i].y);
	//	check_limit(plan[i], data->map);
		i++;
	}
	return ;
}
