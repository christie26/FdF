
#include "fdf.h"

int	key_hook(int keycode, t_data *data)
{
	printf("keycode=%d\n", keycode);
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	// rotate
	if (keycode == LEFT)
		data->y_ro = -0.1;
	if (keycode == RIGHT)
		data->y_ro = 0.1;
	if (keycode == UP)
		data->x_ro = -0.1;
	if (keycode == DOWN)
		data->x_ro = 0.1;
	// move	
	if (keycode == KEY_W)
		data->y_mv = -5;
	if (keycode == KEY_S)
		data->y_mv = 5;
	if (keycode == KEY_A)
		data->x_mv = -5;
	if (keycode == KEY_D)
		data->x_mv = 5;
	// scale
	if (keycode == PLUS)
		data->scale = 2;
	if (keycode == MINUS)
		data->scale = 0.5;
	// perspective 
	// color
	data->status = 0;
	return (0);
}
