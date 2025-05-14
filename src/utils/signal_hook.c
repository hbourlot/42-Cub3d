/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:55:38 by hbourlot          #+#    #+#             */
/*   Updated: 2025/05/13 23:43:39 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_signal(int x, int y, t_cub3d *game)
{
	int	dx;
	if (game->mouse_on == false)
		return(0);
	(void)y;
	dx = x - game->mouse_x;
	if (dx < 0)
		rotate_player(&game->player, XK_a, MOUSE_SIGNAL);
	else if (dx > 0)
		rotate_player(&game->player, XK_d, MOUSE_SIGNAL);
	mlx_mouse_move(game->mlx_ptr, game->win_ptr, S_WIDTH / 2, S_HEIGHT / 2);
	game->mouse_x = S_WIDTH / 2;
	game->mouse_y = S_HEIGHT / 2;
	return (0);
}

int	key_press(int keycode, t_cub3d *game)
{
	if (keycode == XK_Escape)
	{
		ft_printf_fd(1, "You pressed %d (Esc)\n", keycode);
		free_game(game);
	}
	if (keycode == XK_w || keycode == XK_s || keycode == XK_Up
		|| keycode == XK_Down)
		move_player(game->map, &game->player, keycode);
	if (keycode == XK_a || keycode == XK_d || keycode == XK_Left
		|| keycode == XK_Right)
		rotate_player(&game->player, keycode, KEY_SIGNAL);
	if (keycode == XK_space)
		collision_door(game);
	if (keycode == XK_Control_L)
	{
		game->mouse_on = !game->mouse_on;
		printf("Here %d \n", game->mouse_on);
	}
	return (0);
}
