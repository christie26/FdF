/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:13:34 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/05 22:35:41 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define ESC 53

typedef struct s_cube {
	int	x;
	int	y;
	int	z;
}	t_cube;

typedef struct s_plan {
	int	x;
	int	y;
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

typedef struct s_param {
	void	*mlx;
	void	*win;
//	void	*data;
}	t_param;

int		ft_abs(int d);
void	*ft_calloc(size_t count, size_t size);
void	draw_line(t_data *data, t_line *line, int color);
void	tmp_set_line(t_line *line, int n1, int n2, int n3, int n4);
void	write_pixel_image(t_data *data, int x, int y, int color);


#endif
