/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:28:23 by joralves          #+#    #+#             */
/*   Updated: 2025/04/17 01:31:23 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	collision_door(t_cub3d *game)
{
	int		dir_pos[2];
	t_door	*door;

	dir_pos[0] = game->player.director[0] / TILE_SIZE;
	dir_pos[1] = game->player.director[1] / TILE_SIZE;
	door = find_door(game->map, dir_pos[0], dir_pos[1]);
	if (!door)
		return (0);
	if (door->is_open == 0)
		door->is_open = 1;
	else
		door->is_open = 0;
	return (0);
}

static int	wall_collision(t_map *map, float new_x, float new_y, float collider)
{
	int			tile_x;
	int			tile_y;
	int			i;
	t_door		*door;
	const float	corners[4][2] = {{new_x - collider, new_y - collider}, {new_x
		+ collider, new_y - collider}, {new_x - collider, new_y + collider},
	{new_x + collider, new_y + collider}};

	i = 0;
	while (i < 4)
	{
		tile_x = (int)(corners[i][0] / TILE_SIZE);
		tile_y = (int)(corners[i][1] / TILE_SIZE);
		door = find_door(map, tile_x, tile_y);
		if (tile_x < 0 || tile_x >= map->width || tile_y < 0
			|| tile_y >= map->height || map->map_world[tile_y][tile_x] == 1
			|| (door && !door->is_open))
			return (1);
		i++;
	}
	return (0);
}

void	check_collision(t_player *player, t_map *map, float new_x, float new_y)
{
	int	collision_x;
	int	collision_y;

	collision_x = wall_collision(map, new_x, player->y, player->collider);
	collision_y = wall_collision(map, player->x, new_y, player->collider);
	if (!collision_x && !collision_y)
	{
		player->x = new_x;
		player->y = new_y;
	}
	else if (!collision_x)
		player->x = new_x;
	else if (!collision_y)
		player->y = new_y;
}
