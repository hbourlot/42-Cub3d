/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_door.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:05:55 by joralves          #+#    #+#             */
/*   Updated: 2025/04/17 01:16:41 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	perform_dda_loop_door(t_map *map, t_ray *ray, t_dda *dda,
		t_door *door)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			ray->hit_side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			ray->hit_side = 1;
		}
		door = find_door(map, dda->map_x, dda->map_y);
		if ((door && !door->is_open)
			|| map->map_world[dda->map_y][dda->map_x] == 1)
			hit = 1;
		if (dda->map_x < 0 || dda->map_y < 0 || dda->map_x >= map->width
			|| dda->map_y >= map->height)
			break ;
	}
}

t_ray	cast_ray_door(t_map *map, double x, double y, double angle)
{
	t_ray	ray;
	t_dda	dda;
	t_door	*door;

	door = NULL;
	init_s_ray(&ray);
	init_s_dda(&dda, x, y, angle);
	perform_dda_loop_door(map, &ray, &dda, door);
	ray.wall_hit = map->map_world[dda.map_y][dda.map_x];
	if (dda.map_x >= 0 && dda.map_x < map->width && dda.map_y >= 0
		&& dda.map_y < map->height)
		fill_s_ray(&ray, &dda, x, y);
	set_texture(map, &ray, &dda);
	return (ray);
}
