/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:13:34 by yoonsele          #+#    #+#             */
/*   Updated: 2023/01/05 20:29:08 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

# define ESC 53

typedef struct	s_line
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
}	t_line;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_param {
	void	*mlx;
	void	*win;
	void	*img;
}	t_param;

void	draw_line(t_data data, t_line line, int color);
void	tmp_set_line(t_line *line, int n1, int n2, int n3, int n4);
int		ft_abs(int d);
void	write_pixel_image(t_data *data, int x, int y, int color);


#endif
