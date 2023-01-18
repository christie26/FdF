/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
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
	int	i;

	i = 0;
	width = 0;
	if (buf[i] != ' ')
		width++;
	i++;
	while (i < (int)ft_strlen(buf))
	{
		if (buf[i] != ' ' && buf[i - 1] == ' ' && buf[i] != '\n')
			width++;
		i++;
	}
	return (width);
}

int	open_file(char *av)
{
	int		fd;
	char	*format;

	format = ft_substr(av, ft_strlen(av) - 4, 4);
	if (ft_memcmp(format, ".fdf.", 4))
	{
		perror("Error : unvalid file format!");
		return (0);
	}
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		perror("Error :");
		return (0);
	}
	return (fd);
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
			break ;
		storage = ft_strjoin(storage, buf);
	}
	tab = ft_split(storage, '\n');
	return (tab);
}
// have to deal with free

void	make_cube(t_cube *cube_set, char **tab, t_map *map)
{
	int		x;
	int		y;
	int		i;
	char	**tab2;

	y = 0;
	while (y < map->height)
	{
		tab2 = ft_split(tab[y], ' ');
		x = 0;
		while (x < map->width)
		{
			i = y * map->width + x;
			cube_set[i].x = x;
			cube_set[i].y = y;
			cube_set[i].z = ft_atoi(tab2[x]);
			x++;
		}
		y++;
	}
}

void	check_limit_cube(t_cube *cube, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		if (cube[i].x > map->x_max)
			map->x_max = cube[i].x;
		if (cube[i].x < map->x_min)
			map->x_min = cube[i].x;
		if (cube[i].y > map->y_max)
			map->y_max = cube[i].y;
		if (cube[i].y < map->y_min)
			map->y_min = cube[i].y;
		if (cube[i].z > map->z_max)
			map->z_max = cube[i].z;
		if (cube[i].z < map->z_min)
			map->z_min = cube[i].z;
		i++;
	}	
}

t_cube	*get_cube(t_map *map, char *av)
{
	int		fd;
	char	**tab;
	t_cube	*cube_set;

	fd = open_file(av);
	tab = read_map(fd, map);
	if (!tab)
		return (0);
	cube_set = (t_cube *)malloc(sizeof(t_cube) * (map->width * map->height));
	make_cube(cube_set, tab, map);
	check_limit_cube(cube_set, map);
	return (cube_set);
}
