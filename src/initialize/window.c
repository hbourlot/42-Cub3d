#include "cube3d.h"

int init_window(t_cube3d *data)
{
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
        return (ft_printf_fd(2, ME_MF), -1);
    mlx_get_screen_size(data->mlx_ptr, &data->map.width, &data->map.height);
    data->mlx_win = mlx_new_window(data->mlx_ptr, data->map.width - 800, data->map.height - 200, "Cube-3d");
    if (!data->mlx_win)
        return (ft_printf_fd(2, ME_NW), -1);
	if (init_s_map(&data->map) < 0)
        return (-1);    
    return (0);
}