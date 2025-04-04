/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:53:39 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/04 22:32:14 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	draw(t_cub3d *game)
{
	cast_render_raycast(game);
	draw_map2d(game);
	return (0);
}

int	game_loop(t_cub3d *game)
{
	if (map_reachability(game, game->map, game->player.x, game->player.y))
		return (-1);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_press, game);
	mlx_loop_hook(game->mlx_ptr, draw, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
