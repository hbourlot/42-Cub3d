/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:00:36 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/17 01:37:54 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_game(t_cub3d *game)
{
	if (init_window(game) < 0)
		return (-1);
	if (init_images(game) < 0)
		return (-1);
	if (init_doors(game->map) < 0)
		return (-1);
	init_player(game);
	if (init_s_sprite(game))
		return (1);
	if (map_reachability(game, game->map, game->player.x / TILE_SIZE,
			game->player.y / TILE_SIZE))
		return (ft_printf_fd(2, "Error: Map isn't surrounded by walls!"), -1);
	if (game_loop(game))
		return (-1);
	return (0);
}
