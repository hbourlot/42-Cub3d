/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:59:35 by joralves          #+#    #+#             */
/*   Updated: 2025/05/15 20:29:12 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_rotation(t_player *player)
{
	if (player->dir == 'N')
		player->angle = PI / 2;
	if (player->dir == 'E')
		player->angle = 0;
	if (player->dir == 'W')
		player->angle = PI;
	if (player->dir == 'S')
		player->angle = 3 * PI / 2;
}

void	init_player(t_cub3d *game)
{
	t_player	*player;

	player = &game->player;
	set_player_spawn(&game->player, game->map);
	init_rotation(player);
	player->pdx = cos(player->angle) * SPEED;
	player->pdy = -sin(player->angle) * SPEED;
	player->collider = TILE_SIZE / 2 - 2;
	player->director[0] = player->x + player->pdx * TILE_SIZE;
	player->director[1] = player->y + player->pdy * TILE_SIZE;
}

void	normalize_angle(float *angle)
{
	if (*angle < 0)
		*angle += 2 * PI;
	if (*angle > 2 * PI)
		*angle -= 2 * PI;
}
