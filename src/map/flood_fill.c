/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:02:03 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/12 07:31:45 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static int	flood_fill(t_game *game, int x, int y, bool **map_visited)
// {
// 	if (x < 0 || y < 0 || y >= game->map.height
// 		|| x >= (int)ft_strlen(game->map.map_grid[y])
// 		|| game->map.map_grid[y][x] == '1' || map_visited[y][x])
// 		return (0);
// 	map_visited[y][x] = true;
// 	flood_fill(game, x + 1, y, map_visited);
// 	flood_fill(game, x - 1, y, map_visited);
// 	flood_fill(game, x, y + 1, map_visited);
// 	flood_fill(game, x, y - 1, map_visited);
// 	return (0);
// }

void flood_fill(t_map *map, int x, int y, bool **map_visited)
{
    if (x < 0 || y < 0 || y >= map->height || x >= (int)ft_strlen(map->map_array[y]))
        return ;
    map_visited[y][x] = true;
    flood_fill(map, x + 1, y, map_visited);
    flood_fill(map, x - 1, y, map_visited);
    flood_fill(map, y + 1, y, map_visited);
    flood_fill(map, y - 1, y, map_visited);

    return ;
}