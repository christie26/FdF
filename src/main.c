#include "fdf.h"
#include "libft.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_map	*map;
	t_cube	*cube_set;

	if (ac != 2)
	{
		error_msg("Error: wrong argument !");
		return (EXIT_FAILURE);
	}
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (EXIT_FAILURE);
	cube_set = get_cube(map, av[1]);
	if (!cube_set)
		return (EXIT_FAILURE);
	data_init(&data, map);
	data.map = map;
	data.cube_set = cube_set;
	mlx_hook(data.win, 2, 0, key_press, &data);
	mlx_hook(data.win, 17, 0, win_close, 0);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}