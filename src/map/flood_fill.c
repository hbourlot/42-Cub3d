/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:02:03 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/04 16:57:12 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void flood_fill(t_map *map, int x, int y, bool **map_visited)
{
    if (x < 0 || y < 0 || y >= map->height || x >= ft_strlen(map->map_array[y]))
        return ;
    map_visited[y][x] = true;
    flood_fill(map, x + 1, y, map_visited);
    flood_fill(map, x - 1, y, map_visited);
    flood_fill(map, y + 1, y, map_visited);
    flood_fill(map, y - 1, y, map_visited);

    return ;
}