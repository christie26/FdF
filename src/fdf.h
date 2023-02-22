/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:13:34 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/22 16:55:33 by yoonsele         ###   ########.fr       */
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
# define KEY_C 8
# define KEY_T 17
# define B_LEFT 33
# define B_RIGHT 30
# define PLUS 24
# define MINUS 27
# define TOPVIEW 2
# define HEATMAP 3
# define PI 3.141592654
# define FIRSTCOLOR 0xFFFFFF
# define SECONDCOLOR 0xa6d5f6
# define THIRDCOLOR 0x046fe0
# define FORTHCOLOR 0x0063de

typedef struct s_cube {
	double	x;
	double	y;
	double	z;
	int		color;
}	t_cube;

typedef struct s_plan {
	int	x;
	int	y;
}	t_plan;

typedef struct s_map {
	int		width;
	int		height;
	int		size;
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
	int		color;
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
	double	z_scale;
	t_map	*map;
	t_cube	*cube_set;
	t_cube	*render;
}	t_data;

int		ft_abs(int d);
char	**read_map(int fd, t_map *map);
t_cube	*get_cube(t_map *map, char *av);
int		key_press(int keycode, t_data *data);
int		win_close(void);
int		render(t_data *data);
void	transform_rotate(t_data *data, t_cube *cube);
void	transform_move(t_data *data, t_cube *cube);
void	transform_scale(t_data *data, t_cube *cube);
void	print_center(t_data *data, t_cube *render);
void	draw_line(t_data *data, t_plan *point1, t_plan *point2, int color);
void	write_pixel_image(t_data *data, int x, int y, int color);
void	*error_msg(char *error_message);
void	*handle_syscall(char *error_message);
#endif
