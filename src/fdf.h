/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:13:34 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/16 13:12:23 by yoonsele         ###   ########.fr       */
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

typedef struct s_angle {
	double	x;
	double	y;
	double	z;
}	t_angle;

typedef struct s_map {
	int	width;
	int	height;
	int	width_min;
	int	width_max;
	int	height_min;
	int	height_max;
}	t_map;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;
// add dmin, max here

typedef struct s_param {
	void	*mlx;
	void	*win;
	void	*image;
	t_angle	angle;
	t_map	map;
	struct	{

	};

}	t_param;

int		ft_abs(int d);
void	*ft_calloc(size_t count, size_t size);
void	write_pixel_image(t_image *data, int x, int y, int color);
int		key_hook(int keycode, t_param *param);
void	main_rotate(t_image *img);
void	draw_line(t_image *data, t_plan *point1, t_plan *point2, int color);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		get_width(char *buf);
void	make_cube(t_cube *cube_set, char **tab, t_map map);
void	rotate3d(t_cube *origin, t_plan	*project, double angle_x, double angle_y, double angle_z, t_map *map);
char	*ft_strjoin(char *s1, char *s2);
char	**read_map(int fd, t_map *map);
void	print_center(t_plan *plan_set, t_image *img, int color, t_map map);

#endif
