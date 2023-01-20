/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:14:28 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/18 17:54:04 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	draw_cal(int x, int dx)
{
	if (dx > 0)
		return (x + 1);
	else
		return (x - 1);
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
		write_pixel_image(data, x, y, color);
		if (d >= 0)
		{
			y = draw_cal(y, dy);
			d = d + 2 * ft_abs(dy) - 2 * ft_abs(dx);
		}
		else
			d = d + 2 * ft_abs(dy);
		x = draw_cal(x, dx);
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
		write_pixel_image(data, xx, yy, color);
		if (d >= 0)
		{
			xx = draw_cal(xx, dx);
			d = d + 2 * ft_abs(dx) - 2 * ft_abs(dy);
		}
		else
			d = d + 2 * ft_abs(dx);
		yy = draw_cal(yy, dy);
	}
}
