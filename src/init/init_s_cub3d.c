/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:11:01 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/28 22:40:10 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_screen	*init_s_screen(void)
{
	static t_screen	screen;

	return (&screen);
}

void	init_s_cub3d(t_cub3d *game, char *argv[])
{
	game->map->path = argv[1];
	game->map->nbr_of_lines = count_lines(argv[1]);
	if (game->map->nbr_of_lines == 0)
		return (ft_printf_fd(2, ME_EM), free_game(1));
	init_cub_array(game->map);
	init_fc(game->map, game->sprites);
	parse_s_map(game->map);
	init_window(game);
	init_images(game);
	init_doors(game->map);
	init_player(game);
	init_s_sprite(game);
	if (map_reachability(game->map)) 
	{
		ft_printf_fd(2, "Error: Map isn't surrounded by walls!");
		free_game(1);
	}
}
