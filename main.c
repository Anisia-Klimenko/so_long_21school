#include "so_long.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	usleep(500);
	mlx_destroy_window(&mlx, &mlx_win);
	mlx_loop(mlx);
}
