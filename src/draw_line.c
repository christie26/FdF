/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:14:28 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/12 17:30:46 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	draw_line_x(t_data *data, t_plan *point1, t_plan *point2, int color);
void	draw_line_y(t_data *data, t_plan *point1, t_plan *point2, int color);

void	draw_line(t_data *data, t_plan *point1, t_plan *point2, int color)
{
	int	dx;
	int	dy;

	dx = point1->x - point2->x;
	dy = point1->y - point2->y;
	if (ft_abs(dx) > ft_abs(dy))
		draw_line_x(data, point1, point2, color);
	else
		draw_line_y(data, point1, point2, color);
}

void	draw_line_x(t_data *data, t_plan *point1, t_plan *point2, int color)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	d;

	dx = point2->x - point1->x;
	dy = point2->y - point1->y;
	d = 2 * ft_abs(dy) - ft_abs(dx);
	x = point1->x;
	y = point1->y;
	while (x != point2->x)
	{
		if (d >= 0)
		{
			write_pixel_image(data, x, y, color);
			if (dy > 0)
				y = y + 1;
			else
				y = y - 1;
			d = d + 2 * ft_abs(dy) - 2 * ft_abs(dx);
		}
		else
		{
			write_pixel_image(data, x, y, color);
			d = d + 2 * ft_abs(dy);
		}
		if (dx > 0)
			x = x + 1;
		else
			x = x - 1;
	}
}

void	draw_line_y(t_data *data, t_plan *point1, t_plan *point2, int color)
{
	int	dx;
	int	dy;
	int	xx;
	int	yy;
	int	d;

	dx = point2->x - point1->x;
	dy = point2->y - point1->y;
	d = 2 * ft_abs(dx) - ft_abs(dy);
	xx = point1->x;
	yy = point1->y;
	while (yy != point2->y)
	{
		if (d >= 0)
		{
			write_pixel_image(data, xx, yy, color);
			if (dx > 0)
				xx = xx + 1;
			else
				xx = xx - 1;
			d = d + 2 * ft_abs(dx) - 2 * ft_abs(dy);
		}
		else
		{
			write_pixel_image(data, xx, yy, color);
			d = d + 2 * ft_abs(dx);
		}
		if (dy > 0)
			yy = yy + 1;
		else
			yy = yy - 1;
	}
}
