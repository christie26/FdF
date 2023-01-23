/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:57:08 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/22 19:51:21 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

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

char	**read_map(int fd, t_map *map)
{
	char	*buf;
	char	*tmp;
	char	*storage;
	char	**tab;

	buf = get_next_line(fd);
	map->width = get_width(buf);
	map->height = 0;
	storage = ft_strdup("");
	while (buf)
	{
		if (get_width(buf) != map->width)
			return (error_msg("Error : unvalid map!"));
		map->height++;
		tmp = storage;
		storage = ft_strjoin(storage, buf);
		free(tmp);
		free(buf);
		buf = get_next_line(fd);
	}
	map->size = map->width * map->height;
	tab = ft_split(storage, '\n');
	free(storage);
	return (tab);
}

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
			cube_set[i].x = 10 * x;
			cube_set[i].y = 10 * y;
			cube_set[i].z = ft_atoi(tab2[x]);
			free(tab2[x]);
			x++;
		}
		free(tab2);
		free(tab[y]);
		y++;
	}
	free(tab);
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
	char	*format;

	format = ft_substr(av, ft_strlen(av) - 4, 4);
	if (ft_memcmp(format, ".fdf", 4) || ft_strlen(av) < 5)
		return (error_msg("Error: unvalid file format!"));
	free(format);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (handle_syscall(av));
	tab = read_map(fd, map);
	if (!tab)
		return (0);
	cube_set = (t_cube *)malloc(sizeof(t_cube) * map->size);
	make_cube(cube_set, tab, map);
	check_limit_cube(cube_set, map);
	return (cube_set);
}
