#include "cube3d.h"

int	init_dirt_sprite(t_cube3d *game)
{
	t_img	*dirt;

	dirt = malloc(sizeof(t_img));
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

static int	init_sprite(t_cube3d *game, t_img **sprite, char *path)
{
	t_img	*new;

	new = malloc(sizeof(t_img));
	if (!new)
		return (printf("Error: Malloc failed for%s texture\n", path), -1);
	new->img = mlx_xpm_file_to_image(game->mlx_ptr, path, &new->width,
			&new->height);
	if (!new->img)
	{
		free(new);
		return (printf("Error: Failed to load XPM file %s\n", path), -1);
	}
	new->addr = mlx_get_data_addr(new->img, &new->bpp, &new->size_line,
			&new->endian);
	if (!new->addr)
	{
		mlx_destroy_image(game->mlx_ptr, new->img);
		free(new);
		return (printf("Error: Failed to get texture data address\n"), -1);
	}
	*sprite = new;
	return (SUCCESS);
}

int	init_s_sprite(t_cube3d *game)
{
	if (init_sprite(game, &game->sprites->no, (char *)game->map->no))
		return (ft_printf_fd(2, ME_MALLOC), -1);
	if (init_sprite(game, &game->sprites->so, (char *)game->map->so))
		return (ft_printf_fd(2, ME_MALLOC), -1);
	if (init_sprite(game, &game->sprites->ea, (char *)game->map->ea))
		return (ft_printf_fd(2, ME_MALLOC), -1);
	if (init_sprite(game, &game->sprites->we, (char *)game->map->we))
		return (ft_printf_fd(2, ME_MALLOC), -1);
	return (SUCCESS);
}
