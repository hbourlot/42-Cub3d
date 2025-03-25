/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:00:36 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/25 17:28:59 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	init_game(t_cube3d *game)
{

	if (init_window(game) < 0)
		return (-1);
	// render(game);
	// drawRaycast(game);
	draw_map2d(game);
	// draw_player2d(game);
	game_loop(game);

	return(0);
}
