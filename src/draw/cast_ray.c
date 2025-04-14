/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:48:00 by joralves          #+#    #+#             */
/*   Updated: 2025/04/14 01:59:57 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_s_ray(t_ray *ray)
{
	ray->dist = 1000000.0;
	ray->hit_side = 0;
	ray->tex_num = 0;
	ray->wall_x = 0;
}

void	init_s_dda_aux(t_dda *dda, double x, double y)
{
	if (dda->dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - x) * dda->delta_dist_x;
	}
	if (dda->dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - y) * dda->delta_dist_y;
	}
}

void	init_s_dda(t_dda *dda, double x, double y, double angle)
{
	dda->dir_x = cos(angle);
	dda->dir_y = -sin(angle);
	dda->map_x = (int)x;
	dda->map_y = (int)y;
	dda->delta_dist_x = fabs(1.0 / dda->dir_x);
	dda->delta_dist_y = fabs(1.0 / dda->dir_y);
	init_s_dda_aux(dda, x, y);
}

void	perform_dda_loop(t_map *map, t_ray *ray, t_dda *dda)
{
	while (map->map_world[dda->map_y][dda->map_x] == 0 || map->map_world[dda->map_y][dda->map_x] == 3)
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
		if (dda->map_x < 0 || dda->map_y < 0 || dda->map_x >= map->width
			|| dda->map_y >= map->height)
			break ;
	}
}

void	fill_s_ray(t_ray *ray, t_dda *dda, double x, double y)
{
	if (ray->hit_side == 0)
	{
		ray->dist = (dda->map_x - x + (1 - dda->step_x) / 2.0) / dda->dir_x;
		ray->wall_x = y + ray->dist * dda->dir_y;
	}
	else
	{
		ray->dist = (dda->map_y - y + (1 - dda->step_y) / 2.0) / dda->dir_y;
		ray->wall_x = x + ray->dist * dda->dir_x;
	}
	set_texture(ray, dda);
	ray->wall_x -= floor(ray->wall_x);
}

t_ray	cast_ray(t_map *map, double x, double y, double angle)
{
	t_ray	ray;
	t_dda	dda;

	init_s_ray(&ray);
	init_s_dda(&dda, x, y, angle);
	perform_dda_loop(map, &ray, &dda);
	ray.wall_hit = map->map_world[dda.map_y][dda.map_x];
	if (dda.map_x >= 0 && dda.map_x < map->width && dda.map_y >= 0
		&& dda.map_y < map->height)
		fill_s_ray(&ray, &dda, x, y);
	return (ray);
}
