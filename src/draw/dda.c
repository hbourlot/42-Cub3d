/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:01:42 by joralves          #+#    #+#             */
/*   Updated: 2025/04/10 20:04:58 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	dda_set_step(t_dda *dda, float x0, float y0)
{
	if (dda->dir_x < 0)
	{
		dda->step_x = -1;
		dda->initial_x = x0 - dda->grid_x * TILE_SIZE;
	}
	else
	{
		dda->step_x = 1;
		dda->initial_x = (dda->grid_x + 1) * TILE_SIZE - x0;
	}
	if (dda->dir_y < 0)
	{
		dda->step_y = -1;
		dda->initial_y = y0 - dda->grid_y * TILE_SIZE;
	}
	else
	{
		dda->step_y = 1;
		dda->initial_y = (dda->grid_y + 1) * TILE_SIZE - y0;
	}
}

static void	init_dda(t_dda *dda, float x0, float y0, float angle)
{
	dda->grid_x = (int)(x0 / TILE_SIZE);
	dda->grid_y = (int)(y0 / TILE_SIZE);
	dda->dir_x = cos(angle);
	dda->dir_y = -sin(angle);
	if (dda->dir_x == 0)
		dda->dir_x = EPSILON;
	if (dda->dir_y == 0)
		dda->dir_y = EPSILON;
	dda->sx_norm = sqrt(1 + (dda->dir_y / dda->dir_x) * (dda->dir_y
				/ dda->dir_x));
	dda->sy_norm = sqrt(1 + (dda->dir_x / dda->dir_y) * (dda->dir_x
				/ dda->dir_y));
	dda->sx = TILE_SIZE * dda->sx_norm;
	dda->sy = TILE_SIZE * dda->sy_norm;
	dda_set_step(dda, x0, y0);
	dda->acum_x = dda->initial_x * dda->sx_norm;
	dda->acum_y = dda->initial_y * dda->sy_norm;
}

void	draw_ray_lines(t_cub3d *game, t_dda *dda, float x0, float y0)
{
	// draw_line(game, x0, y0, x0 + dda->initialX * dda->stepX + TILE_SIZE
	// 	* (dda->counterX - 1) * dda->stepX, y0, 0x80CC80);
	// draw_line(game, x0, y0, x0, y0 + dda->initialY * dda->stepY + TILE_SIZE
	// 	* (dda->counterY - 1) * dda->stepY, 0xCC8080);
// 	draw_line(game, x0, y0, x0 + dda->initial_x * dda->step_x + TILE_SIZE
// 		* (dda->counter_x - 1) * dda->step_x, y0 + dda->initial_y * dda->step_y
// 		+ TILE_SIZE * (dda->counter_y - 1) * dda->step_y, 0x8080CC);
}

void	dda(t_cub3d *game, t_raycast *raycast, float x0, float y0)
{
	t_dda	*dda;

	// printf("x- %f y-%f\n ", x0, y0);
	dda = &raycast->dda;
	dda->grid_int = game->map->map_world;
	init_dda(dda, x0, y0, raycast->ray_angle);
	while (dda->grid_int[dda->grid_y][dda->grid_x] == 0)
	{
		if (dda->acum_x <= dda->acum_y)
		{
			dda->grid_x += dda->step_x;
			dda->dist = dda->acum_x;
			dda->acum_x += dda->sx;
			dda->hitside = 1;
		}
		else
		{
			dda->grid_y += dda->step_y;
			dda->dist = dda->acum_y;
			dda->acum_y = dda->acum_y + dda->sy;
			dda->hitside = 0;
		}
		if (dda->grid_x < 0 || dda->grid_y < 0
			|| dda->grid_x >= game->map->width
			|| dda->grid_y >= game->map->height)
			break ;
	}
	if (dda->hitside == 1)
		raycast->wall_x = y0 + dda->dist * dda->dir_y;
	else
		raycast->wall_x = x0 + dda->dist * dda->dir_x;
	raycast->wall_x -= floor(raycast->wall_x);
	// printf("%f\n", raycast->wall_x);
	raycast->dist = raycast->dda.dist;
	// draw_ray_lines(game, dda, x0, y0);
}
