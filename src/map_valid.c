/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:57:08 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/13 17:27:57 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_width(char *buf)
{
	int	width;

	width = 0;
	while (*buf)
	{
		if (*buf == ' ')
			width++;
		buf++;
	}
	return (width);
}

char	**read_map(int fd, t_map *map)
{
	char	*buf;
	char	*storage;
	char	**tab;

	buf = get_next_line(fd);
	map->width = get_width(buf);
	map->height = 0;
	storage = buf;
	while (buf)
	{
		if (get_width(buf) != map->width)
			perror("Error : unvalid map!\n");
		map->height++;
		buf = get_next_line(fd);
		if (buf == 0)
			break;
		storage = ft_strjoin(storage, buf); //free
	}
	tab = ft_split(storage, '\n');
	return (tab);
}

void	make_cube(t_cube *cube_set, char **tab, t_map map)
{
	int		x;
	int		y;
	int		i;
	char	**tab2;

	y = 0;
//	printf("%d,%d\n", map.width, map.height);
	while (y < map.height)
	{
	//	printf("tab is %s\n", tab[y]);
		tab2 = ft_split(tab[y], ' ');
		x = 0;
		while (x < map.width)
		{
			i = y * map.width + x;
			cube_set[i].x = x;
			cube_set[i].y = y;
			cube_set[i].z = ft_atoi(tab2[x]);
	//		printf("i=%d, x=%d, y=%d\n", i, x, y);
			x++;
		}
		y++;
	}
}
