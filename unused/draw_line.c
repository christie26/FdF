/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:16:07 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/12 14:22:28 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_line *tmp_set_line(int n1, int n2, int n3, int n4)
{
	t_plan	*dot1;
	t_plan	*dot2;
	t_line	*line;

	dot1 = (t_plan *)malloc(sizeof(t_plan));
	dot2 = (t_plan *)malloc(sizeof(t_plan));
	line = (t_line *)malloc(sizeof(t_line));
	dot1->x = n1;
	dot1->y = n2;
	dot2->x = n3;
	dot2->y = n4;
	line->start = dot1;
	line->end = dot2;
	return (line);
}

void	draw_line_x(t_data *data, t_line *line, int color)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	d;

	dx = line->end->x - line->start->x;
	dy = line->end->y - line->start->y;
	d = 2 * ft_abs(dy) - ft_abs(dx);
	x = line->start->x;
	y = line->start->y;
	while (x != line->end->x)
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

void	draw_line_y(t_data *data, t_line *line, int color)
{
	int	dx;
	int	dy;
	int	xx;
	int	yy;
	int	d;

	//printf("draw2(%d,%d)->(%d,%d)\n", line->start->x, line->start->y, line->end->x, line->end->y);
	dx = line->end->x - line->start->x;
	dy = line->end->y - line->start->y;
	//printf("dx %d, dy %d\n", dx, dy);
	d = 2 * ft_abs(dx) - ft_abs(dy);
	xx = line->start->x;
	yy = line->start->y;
	while (yy != line->end->y)
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

void	draw_line(t_data *data, t_line *line, int color)
{
	int	dx;
	int	dy;

	dx = line->end->x - line->start->x;
	dy = line->end->y - line->start->y;
	//printf("draw1(%d,%d)->(%d,%d)\n", line->start->x, line->start->y, line->end->x, line->end->y);
	if (ft_abs(dx) > ft_abs(dy))
		draw_line_x(data, line, color);
	else
		draw_line_y(data, line, color);
	//printf("draw4(%d,%d)->(%d,%d)\n", line->start->x, line->start->y, line->end->x, line->end->y);
}
