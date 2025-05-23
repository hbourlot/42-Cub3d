/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_spawn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:13:30 by hbourlot          #+#    #+#             */
/*   Updated: 2025/05/23 11:34:32 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_player_error(char *msg)
{
	ft_printf_fd(STDERR_FILENO, msg);
	free_game(2);
}

void	set_player_spawn(t_player *player, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[i][j])
		{
			if (ft_strchr(VPL, map->map_array[i][j]) && player->x != 0)
				handle_player_error("Error: Duplicated player\n");
			if (ft_strchr(VPL, map->map_array[i][j]))
			{
				player->dir = map->map_array[i][j];
				player->x = j * TILE_SIZE + TILE_SIZE / 2;
				player->y = i * TILE_SIZE + TILE_SIZE / 2;
			}
			j++;
		}
		i++;
	}
	if (player->x == 0)
		handle_player_error("Error: Missing player parameter\n");
}
