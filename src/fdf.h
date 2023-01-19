/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:13:34 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/19 12:37:01 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define PLUS 24
# define MINUS 27
# define PI 3.141592654

typedef struct s_cube {
	double	x;
	double	y;
	double	z;
}	t_cube;

typedef struct s_plan {
	int	x;
	int	y;
}	t_plan;

typedef struct s_map {
	int		width;
	int		height;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	z_min;
	double	z_max;
}	t_map;

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		status;
	double	win_xmin;
	double	x_ro;
	double	y_ro;
	double	z_ro;
	double	x_mv;
	double	y_mv;
	double	z_mv;
	double	x;
	double	y;
	double	z;
	double	scale;
	t_map	*map;
	t_cube	*cube_set;
}	t_data;

int		ft_abs(int d);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);

t_cube	*get_cube(t_map *map, char *av);
void	write_pixel_image(t_data *data, int x, int y, int color);
int		key_hook(int keycode, t_data *data);
int		render(t_data *data);
void	draw_line(t_data *data, t_plan *point1, t_plan *point2, int color);

void	get_plan(t_data *data, t_cube *cube, t_plan *plan);
void	transform_rotate(t_data *data, t_cube *cube);
void	transform_move(t_data *data, t_cube *cube);
void	transform_init(t_data *data, t_cube *cube);
char	**read_map(int fd, t_map *map);
void	print_center(t_plan *plan_set, t_data *img, int color, t_map map);
void	data_init(t_data *data, t_map *map);
void	data_reset(t_data *data);
#endif
