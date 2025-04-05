/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:01:42 by joralves          #+#    #+#             */
/*   Updated: 2025/04/05 11:14:05 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda_set_step(t_dda *dda, float x0, float y0)
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

void	init_dda(t_dda *dda, float x0, float y0, float angle)
{
	normalize_angle(&angle);
	dda->grid_x = round(x0 / TILE_SIZE);
	dda->grid_y = round(y0 / TILE_SIZE);
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
	dda->counter_x = 0;
	dda->counter_y = 0;
}

void	draw_ray_lines(t_cub3d *game, t_dda *dda, float x0, float y0)
{
	// draw_line(game, x0, y0, x0 + dda->initialX * dda->stepX + TILE_SIZE
	// 	* (dda->counterX - 1) * dda->stepX, y0, 0x80CC80);
	// draw_line(game, x0, y0, x0, y0 + dda->initialY * dda->stepY + TILE_SIZE
	// 	* (dda->counterY - 1) * dda->stepY, 0xCC8080);
	draw_line(game, x0, y0, x0 + dda->initial_x * dda->step_x + TILE_SIZE
		* (dda->counter_x - 1) * dda->step_x, y0 + dda->initial_y * dda->step_y
		+ TILE_SIZE * (dda->counter_y - 1) * dda->step_y, 0x8080CC);
}

void	dda(t_cub3d *game, t_raycast *raycast, float x0, float y0)
{
	t_dda	*dda;

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
			dda->counter_x++;
		}
		else
		{
			dda->grid_y += dda->step_y;
			dda->dist = dda->acum_y;
			dda->acum_y = dda->acum_y + dda->sy;
			dda->hitside = 0;
			dda->counter_y++;
		}
		if (dda->grid_x < 0 || dda->grid_y < 0
			|| dda->grid_x >= game->map->width
			|| dda->grid_y >= game->map->height)
			break ;
	}
	raycast->dist = raycast->dda.dist;
	draw_ray_lines(game, dda, x0, y0);
}

void	render_walls(t_cub3d *game, t_raycast *raycast, int color)
{
	int	x;
	int	y;

	x = raycast->x_start;
	while (x < raycast->x_end)
	{
		y = 0;
		while (y < raycast->wall_height)
		{
			raycast->screen_y = raycast->wall_start + y;
			if (raycast->screen_y >= 0 && raycast->screen_y < SCREEN_HEIGHT)
				my_mlx_pixel_put(game, x, raycast->screen_y, color);
			y++;
		}
		x++;
	}
}

void	cast_render_raycast(t_cub3d *game)
{
	t_raycast	raycast;
	int			i;
	int			color;

	i = 0;
	raycast.column_width = (int)((float)SCREEN_WIDTH / (float)SCREEN_WIDTH);
	if (raycast.column_width < 1)
		raycast.column_width = 1;
	while (i < SCREEN_WIDTH)
	{
		raycast.alpha = FOV / 2 - FOV/SCREEN_WIDTH * i;
		raycast.ray_angle = game->player.angle + raycast.alpha;
		normalize_angle(&raycast.ray_angle);
		dda(game, &raycast, game->player.x, game->player.y);
		raycast.perp_dist = raycast.dist * cos(raycast.alpha);
		raycast.wall_height = (int)(WALL_SIZE * SCREEN_HEIGHT
				/ raycast.perp_dist);
		raycast.wall_start = SCREEN_HEIGHT / 2 - raycast.wall_height / 2;
		raycast.x_start = i * raycast.column_width;
		raycast.x_end = (i + 1) * raycast.column_width;
		if (raycast.x_end > SCREEN_WIDTH)
			raycast.x_end = SCREEN_WIDTH;
		if (raycast.dda.hitside == 1)
			color = create_rgb(0, 255, 0, 0);
		else
			color = create_rgb(0, 0, 0, 255);
		render_walls(game, &raycast, color);
		i++;
	}
}

// void	render_walls(t_cube3d *game, t_raycast *raycast)
// {
// 	float tex_pos_y;
// 	int color;
// 	float wall_hit_x;

// 	int x, y;
// 	t_img *texture = game->sprites->dirt; // Usamos solo "dirt"
// 	int tex_x, tex_y;
// 	wall_hit_x = game->player.x + raycast->dist * cos(raycast->ray_angle);
// 	wall_hit_x -= floor(wall_hit_x);
// 	tex_x = (int)(wall_hit_x * texture->width);
// 	x = raycast->x_start;
// 	while (x < raycast->x_end)
// 	{
// 		tex_pos_y = 0;
// 		y = (raycast->wall_start < 0) ? 0 : raycast->wall_start;
// 		while (y < raycast->wall_start + raycast->wall_height
// 			&& y < GAME_HEIGHT)
// 		{
// 			tex_y = (int)(tex_pos_y) % texture->height;
// 			color = *(int *)(texture->addr + (tex_y * texture->size_line + tex_x
// 						* (texture->bpp / 8)));
// 			my_mlx_pixel_put(game, x, y, color);
// 			tex_pos_y += (float)texture->height / raycast->wall_height;
// 			y++;
// 		}
// 		x++;
// 	}
// }