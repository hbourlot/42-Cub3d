/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:53:39 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/28 17:15:19 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	draw(t_cube3d *game)
{
	cast_render_raycast(game);
	draw_map2d(game);
}

int	game_loop(t_cube3d *game)
{
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_press, game);
	mlx_loop_hook(game->mlx_ptr, draw, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
