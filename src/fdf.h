/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:13:34 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/12 17:59:03 by yoonsele         ###   ########.fr       */
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
int		get_width(char **tab);

#endif
