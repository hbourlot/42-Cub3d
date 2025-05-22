/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:48:00 by joralves          #+#    #+#             */
/*   Updated: 2025/05/15 20:22:00 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	cast_ray(t_map *map, double x, double y, double angle)
{
	t_ray	ray;
	t_dda	dda;

	init_s_ray(&ray);
	init_s_dda(&dda, x, y, angle);
	perform_dda_loop(map, &ray, &dda);
	ray.wall_hit = map->map_world[dda.map_y][dda.map_x];
	if (ray.wall_hit == 2)
		ray.door = find_door(map, dda.map_x, dda.map_y);
	if (dda.map_x >= 0 && dda.map_x < map->width && dda.map_y >= 0
		&& dda.map_y < map->height)
		fill_s_ray(&ray, &dda, x, y);
	set_texture(map, &ray, &dda);
	return (ray);
}
