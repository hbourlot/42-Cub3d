/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reachability.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:35:03 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/11 12:48:04 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static int invalid_chars(t_map *map, int x, int y)
{
	const char *chars[] = {"1", "0", "N", "S", "E", "W", NULL};
	
	printf("OVER HERE\n");
	printf("x: %d | y: %d\n", x, y);
	if (!ft_strstr_any(&map->map_array[y][x], chars))
	{
		printf("OVER HERE\n");
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
		return (-1);
	
	while (i < map->height)
	{
		map_visited[i] = ft_calloc(map->width, sizeof(bool));
		if (!map_visited[i])
		{
			while (i--)
				free(map_visited[i]);
			free(map_visited);
			ft_printf_fd(2, ME_MALLOC);
			return (NULL);
		}
		i++;
	}
	return (map_visited);
}

static int flood_fill(t_map *map, int x, int y, bool **map_visited)
{
	if (invalid_chars(map, x, y))
		return -1;
    if (x < 0 || y < 0 || y >= map->height || x >= ft_strlen(map->map_array[y]))
        return 0;
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

	map_visited = allocate_visited(map);
	if (!map_visited)
		return (-1);
	if (flood_fill(map, x, y, map_visited))
	{
		ft_printf_fd(2, ME_MINFO);
		return (-1);
		
	}
	
	return (0);

}
