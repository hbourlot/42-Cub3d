#include "cub3d.h"

int	init_window(t_cube3d *game)
{
	t_screen	*screen;

	screen = init_s_screen();
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (ft_printf_fd(2, ME_MF), -1);
	mlx_get_screen_size(game->mlx_ptr, &screen->width, &screen->height);
	//! Check game scale, if > screen_width or height ERROR
	game->win_ptr = mlx_new_window(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT,
			"Cube-3D");
	if (!game->win_ptr)
		return (ft_printf_fd(2, ME_NW), -1);
	return (0);
}
