#include "mlx.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	ft_putchar('x');
	mlx_pixel_put(mlt_ptr, win_ptr, );
	return (0);
}

int	main(void)
{
	void	*mlt_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlt_ptr);

}
