#include "fdf.h"
#include <stdio.h>

t_plan	*rotate(t_cube *camera, t_cube *point, t_view *view)
{
	t_cube	*d;
	t_plan	*b;
	double	x;
	double	y;
	double	z;
	double	cx;
	double	cy;
	double	cz;
	double	sx;
	double	sy;
	double	sz;
	
	x = (double)(point->x - camera->x);
	y = (double)(point->y - camera->y);
	z = (double)(point->z - camera->z);
	d = (t_cube *)malloc(sizeof(t_cube));
	b = (t_plan *)malloc(sizeof(t_plan));
	view->x = (view->x * PI) / 180;
	view->y = (view->y * PI) / 180;
	view->z = (view->z * PI) / 180;
	printf("view->x:%f\n", view->x);
	printf("cos(view->x):%f\n", cos(view->x));
	cx = cos(view->x);
	cy = cos(view->y);
	cz = cos(view->z);
	sx = sin(view->x);
	sy = sin(view->y);
	sz = sin(view->z);
	printf("cos, sin %f %f %f %f %f %f\n", cx, cy, cz, sx, sy, sz);
	
	d->x = (cy) * (sz * y + cz * x) - sy*z;
	d->y = sx * (cy*z + sy * (sz*y + cz * x)) + cx * (cz * y - sz * x);
	d->z = cx * (cy*z+sy * (sz*y+cz*x)) - sx * (cz*y-sz*x);
	printf("d is (%f, %f, %f)\n", d->x, d->y, d->z);
	
	b->x = (1 / d->z) * d->x + 1;
	b->y = (1 / d->z) * d->y + 1;
	printf("b is (%f, %f\n", b->x, b->y);
	return (b);
}

int	main(void)
{
	t_cube	camera;
	t_cube	point;
	t_view	view;
	t_plan	*result;

	
	camera.x = 0;
	camera.y = 0;
	camera.z = 0;
	point.x = 5;
	point.y = 5;
	point.z = 5;
	view.x = 45;
	view.y = 45;
	view.z = 45;
	result = rotate(&camera, &point, &view);
	printf("result is (%f,%f)\n", result->x, result->y);
}
