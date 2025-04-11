/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reachability.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:35:03 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/11 15:04:57 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "debug.h"


static int invalid_chars(t_map *map, int x, int y)
{
	const char *chars[] = {"1", "0", "N", "S", "E", "W", NULL};
	
	// printf("x: %d | y: %d\n", x, y);
	if (!ft_strstr_any(&map->map_array[y][x], chars))
	{
		printf("map_array[%x][%d]: '%c' value: %d\n", y, x , map->map_array[y][x], map->map_array[y][x]);
		// printf("OVER HERE\n");
		exit(0);
		return (-1);
	}

	return (0);
}

static bool **allocate_visited(t_map *map)
{
	bool	**map_visited;
	int		i;
	
	i = 0;
	map_visited = ft_calloc(map->height, sizeof(bool *));
	if (!map_visited)
		return (ft_printf_fd(2, ME_MALLOC), NULL);
	
	while (i < map->height)
	{
		printf("map->width: %d\n", map->width);
		map_visited[i] = ft_calloc(map->width, sizeof(bool));
		if (!map_visited[i])
		{
			while (--i >= 0)
				free(map_visited[i]);
			free(map_visited);
			return (ft_printf_fd(2, ME_MALLOC), NULL);
		}
		i++;
	}
	return (map_visited);
}

static int flood_fill(t_map *map, int x, int y, bool **map_visited)
{
	if (x < 0 || y < 0 || y >= map->height || x >= ft_strlen(map->map_array[y]))
		return 0;
	if (invalid_chars(map, x, y))
		return (ft_printf_fd(2, ME_MINFO), -1);
    map_visited[y][x] = true;
    flood_fill(map, x + 1, y, map_visited);
    flood_fill(map, x - 1, y, map_visited);
    flood_fill(map, y + 1, y, map_visited);
    flood_fill(map, y - 1, y, map_visited);

    return (0);
}


int	map_reachability(t_cub3d *game, t_map *map, int x, int y)
{
	bool	**map_visited;

	// print_map(game);
	// print_map_detailed(game);
	map_visited = allocate_visited(map);
	if (!map_visited)
		return (-1);
	if (flood_fill(map, x, y, map_visited))
		return (-1);
	return (0);

}
