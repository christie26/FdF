/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonsele <yoonsele@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:33:08 by yoonsele          #+#    #+#             */
/*   Updated: 2023/02/22 16:53:44 by yoonsele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_press2(int keycode, t_data *data);

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (keycode == LEFT)
		data->trans->y_ro += 1;
	if (keycode == RIGHT)
		data->trans->y_ro -= 1;
	if (keycode == UP)
		data->trans->x_ro -= 1;
	if (keycode == DOWN)
		data->trans->x_ro += 1;
	if (keycode == KEY_W)
		data->trans->y_mv -= 5;
	if (keycode == KEY_S)
		data->trans->y_mv += 5;
	if (keycode == KEY_A)
		data->trans->x_mv -= 5;
	if (keycode == KEY_D)
		data->trans->x_mv += 5;
	if (keycode == PLUS)
		data->trans->scale *= 1.1;
	if (keycode == MINUS)
		data->trans->scale *= 0.9;
	key_press2(keycode, data);
	return (0);
}

void	key_press2(int keycode, t_data *data)
{
	if (keycode == B_LEFT)
		data->trans->z_scale *= 0.9;
	if (keycode == B_RIGHT)
		data->trans->z_scale *= 1.1;
	data->status = 1;
	if (keycode == KEY_T)
		data->status = TOPVIEW;
	if (keycode == KEY_C)
	{
		if (data->color == 0)
			data->color = 1;
		else
			data->color = 0;
	}
}

int	win_close(void)
{
	exit (EXIT_SUCCESS);
}
