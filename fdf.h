/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:13:34 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/09 15:55:56 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define ESC 53
# define PI 3.141592654

typedef struct s_cube {
	double	x;
	double	y;
	double	z;
}	t_cube;

typedef struct s_view {
	double	x;
	double	y;
	double	z;
}	t_view;

typedef struct s_plan {
	double	x;
	double	y;
}	t_plan;

typedef struct s_line {
	t_plan	*start;
	t_plan	*end;
}	t_line;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_angle {
	double	x;
	double	y;
	double	z;
}	t_angle;

typedef struct s_param {
	void	*mlx;
	void	*win;
//	void	*data;
}	t_param;

int		ft_abs(int d);
void	set_cube(t_cube *cube, double x, double y, double z);
void	*ft_calloc(size_t count, size_t size);
//void	draw_line(t_data *data, t_line *line, int color);
//t_line	*tmp_set_line(int n1, int n2, int n3, int n4);
void	write_pixel_image(t_data *data, int x, int y, int color);
t_plan	*convert(t_cube *camera, t_cube *point, t_cube *view);
int		key_hook(int keycode, t_param *param);
void	write_pixel_image(t_data *data, int x, int y, int color);
void	main_rotate(t_data *img);
void	connect_point(t_data *data, t_plan *point1, t_plan *point2, int color);

#endif
