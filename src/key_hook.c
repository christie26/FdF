
#include "fdf.h"

int	key_hook(int keycode, t_data *data)
{
	printf("This key's keycode is %d\n", keycode);
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	// move
	if (keycode == LEFT)
		data->x_mv = -10;
	if (keycode == RIGHT)
		data->x_mv = 10;
	if (keycode == UP)
		data->y_mv = -10;
	if (keycode == DOWN)
		data->y_mv = 10;
	// rotate
	// perspective 
	// color?
	data->status = 0;
	return (0);
}
