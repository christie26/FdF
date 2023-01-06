/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:36:08 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/05 21:52:26 by yoonsele         ###   ########.fr       */
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

void	set_cube(t_cube *cube, double x, double y, double z)
{
	cube->x = x;
	cube->y = y;
	cube->z = z;
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
