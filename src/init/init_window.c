/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:42:02 by joralves          #+#    #+#             */
/*   Updated: 2025/04/28 22:09:11 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_window(t_cub3d *game)
{
	t_screen	*screen;

	screen = init_s_screen();
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (ft_printf_fd(2, ME_MF), free_game(1));
	mlx_get_screen_size(game->mlx_ptr, &screen->width, &screen->height);
	if (S_WIDTH > screen->width || S_HEIGHT > screen->height)
		return (ft_printf_fd(2, ME_RES), free_game(1));
	game->win_ptr = mlx_new_window(game->mlx_ptr, S_WIDTH, S_HEIGHT, "Cube-3D");
	if (!game->win_ptr)
		return (ft_printf_fd(2, ME_NW), free_game(1));
}
