/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:33:06 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/19 12:45:37 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
