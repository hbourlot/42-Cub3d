/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:01:42 by joralves          #+#    #+#             */
/*   Updated: 2025/03/25 17:02:12 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	dda_set_step(t_dda *dda, float x0, float y0)
{
	if (dda->dirX < 0)
	{
		dda->stepX = -1;
		dda->initialX = x0 - dda->gridX * TILE_SIZE;
	}
	else
	{
		dda->stepX = 1;
		dda->initialX = (dda->gridX + 1) * TILE_SIZE - x0;
	}
	if (dda->dirY < 0)
	{
		dda->stepY = -1;
		dda->initialY = y0 - dda->gridY * TILE_SIZE;
	}
	else
	{
		dda->stepY = 1;
		dda->initialY = (dda->gridY + 1) * TILE_SIZE - y0;
	}
}

void	init_dda(t_dda *dda, float x0, float y0, float angle)
{
	normalize_angle(&angle);
	dda->gridX = round(x0 / TILE_SIZE);
	dda->gridY = round(y0 / TILE_SIZE);
	dda->dirX = cos(angle);
	dda->dirY = -sin(angle);
	if (dda->dirX == 0)
		dda->dirX = EPSILON;
	if (dda->dirY == 0)
		dda->dirY = EPSILON;
	dda->sx_norm = sqrt(1 + (dda->dirY / dda->dirX) * (dda->dirY / dda->dirX));
	dda->sy_norm = sqrt(1 + (dda->dirX / dda->dirY) * (dda->dirX / dda->dirY));
	dda->sx = TILE_SIZE * dda->sx_norm;
	dda->sy = TILE_SIZE * dda->sy_norm;
	dda_set_step(dda, x0, y0);
	dda->acum_x = dda->initialX * dda->sx_norm;
	dda->acum_y = dda->initialY * dda->sy_norm;
	dda->counterX = 0;
	dda->counterY = 0;
}

void	draw_ray_lines(t_cube3d *game, t_dda *dda, float x0, float y0)
{
	draw_line(game, x0, y0, x0 + dda->initialX * dda->stepX + TILE_SIZE
		* (dda->counterX - 1) * dda->stepX, y0, 0x80CC80);
	draw_line(game, x0, y0, x0, y0 + dda->initialY * dda->stepY + TILE_SIZE
		* (dda->counterY - 1) * dda->stepY, 0xCC8080);
	draw_line(game, x0, y0, x0 + dda->initialX * dda->stepX + TILE_SIZE
		* (dda->counterX - 1) * dda->stepX, y0 + dda->initialY * dda->stepY
		+ TILE_SIZE * (dda->counterY - 1) * dda->stepY, 0x8080CC);
}

float	dda(t_cube3d *game, float x0, float y0, float angle)
{
	t_dda	dda;

	dda.grid = game->map->map_array;
	init_dda(&dda, x0, y0, angle);
	while (dda.grid[dda.gridY][dda.gridX] == '0')
	{
		if (dda.acum_x <= dda.acum_y)
		{
			dda.gridX += dda.stepX;
			dda.dist = dda.acum_x;
			dda.acum_x += dda.sx;
			dda.counterX++;
		}
		else
		{
			dda.gridY += dda.stepY;
			dda.dist = dda.acum_y;
			dda.acum_y = dda.acum_y + dda.sy;
			dda.counterY++;
		}
		if (dda.gridX < 0 || dda.gridY < 0 || dda.gridX >= game->map->width
			|| dda.gridY >= game->map->height)
			break ;
	}
	draw_ray_lines(game, &dda, x0, y0);
	return (dda.dist);
}

void	draw_raycast(t_cube3d *game)
{
	int		i;
	float	alpha;
	float	ray_angle;
	float	dist;
	int		wall_height;
	float	wall_start;
	float	perp_dist;
	i = 0;
	while (i < CANT_RAYS - 1)
	{
		alpha = FOV / 2 - ANGLE_PER_RAY * i;
		ray_angle = game->player.angle + alpha;
		normalize_angle(&ray_angle);
		dist = dda(game, game->player.x, game->player.y, ray_angle);
		perp_dist = dist * cos(alpha);
		wall_height = floor(WALL_SIZE * GAME_HEIGHT / perp_dist);
		wall_start = GAME_HEIGHT / 2 - wall_height / 2;
		for (int y = 0; y < wall_height; y++)
		{
			if (wall_start + y >= 0 && wall_start + y < GAME_HEIGHT)
			{
				my_mlx_pixel_put(game, i * RENDER_LINE_WIDTH, wall_start + y,
					create_rgb(100, 100, 50, 50));
			}
		}
		i++;
	}
}
