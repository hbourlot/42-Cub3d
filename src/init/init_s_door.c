/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:01:17 by joralves          #+#    #+#             */
/*   Updated: 2025/04/15 15:51:17 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_door *populate_door(t_map *map, t_dda *dda , t_ray *ray)
{
	t_door *door = find_door(map,dda->map_x,dda->map_y);
	if(!door)
		return(NULL);
	door->dda.step_x = dda->step_x;
	door->dda.step_y = dda->step_y;
	door->dda.dir_y = dda->dir_y;
	door->dda.dir_x = dda->dir_x;
	door->hit_side = ray->hit_side;
	return(door);
}

t_door	*find_door(t_map *map, int x, int y)
{
	int	i;

	i = 0;
	while (i < map->num_doors)
	{
		if (map->doors[i].x == x && map->doors[i].y == y)
			return (&map->doors[i]);
		i++;
	}
	return (NULL);
}
static void	count_doors(t_map *map)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map_world[y][x] == 2)
				count++;
			x++;
		}
		y++;
	}
	map->num_doors = count;
}

int	init_doors(t_map *map)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	count_doors(map);
	if (map->num_doors == 0)
		return (0);
	map->doors = malloc(map->num_doors * sizeof(t_door));
	if (!map->doors)
		return (-1);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map_world[y][x] == 2)
			{
				map->doors[i].x = x;
				map->doors[i].y = y;
				map->doors[i].is_open = 0;
				// map->doors[i].timer = 0.0;
				// map->map_world[y][x] = 0;
				i++;
			}
			x++;
		}
		y++;
	}
	return (0);
}
