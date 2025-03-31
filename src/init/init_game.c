/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:00:36 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/31 17:46:05 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	init_game(t_cube3d *game, int argc, char *argv[])
{
	if (init_s_cube3d(&game, argc, argv) < 0)
		return (-1);
	if (init_window(game) < 0)
		return (-1);
	init_player(game, 1, 1);
	init_dirt_sprite(game);
	if (init_s_sprite(game))
		return (1);
	game_loop(game);
	return (0);
}
