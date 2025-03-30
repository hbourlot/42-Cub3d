#include "cube3d.h"

int	init_dirt_sprite(t_cube3d *game)
{
	t_sprite	*dirt;

	dirt = malloc(sizeof(t_sprite));
	if (!dirt)
		return (printf("Error: Malloc failed for dirt texture\n"), -1);
	dirt->img = mlx_xpm_file_to_image(game->mlx_ptr,
			"texture/wall/grass_block.xpm", &dirt->width, &dirt->height);
	if (!dirt->img)
	{
		free(dirt);
		return (printf("Error: Failed to load XPM file grass_block.xpm\n"), -1);
	}
	dirt->addr = mlx_get_data_addr(dirt->img, &dirt->bpp, &dirt->size_line,
			&dirt->endian);
	if (!dirt->addr)
	{
		mlx_destroy_image(game->mlx_ptr, dirt->img);
		free(dirt);
		return (printf("Error: Failed to get texture data address\n"), -1);
	}
	game->sprites->dirt = dirt;
	return (0);
}
