/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_spawn_point.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:13:30 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/01 01:01:48 by joralves         ###   ########.fr       */
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
}
