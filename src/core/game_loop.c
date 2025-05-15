/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:53:39 by hbourlot          #+#    #+#             */
/*   Updated: 2025/05/15 20:53:40 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw(t_cub3d *game)
{
	raycaster(game, &game->player);
	draw_map2d(game, game->map);
	return (0);
}

static int close_window( void )
{
    free_game(0);
    return (0);
}

void game_loop(t_cub3d *game)
{
    mouse_handler(game);
    mlx_hook(game->win_ptr, 2, 1L << 0, key_press, game); // KeyPress event
    mlx_hook(game->win_ptr, 17, 0, close_window, game);  // DestroyNotify event
    mlx_loop_hook(game->mlx_ptr, draw, game);
    mlx_loop(game->mlx_ptr);
}
