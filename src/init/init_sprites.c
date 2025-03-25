#include "cube3d.h"

int	init_dirt_sprite(t_cube3d *game)
{
	t_sprite	*dirt;

	dirt = game->sprites->dirt;
	dirt->img = mlx_new_image(game->mlx_ptr, &dirt->size_x, &dirt->size_y);
	if (!dirt->img)
		return (printf("Error initializer Dirt Texture\n"), -1);
	return (0);
}
