/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:16:07 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/05 20:22:19 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	tmp_set_line(t_line *line, int n1, int n2, int n3, int n4)
{
	// set from (3,6) to (7, 9)
	line->start_x = n1;
	line->start_y = n2;
	line->end_x = n3;
	line->end_y = n4;
}

//when abs(dx) > abs(dy)
void	draw_line_x(t_data data, t_line line, int color)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	d;

	dx = line.end_x - line.start_x;
	dy = line.end_y - line.start_y;
	d = 2 * ft_abs(dy) - ft_abs(dx);
	x = line.start_x;
	y = line.start_y;
	while (x != line.end_x)
	{
		if (d >= 0)
		{
			write_pixel_image(&data, x, y, color);
			if (dy > 0)
				y = y + 1;
			else
				y = y - 1;
				
			d = d + 2 * ft_abs(dy) - 2 * ft_abs(dx);
		}
		else
		{
			write_pixel_image(&data, x, y, color);
			d = d + 2 * ft_abs(dy);
		}
		if (dx > 0)
			x = x + 1;
		else
			x = x - 1;
	}
}

void	draw_line_y(t_data data, t_line line, int color)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	d;

	dx = line.end_x - line.start_x;
	dy = line.end_y - line.start_y;
	d = 2 * ft_abs(dx) - ft_abs(dy);
	x = line.start_x;
	y = line.start_y;
	while (y != line.end_y)
	{
		if (d >= 0)
		{
			write_pixel_image(&data, x, y, color);
			if (dx > 0)
				x = x + 1;
			else
				x = x - 1;
				
			d = d + 2 * ft_abs(dx) - 2 * ft_abs(dy);
		}
		else
		{
			write_pixel_image(&data, x, y, color);
			d = d + 2 * ft_abs(dx);
		}
		if (dy > 0)
			y = y + 1;
		else
			y = y - 1;
	}
}

void	draw_line(t_data data, t_line line, int color)
{
	int	dx;
	int	dy;

	dx = line.end_x - line.start_x;
	dy = line.end_y - line.start_y;
	if (ft_abs(dx) > ft_abs(dy))
		draw_line_x(data, line, color);
	else
		draw_line_y(data, line, color);
}



