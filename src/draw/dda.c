/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:01:42 by joralves          #+#    #+#             */
/*   Updated: 2025/03/28 16:30:55 by joralves         ###   ########.fr       */
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

// void	render_walls(t_cube3d *game, t_raycast *raycast)
// {
// 	int			x;
// 	int			y;
// 	t_sprite	*text;
// 	int			color;

// 	text = game->sprites->dirt;
// 	x = raycast->x_start;
// 	while (x < raycast->x_end)
// 	{
// 		y = 0;
// 		while (y < raycast->wall_height)
// 		{
// 			raycast->screen_y = raycast->wall_start + y;
// 			if (raycast->screen_y >= 0 && raycast->screen_y < GAME_HEIGHT)
// 			{
// 				my_mlx_pixel_put(game, x, raycast->screen_y, create_rgb(100,
// 						100, 50, 50));
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// }
void	render_walls(t_cube3d *game, t_raycast *raycast)
{
	float	tex_pos_y;
	int		color;

	int x, y;
	t_sprite *texture = game->sprites->dirt; // Usamos solo "dirt"
	int tex_x, tex_y;
	// Coordenada X en la textura (simplificado sin 'side')
	float wall_hit_x = game->player.x + raycast->dist * cos(raycast->ray_angle);
		// Usamos solo X para simplificar
	wall_hit_x -= floor(wall_hit_x);
	tex_x = (int)(wall_hit_x * texture->width);
	x = raycast->x_start;
	while (x < raycast->x_end)
	{
		tex_pos_y = 0; // Empezamos desde arriba de la textura
		y = (raycast->wall_start < 0) ? 0 : raycast->wall_start;
		while (y < raycast->wall_start + raycast->wall_height
			&& y < GAME_HEIGHT)
		{
			tex_y = (int)(tex_pos_y) % texture->height; // Mapeo simple
			color = *(int *)(texture->addr + (tex_y * texture->size_line
						+ tex_x * (texture->bpp / 8)));
			my_mlx_pixel_put(game, x, y, color);
			tex_pos_y += (float)texture->height / raycast->wall_height;
				// Ajuste vertical
			y++;
		}
		x++;
	}
}

void	cast_render_raycast(t_cube3d *game)
{
	t_raycast	raycast;
	int			i;

	i = 0;
	raycast.column_width = (int)((float)GAME_WIDTH / (float)CANT_RAYS);
	if (raycast.column_width < 1)
		raycast.column_width = 1;
	while (i < CANT_RAYS)
	{
		raycast.alpha = FOV / 2 - ANGLE_PER_RAY * i;
		raycast.ray_angle = game->player.angle + raycast.alpha;
		normalize_angle(&raycast.ray_angle);
		raycast.dist = dda(game, game->player.x, game->player.y,
				raycast.ray_angle);
		raycast.perp_dist = raycast.dist * cos(raycast.alpha);
		raycast.wall_height = (int)(WALL_SIZE * GAME_HEIGHT
				/ raycast.perp_dist);
		raycast.wall_start = GAME_HEIGHT / 2 - raycast.wall_height / 2;
		raycast.x_start = i * raycast.column_width;
		raycast.x_end = (i + 1) * raycast.column_width;
		if (raycast.x_end > GAME_WIDTH)
			raycast.x_end = GAME_WIDTH;
		render_walls(game, &raycast);
		i++;
	}
}
