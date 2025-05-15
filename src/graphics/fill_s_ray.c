/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_s_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:14:52 by hbourlot          #+#    #+#             */
/*   Updated: 2025/05/15 20:15:04 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	ray->wall_x -= floor(ray->wall_x);
}
