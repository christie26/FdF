/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:36:08 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/16 16:38:51 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_data *data)
{
	printf("This key's keycode is %d\n", keycode);
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
//	if (keycode == LEFT)
//		angle.x
	else
		printf("It's not ESC\n");
	(void)data;
	return (0);
}

/*
void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = (void *)malloc(count * size);
	if (!res)
		return (0);
	res = ft_memset(res, 0, count * size);
	return (res);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*dst;

	dst = (char *)b;
	i = 0;
	while (i < len)
		dst[i++] = (unsigned char)c;
	return ((void *)dst);
}
*/
