/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 22:53:39 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/06 22:57:23 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


int	game_loop(t_cube3d *game)
{
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, key_press, game);
	mlx_loop(game->mlx_ptr);
	return 0;
}