#include "cube3d.h"

int init_window(t_cube3d *game)
{
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
        return (ft_printf_fd(2, ME_MF), -1);
    mlx_get_screen_size(game->mlx_ptr, &game->map->width, &game->map->height);
    // game->win_ptr = mlx_new_window(game->mlx_ptr, IMG_WIDTH, IMG_HEIGHT, "Cube-3d");
    game->win_ptr = mlx_new_window(game->mlx_ptr, 800, 400, "Cube-3d");
    if (!game->win_ptr)
        return (ft_printf_fd(2, ME_NW), -1);
    // game->img_ptr = mlx_new_image(game->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
    game->img_ptr = mlx_new_image(game->mlx_ptr, 800, 400);
    if (!game->img_ptr)
        return (ft_printf_fd(2, ME_NW), -1);
    return (0);
}