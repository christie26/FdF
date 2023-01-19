/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:36:08 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/19 12:41:44 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int d)
{
	if (d < 0)
		return (-d);
	else
		return (d);
}

void	write_pixel_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 950 || x < 50 || y > 750 | y < 50)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return ;
}
