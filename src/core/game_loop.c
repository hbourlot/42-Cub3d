/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:53:39 by hbourlot          #+#    #+#             */
/*   Updated: 2025/05/16 14:57:02 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw(t_cub3d *game)
{
	raycaster(game, &game->player);
	draw_map2d(game, game->map);
	return (0);
}

static int	close_window(void)
{
	free_game(0);
	return (0);
}

void	game_loop(t_cub3d *game)
{
	mouse_handler(game);
	mlx_hook(game->win_ptr, 2, 1L << 0, key_press, game);
	mlx_hook(game->win_ptr, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx_ptr, draw, game);
	mlx_loop(game->mlx_ptr);
}
