/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:59:35 by joralves          #+#    #+#             */
/*   Updated: 2025/04/01 01:02:45 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_cube3d *game, int x, int y)
{
	t_player	*player;

	player = &game->player;
	locate_spawn_point(&game->player, game->map);
	player->x = player->x * TILE_SIZE + TILE_SIZE / 2;
	player->y = player->y * TILE_SIZE + TILE_SIZE / 2;
	player->angle = P2;
	player->pdx = cos(player->angle) * SPEED;
	player->pdy = -sin(player->angle) * SPEED;
}

void	normalize_angle(float *angle)
{
	if (*angle < 0)
		*angle += 2 * PI;
	if (*angle > 2 * PI)
		*angle -= 2 * PI;
}
