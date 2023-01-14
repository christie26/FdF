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
	//		printf("(%d,%d)-(%d,%d)\n",row, col, row + 1, col);
	//		printf("(%d,%d)-(%d,%d)\n",plan_set[i].x,plan_set[i].y,plan_set[j].x, plan_set[j].y);
			draw_line(img, &(plan_set[i]), &(plan_set[j]), color);
			row++;
		}
		col++;
	}
}

void	print_garo(t_plan *plan_set, t_image *img, int color, t_map map)
{
	int	col;
	int	row;
	int	i;
	int	j;

	row = 0;
	while (row < map.height)
	{
		col = 0;
		while(col < map.width - 1)
		{
			i = row * map.width + col;
			j = row * map.width + col + 1;
	//		printf("(%d,%d)-(%d,%d)\n",row, col, row , col+1);
	//		printf("(%d,%d)-(%d,%d)\n",plan_set[i].x,plan_set[i].y,plan_set[j].x, plan_set[j].y);
			draw_line(img, &(plan_set[i]), &(plan_set[j]), color);
			col++;
		}
		row++;
	}
	
}

void	print_center(t_plan *plan_set, t_image *img, int color, t_map map)
{
	print_sero(plan_set, img, color, map);
	print_garo(plan_set, img, color, map);
}
