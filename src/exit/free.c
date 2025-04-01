/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:14:58 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/01 01:15:44 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_world(int **world)
{
	int	i;

	i = 0;
	while (world[i])
	{
		free(world[i]);
		i++;
	}
	free(world);
}

static void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->map_array && map->map_array[++i])
		free(map->map_array[i]);
	if (map->map_world)
		free_world(map->map_world);
	if (map->map_array)
		free(map->map_array);
	if (map->cub_array)
		free_split(map->cub_array);
	if (map->ea)
		free_pointers(1, &map->ea);
	if (map->no)
		free_pointers(1, &map->no);
	if (map->we)
		free_pointers(1, &map->we);
	if (map->so)
		free_pointers(1, &map->so);
	if (map->ceiling)
		free_pointers(1, &map->ceiling);
	if (map->floor)
		free_pointers(1, &map->floor);
}

static void	free_sprites(t_cube3d *game, t_sprite *sprites)
{
	if (sprites->no)
	{
		mlx_destroy_image(game->mlx_ptr, sprites->no->img);
		free(sprites->no);
	}
	if (sprites->so)
	{
		mlx_destroy_image(game->mlx_ptr, sprites->so->img);
		free(sprites->so);
	}
	if (sprites->ea)
	{
		mlx_destroy_image(game->mlx_ptr, sprites->ea->img);
		free(sprites->ea);
	}
	if (sprites->we)
	{
		mlx_destroy_image(game->mlx_ptr, sprites->we->img);
		free(sprites->we);
	}
	if (sprites->dirt)
	{
		mlx_destroy_image(game->mlx_ptr, sprites->dirt->img);
		free(sprites->dirt);
	}
}

void	free_game(t_cube3d *game)
{
	free_map(game->map);
	if (game->mlx_ptr && game->img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->img_ptr);
	free_sprites(game, game->sprites);
	if (game->mlx_ptr && game->img_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(0);
}
