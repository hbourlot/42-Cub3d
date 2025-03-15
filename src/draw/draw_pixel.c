/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:06:21 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/15 19:01:38 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_pixel(t_sprite *sprite, int x, int y, int color)
{
	mlx_pixel_put(sprite->mlx_ptr, sprite->mlx_win, x, y, color);
}

void	my_mlx_pixel_put(t_cube3d *game, int x, int y, int color)
{
	mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, color);
}

void	draw_square(void *mlx, void *win, int x, int y, int color)
{
	for (int i = 0; i < TILE_SIZE; i++)
	{
		for (int j = 0; j < TILE_SIZE; j++)
		{
			mlx_pixel_put(mlx, win, x + i, y + j, color);
		}
	}
}
// Algoritmo de Bresenham para dibujar líneas
void	draw_line(t_cube3d *game, int x0, int y0, int x1, int y1, int color)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = (x0 < x1) ? 1 : -1;
	sy = (y0 < y1) ? 1 : -1;
	err = dx - dy;
	while (1)
	{
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = err * 2;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	draw_map2d(t_cube3d *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (game->map->map_array && game->map->map_array[y])
	{
		x = 0;
		while (game->map->map_array[y][x])
		{
			if (game->map->map_array[y][x] == '1')
				color = 0xFFFFFF;
			else
				color = 0x000000;
			draw_square(game->mlx_ptr, game->win_ptr, x * TILE_SIZE, y
				* TILE_SIZE, color);
			x++;
		}
		y++;
	}
	draw_player2d(game);
}

void	draw_player2d(t_cube3d *game)
{
	int	line_x;
	int	line_y;

	draw_square(game->mlx_ptr, game->win_ptr, game->player.x * TILE_SIZE,
		game->player.y * TILE_SIZE, 0xFFFF00);
	line_x = game->player.x * TILE_SIZE + TILE_SIZE / 2 + game->player.pdx * 15;
	line_y = game->player.y * TILE_SIZE + TILE_SIZE / 2 + game->player.pdy * 15;
	draw_line(game, game->player.x * TILE_SIZE + TILE_SIZE / 2, game->player.y
		* TILE_SIZE + TILE_SIZE / 2, line_x, line_y, 0x00FF00);
	// draw_rays2d(game, &game->player, game->map);
}
float	dist(float ax, float ay, float bx, float by, float ang)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	draw_background(t_cube3d *game)
{
	for (int x = MAP_WIDTH / 2; x < MAP_WIDTH; x++)
	{
		for (int y = 0; y < MAP_HEIGHT / 2; y++)
			my_mlx_pixel_put(game, x, y, 0x00FFFF);
		for (int y = MAP_HEIGHT / 2; y < MAP_HEIGHT; y++)
			my_mlx_pixel_put(game, x, y, 0x6B4F3B);
	}
}

// void	draw_rays2d(t_cube3d *game, t_player *player, t_map *map)
// {
// 	float	aTan;
// 	float	nTan;
// 	float	disT;

// 	// draw_background(game);
// 	float disH, hx, hy;
// 	float disV, vx, vy;
// 	int r, mx, my, mp, dof;
// 	float rx, ry, ra, xo, yo;
// 	ra = player->angle /* - DR * 30 */;
// 	printf("ra - %f\n", ra);
// 	if (ra < 0)
// 		ra += 2 * PI;
// 	if (ra > 2 * PI)
// 		ra -= 2 * PI;
// 	// ---Check Horizontal Lines---
// 	for (r = 0; r < 1; r++)
// 	{
// 		dof = 0;
// 		disH = 100000;
// 		hx = player->x;
// 		hy = player->y;
// 		aTan = -1 / tan(ra);
// 		if (ra > PI)
// 		{
// 			ry = (((int)player->y >> 6) << 6) - 0.0001;
// 			rx = (player->y - ry) * aTan + player->x;
// 			yo = -64;
// 			xo = -yo * aTan;
// 		}
// 		if (ra < PI)
// 		{
// 			ry = (((int)player->y >> 6) << 6) + 64;
// 			rx = (player->y - ry) * aTan + player->x;
// 			yo = 64;
// 			xo = -yo * aTan;
// 		}
// 		if (ra == 0 || ra == PI)
// 		{
// 			rx = player->x;
// 			ry = player->y;
// 			dof = 8;
// 		}
// 		while (dof < 8)
// 		{
// 			mx = (int)(rx) >> 6;
// 			my = (int)(ry) >> 6;
// 			mp = my * map->width + mx;
// 			if ((mx >= 0 && mx < map->width) && (my >= 0 && my < map->height)
// 				&& map->map_array[my][mx] == '1')
// 			{
// 				hx = rx;
// 				hy = ry;
// 				disH = dist(player->x, player->y, hx, hy, ra);
// 				dof = 8;
// 			}
// 			else
// 			{
// 				rx += xo;
// 				ry += yo;
// 				dof += 1;
// 			}
// 		}
// 		//---Check Vertical Lines---
// 		// dof = 0;
// 		disV = 100000;
// 		// vx = player->x;
// 		// vy = player->y;
// 		// nTan = -tan(ra);
// 		// if (ra > P2 && ra < P3)
// 		// {
// 		// 	rx = (((int)player->x >> 6) << 6) - 0.0001;
// 		// 	ry = (player->x - rx) * nTan + player->y;
// 		// 	xo = -64;
// 		// 	yo = -xo * nTan;
// 		// }
// 		// if (ra < P2 || ra > P3)
// 		// {
// 		// 	rx = (((int)player->x >> 6) << 6) + 64;
// 		// 	ry = (player->x - rx) * nTan + player->y;
// 		// 	xo = 64;
// 		// 	yo = -xo * nTan;
// 		// }
// 		// if (ra == 0 || ra == PI)
// 		// {
// 		// 	rx = player->x;
// 		// 	ry = player->y;
// 		// 	dof = 8;
// 		// }
// 		// while (dof < 8)
// 		// {
// 		// 	mx = (int)(rx) >> 6;
// 		// 	my = (int)(ry) >> 6;
// 		// 	mp = my * map->width + mx;
// 		// 	if ((mx >= 0 && mx < map->width) && (my >= 0 && my < map->height)
// 		// 		&& map->map_array[my][mx] == '1')
// 		// 	{
// 		// 		vx = rx;
// 		// 		vy = ry;
// 		// 		disV = dist(player->x, player->y, vx, vy, ra);
// 		// 		dof = 8;
// 		// 	}
// 		// 	else
// 		// 	{
// 		// 		rx += xo;
// 		// 		ry += yo;
// 		// 		dof ++;
// 		// 	}
// 		// }
// 		if (disV < disH)
// 		{
// 			rx = vx;
// 			ry = vy;
// 			disT = disV;
// 		}
// 		if (disH < disV)
// 		{
// 			rx = hx;
// 			ry = hy;
// 			disT = disH;
// 		}
// 		draw_line(game, game->player.x * TILE_SIZE + TILE_SIZE / 2,
// 			game->player.y * TILE_SIZE + TILE_SIZE / 2, rx, ry, 0xFF0000);
// 		// ra += DR;
// 		// if (ra < 0)
// 		// 	ra += 2 * PI;
// 		// if (ra > 2 * PI)
// 		// 	ra -= 2 * PI;
// 	}
// }


void	draw_rays2d(t_cube3d *game, t_player *player, t_map *map)
{

}
