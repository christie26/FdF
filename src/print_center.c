// this file has two function 

#include "fdf.h"

void	print_sero(t_plan *plan_set, t_image *img, int color, t_map map)
{
	int	col;
	int	row;
	int	i;
	int	j;

	col = 0;
	while (col < map.width)
	{
		row = 0;
		while(row < map.height - 1)
		{
			i = row * map.width + col;
			j = (row + 1) * map.width + col;
	//		printf("i=%d, col=%d, row=%d\n", i, col, row);
	//		printf("j=%d, col=%d, row=%d\n", j, col, row + 1);
			printf("(%d,%d)-(%d,%d)\n",plan_set[i].x,plan_set[i].y,plan_set[j].x, plan_set[j].y);
			draw_line(img, &(plan_set[i]), &(plan_set[j]), color);
	//		printf("check\n");
			row++;
		}
		col++;
	}
}

void	print_center(t_plan *plan_set, t_image *img, int color, t_map map)
{
	print_sero(plan_set, img, color, map);
//	print_garo(plan_set, img, color, map);
}
