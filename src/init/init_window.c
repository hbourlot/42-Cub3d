#include "cub3d.h"

int	init_window(t_cub3d *game)
{
	t_screen	*screen;

	screen = init_s_screen();
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (ft_printf_fd(2, ME_MF), -1);
	mlx_get_screen_size(game->mlx_ptr, &screen->width, &screen->height);
	if (S_WIDTH > screen->width || S_HEIGHT > screen->height)
		return (ft_printf_fd(2, ME_RES), -1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, S_WIDTH, S_HEIGHT, "Cube-3D");
	if (!game->win_ptr)
		return (ft_printf_fd(2, ME_NW), -1);
	game->main_img.img = mlx_new_image(game->mlx_ptr, S_WIDTH, S_HEIGHT);
	if (!game->main_img.img)
		return (ft_printf_fd(2, ME_NW), -1);
	game->main_img.addr = mlx_get_data_addr(game->main_img.img,
			&game->main_img.bpp, &game->main_img.size_line,
			&game->main_img.endian);
	if (!game->main_img.addr)
		return (ft_printf_fd(2, ME_NW), -1);
	return (0);
}
