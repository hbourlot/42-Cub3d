/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:14:58 by hbourlot          #+#    #+#             */
/*   Updated: 2025/05/16 14:56:41 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_world(int **world)
{
	int	i;

	i = 0;
	while (world && world[i])
	{
		free(world[i]);
		i++;
	}
	if (world)
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

static void	free_sprites(t_cub3d *game, t_sprite *sprites)
{
	int			i;
	const t_img	*all_sprites[] = {sprites->no, sprites->so, sprites->we,
		sprites->ea, sprites->door_close, sprites->door_open, NULL};

	i = 0;
	while (i < 6)
	{
		if (all_sprites[i])
		{
			mlx_destroy_image(game->mlx_ptr, all_sprites[i]->img);
			free((void *)all_sprites[i]);
		}
		i++;
	}
}

void	free_game(int exit_status)
{
	t_cub3d	*game;

	game = get_cub();
	if (game->map->num_doors)
		free(game->map->doors);
	free_map(game->map);
	free_sprites(game, game->sprites);
	if (game->mlx_ptr && game->map_img.img)
		mlx_destroy_image(game->mlx_ptr, game->map_img.img);
	if (game->mlx_ptr && game->main_img.img)
		mlx_destroy_image(game->mlx_ptr, game->main_img.img);
	if (game->mlx_ptr && game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(exit_status);
}
