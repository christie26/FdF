
#include "fdf.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	// rotate
	if (keycode == LEFT)
		data->y_ro -= 1;
	if (keycode == RIGHT)
		data->y_ro += 1;
	if (keycode == UP)
		data->x_ro -= 1;
	if (keycode == DOWN)
		data->x_ro += 1;
	// move	
	if (keycode == KEY_W)
		data->y_mv -= 5;
	if (keycode == KEY_S)
		data->y_mv += 5;
	if (keycode == KEY_A)
		data->x_mv -= 5;
	if (keycode == KEY_D)
		data->x_mv += 5;
	// scale
	if (keycode == PLUS)
		data->scale *= 1.1;
	if (keycode == MINUS)
		data->scale *= 0.9;

	// color
	if (keycode == KEY_C)
		printf("should show heat map\n");
	
	// z height
//	if (keycode == B_LEFT)
//		data->z_scale *= 0.9;
//	if (keycode == B_RIGHT)
//		data->z_scale *= 1.1;
	
	data->status = 1;
	
	// perspective 
	if (keycode == KEY_T)
		data->status = 3;

	return (0);
}

int	win_close(void)
{
	exit (1);
}
