/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_spawn_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:13:30 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/11 12:37:11 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	locate_spawn_point(t_player *player, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[i][j])
		{
			if (ft_strchr(VPL, map->map_array[i][j]))
			{
				player->dir = map->map_array[i][j];
				player->x = j;
				player->y = i;
			}
			j++;
		}
		i++;
	}
	player->x = player->x * TILE_SIZE + TILE_SIZE / 2;
	player->y = player->y * TILE_SIZE + TILE_SIZE / 2;
}
