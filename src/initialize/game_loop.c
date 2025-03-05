#include "cube3d.h"

int	game_loop(t_cube3d *data)
{
	mlx_loop(data->mlx_ptr);
	return 0;
}