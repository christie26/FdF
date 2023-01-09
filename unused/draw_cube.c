#include "fdf.h"

void	set_cube(t_cube *cube, double x, double y, double z)
{
	cube->x = x;
	cube->y = y;
	cube->z = z;
}

void	two_cube(t_cube *cube1, t_cube *cube2, t_cube *camera, t_cube *view, t_data *img)
{
	t_plan	*plan1;
	t_plan	*plan2;
	t_line	*line;

	plan1 = convert(camera, cube1, view);
	plan2 = convert(camera, cube2, view);
	line = tmp_set_line(plan1->x, plan1->y, plan2->x, plan2->y);

	draw_line(img, line, 0x77CCFF);

}

void	draw_cube(t_data *img)
{
//	void	**table;
	t_cube	one;
	t_cube	two;
	t_cube	three;
	t_cube	four;
//	t_cube	five;
//	t_cube	six;
//	t_cube	seven;
/*
	t_plan	*one_p;
	t_plan	*two_p;
	t_plan	*three_p;
	t_plan	*four_p;
	t_plan	*five_p;
	t_plan	*six_p;
	t_plan	*seven_p;
*/
	t_cube	camera;
	t_cube	view;

	set_cube(&one, 100, 100, 100);
	set_cube(&two, 100, 100, 200);
	set_cube(&three, 100, 200, 100);
	set_cube(&four, 200, 100, 100);
//	set_cube(&five, 0, 100, 0);
//	set_cube(&six, 0, 0, 0);
//	set_cube(&seven, 100, 0, 0);
	set_cube(&camera, 0, 0, 0);
	set_cube(&view, 45, 45, 45);
	
	two_cube(&one, &two, &camera, &view, img);
//	two_cube(&one, &three, &camera, &view, img);
//	two_cube(&one, &four, &camera, &view, img);
//	two_cube(&five, &six, &camera, &view, img);
//	two_cube(&one, &three, &camera, &view, img);
/*
	int i;
	table = (void **)malloc(3 * sizeof(void *));
	while (i < 3)
		table[i++] = (void *)malloc(3 * sizeof(void));
*/
	
}
/*
int main(void)
{
	t_param	param;
	t_data	img;

	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 500, 500, "mlx 42");

	img.img = mlx_new_image(param.mlx, 500, 500);
	mlx_put_image_to_window (param.mlx, param.win, img.img, 0, 0);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	draw_cube(&img);
	mlx_key_hook(param.win, key_hook, &param);
	mlx_loop(param.mlx);
}
*/
