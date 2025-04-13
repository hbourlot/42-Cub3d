/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reachability.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:35:03 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/12 18:48:40 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "debug.h"


static int invalid_chars(t_map *map, int x, int y)
{
	const char *chars[] = {"1", "0", "N", "S", "E", "W", "\n", NULL};
	
	// printf("x: %d | y: %d\n", x, y);
	if (!ft_strstr_any(&map->map_array[y][x], chars))
	{
		printf("map_array[%d][%d]: '%c' value: %d\n", y, x , map->map_array[y][x], map->map_array[y][x]);
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
	// printf("map->map_array[%d]: len -> %ld\n", y, ft_strlen(map->map_array[y]));
	// printf("x: %d\n", x);
	if (x < 0 || y < 0 || y >= map->height || x >= ft_strlen(map->map_array[y]) || map_visited[y][x])
		return (0);
	if (invalid_chars(map, x, y))
		return (ft_printf_fd(2, ME_MINFO), -1);
    map_visited[y][x] = true;
    flood_fill(map, x + 1, y, map_visited);
    flood_fill(map, x - 1, y, map_visited);
    flood_fill(map, x, y + 1, map_visited);
    flood_fill(map, x, y - 1, map_visited);

    return (0);
}


int	map_reachability(t_cub3d *game, t_map *map, int x, int y)
{
	bool	**map_visited;

	// printf("map->height: %d\n", map->height);
	// printf("x: %d | y: %d\n", x, y);
	// printf("char: '%c'\n", map->map_array[y][x]);
	// print_map(game);
	// print_map_detailed(game);
	map_visited = allocate_visited(map);
	if (!map_visited)
		return (-1);
	// printf("map->height: %d\n", map->height);
	if (flood_fill(map, x, y, map_visited))
		return (-1);
	return (0);

}
