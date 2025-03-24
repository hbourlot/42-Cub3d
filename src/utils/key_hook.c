/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:55:38 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/24 01:01:00 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	key_press(int keycode, t_cube3d *game)
{
	if (keycode == XK_Escape)
	{
		ft_printf_fd(1, "You pressed %d (Esc)\n", keycode);
		free_game(game);
	}
	if (keycode == XK_w || keycode == XK_s)
		move_player(game->map, &game->player, keycode);
	if (keycode == XK_a || keycode == XK_d)
		rotate_player(&game->player, keycode);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	draw_map2d(game);
	// drawRaycast(game);

	return (0);
}
