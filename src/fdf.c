/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:45:01 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/22 16:50:45 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	*handle_syscall(char *error_message)
{
	perror(error_message);
	return (0);
}

void	*error_msg(char *error_message)
{
	ft_putendl_fd(error_message, 2);
	return (0);
}

void	data_init(t_data *data, t_map *map)
{
	t_trans	*trans;

	trans = malloc(sizeof(t_trans));
	trans->x_mv = 0;
	trans->y_mv = 0;
	trans->z_mv = 0;
	trans->x_ro = -30;
	trans->y_ro = 0;
	trans->z_ro = -30;
	trans->color = 0;
	trans->scale = 1;
	trans->z_scale = 1;
	trans->x = (map->x_max - map->x_min) / 2;
	trans->y = (map->y_max - map->y_min) / 2;
	trans->z = (map->z_max - map->z_min) / 2;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 800, "mlx 42");
	data->img = 0;
	data->status = 1;
	data->trans = trans;
	return ;
}
