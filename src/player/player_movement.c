/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 23:53:30 by joralves          #+#    #+#             */
/*   Updated: 2025/04/14 01:35:35 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_player *player, int keycode, int signal)
{
	float	rot_speed;

	if (signal == KEY_SIGNAL)
		rot_speed = KEY_ROT_SPEED;
	else if (signal == MOUSE_SIGNAL)
		rot_speed = MOUSE_ROT_SPEED;
	if (keycode == XK_a || keycode == XK_Left)
		player->angle += rot_speed;
	if (keycode == XK_d || keycode == XK_Right)
		player->angle -= rot_speed;
	normalize_angle(&player->angle);
	player->pdx = cos(player->angle) * SPEED;
	player->pdy = -sin(player->angle) * SPEED;
}

int	wall_collision(t_map *map, float new_x, float new_y, float collider)
{
	int			tile_x;
	int			tile_y;
	int			i;
	const float	corners[4][2] = {{new_x - collider, new_y - collider}, {new_x
		+ collider, new_y - collider}, {new_x - collider, new_y + collider},
	{new_x + collider, new_y + collider}};

	i = 0;
	while (i < 4)
	{
		tile_x = (int)(corners[i][0] / TILE_SIZE);
		tile_y = (int)(corners[i][1] / TILE_SIZE);
		if (tile_x < 0 || tile_x >= map->width || tile_y < 0
			|| tile_y >= map->height || map->map_world[tile_y][tile_x] == 1)
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

void	move_player(t_map *map, t_player *player, int keycode)
{
	float	new_x;
	float	new_y;

	new_x = player->x;
	new_y = player->y;
	if (keycode == XK_w || keycode == XK_Up)
	{
		new_x += player->pdx;
		new_y += player->pdy;
	}
	else if (keycode == XK_s || keycode == XK_Down)
	{
		new_x -= player->pdx;
		new_y -= player->pdy;
	}
	check_collision(player, map, new_x, new_y);
}

void	mouse_handler(t_cub3d *game)
{
	// mlx_mouse_hide(game->mlx_ptr, game->win_ptr);
	mlx_mouse_move(game->mlx_ptr, game->win_ptr, MAP_WIDTH / 2, MAP_HEIGHT / 2);
	game->mouse_x = S_WIDTH / 2;
	game->mouse_y = S_HEIGHT / 2;
	mlx_hook(game->win_ptr, MotionNotify, PointerMotionMask, mouse_signal,
		game);
}
