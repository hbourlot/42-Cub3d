/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:06:21 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/31 16:43:29 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	get_greater_num(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// void	draw_pixel(t_sprite *sprite, int x, int y, int color)
// {
// 	mlx_pixel_put(sprite->mlx_ptr, sprite->mlx_win, x, y, color);
// }

void	my_mlx_pixel_put(t_cube3d *game, int x, int y, int color)
{
	mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, color);
}

void	draw_square(t_cube3d *game, int x, int y, int width, int height,
		int color)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			mlx_pixel_put(game->mlx_ptr, game->win_ptr, x + i, y + j, color);
		}
	}
}

void	draw_line(t_cube3d *game, float x0, float y0, float x1, float y1,
		int color)
{
	t_line	lines;
	int		i;

	ft_memset(&lines, 0, sizeof(t_line));
	i = 0;
	lines.dx = x1 - x0;
	lines.dy = y1 - y0;
	lines.steps = get_greater_num(abs(lines.dx), abs(lines.dy));
	lines.x_inc = (float)lines.dx / lines.steps;
	lines.y_inc = (float)lines.dy / lines.steps;
	while (i <= lines.steps)
	{
		mlx_pixel_put(game->mlx_ptr, game->win_ptr, round(x0), round(y0),
			color);
		x0 += lines.x_inc;
		y0 += lines.y_inc;
		i++;
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
			draw_square(game, x * TILE_SIZE, y * TILE_SIZE, TILE_SIZE,
				TILE_SIZE, color);
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

	draw_square(game, game->player.x - TILE_SIZE / 2, game->player.y - TILE_SIZE
		/ 2, TILE_SIZE, TILE_SIZE, 0xc0c0c0);
	// draw_square(game, game->player.x, game->player.y, TILE_SIZE, TILE_SIZE,
	// 	0xFFFF00);
	// line_x = game->player.x + game->player.pdx * 3 * TILE_SIZE;
	// line_y = game->player.y + game->player.pdy * 3 * TILE_SIZE;
	// draw_line(game, game->player.x, game->player.y, line_x, line_y,
	// 0x00FF00);
	// DDA(game, game->player.x, game->player.y, game->player.angle);
	// cast_render_raycast(game);
}

void	draw_background(t_cube3d *game)
{
	for (int x = SCREEN_WIDTH / 2; x < SCREEN_WIDTH; x++)
	{
		for (int y = 0; y < SCREEN_HEIGHT / 2; y++)
			my_mlx_pixel_put(game, x, y, 0x00FFFF);
		for (int y = SCREEN_HEIGHT / 2; y < SCREEN_HEIGHT; y++)
			my_mlx_pixel_put(game, x, y, 0x6B4F3B);
	}
}
