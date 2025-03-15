/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:55:38 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/15 18:37:43 by joralves         ###   ########.fr       */
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
	if (keycode == XK_w)
		move_player(game, 0, game->player.pdx, game->player.pdy);
	if (keycode == XK_s)
		move_player(game, 0, -game->player.pdx, -game->player.pdy);
	if (keycode == XK_a)
		move_player(game, -0.1, 0, 0);
	if (keycode == XK_d)
		move_player(game, +0.1, 0, 0);

	return(0);
}
