/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reachability.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:35:03 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/14 01:33:26 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	**allocate_visited(t_map *map)
{
	bool	**map_visited;
	int		i;

	i = 0;
	map_visited = ft_calloc(map->height + 1, sizeof(bool *));
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

static int	flood_fill(t_map *map, int x, int y, bool **map_visited)
{
	if (x < 0 || y < 0 || y >= map->height || x >= ft_strlen(map->map_array[y]))
		return (-1);
	if (map_visited[y][x])
		return (0);
	if (map->map_array[y][x] == '0' || map->map_array[y][x] == 'N'
		|| map->map_array[y][x] == '2')
	{
		map_visited[y][x] = true;
		if (flood_fill(map, x + 1, y, map_visited) || flood_fill(map, x - 1, y,
				map_visited) || flood_fill(map, x, y + 1, map_visited)
			|| flood_fill(map, x, y - 1, map_visited))
			return (-1);
	}
	else if (map->map_array[y][x] != '1')
		return (-1);
	return (0);
}

void	free_visited(bool **map_visited)
{
	int	i;

	i = 0;
	while (map_visited[i])
	{
		free(map_visited[i]);
		i++;
	}
	free(map_visited);
}

void	reload_map_visited(bool **map_visited)
{
	int	i;

	i = 0;
	while (map_visited[i])
	{
		ft_memset(map_visited[i], 0, sizeof(map_visited[i]));
		i++;
	}
}

int	map_reachability(t_cub3d *game, t_map *map, int x, int y)
{
	bool	**map_visited;
	int		i;
	int		j;

	map_visited = allocate_visited(map);
	if (!map_visited)
		return (-1);
	i = -1;
	while (map->map_array[++i])
	{
		j = -1;
		while (map->map_array[i][++j])
		{
			if (map->map_array[i][j] == '0')
			{
				if (flood_fill(map, j, i, map_visited))
					return (free_visited(map_visited), -1);
				else
					reload_map_visited(map_visited);
			}
		}
	}
	free_visited(map_visited);
	return (0);
}
