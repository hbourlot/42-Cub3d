/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:06:21 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/11 13:34:03 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	get_greater_num(int a, int b)
// {
// 	if (a > b)
// 		return (a);
// 	else
// 		return (b);
// }

// void	draw_line(t_cub3d *game, float x0, float y0, float x1, float y1,
// 		int color)
// {
// 	t_line	lines;
// 	int		i;
//
// 	ft_memset(&lines, 0, sizeof(t_line));
// 	i = 0;
// 	lines.dx = x1 - x0;
// 	lines.dy = y1 - y0;
// 	lines.steps = get_greater_num(abs(lines.dx), abs(lines.dy));
// 	lines.x_inc = (float)lines.dx / lines.steps;
// 	lines.y_inc = (float)lines.dy / lines.steps;
// 	while (i <= lines.steps)
// 	{
// 		mlx_pixel_put(game->mlx_ptr, game->win_ptr, round(x0), round(y0),
// 			color);
// 		x0 += lines.x_inc;
// 		y0 += lines.y_inc;
// 		i++;
// 	}
// }

// void	draw_background(t_cub3d *game)
// {
// 	for (int x = S_WIDTH / 2; x < S_WIDTH; x++)
// 	{
// 		for (int y = 0; y < S_HEIGHT / 2; y++)
// 			my_mlx_pixel_put(game, x, y, 0x00FFFF);
// 		for (int y = S_HEIGHT / 2; y < S_HEIGHT; y++)
// 			my_mlx_pixel_put(game, x, y, 0x6B4F3B);
// 	}
// }


int	create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_cub3d *game, int x, int y, int color)
{
	mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, color);
}

void	draw_square(t_cub3d *game, int x, int y, int width, int height,
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

void	draw_map2d(t_cub3d *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (game->map->map_array && game->map->map_array[y])
	{
		x = 0;
		while (game->map->map_array[y][x] &&game->map->map_array[y][x] != '\n' )
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

void	draw_player2d(t_cub3d *game)
{
	draw_square(game, game->player.x - game->player.collider, game->player.y
		- game->player.collider, game->player.collider * 2,
		game->player.collider * 2, 0xc0c0c0);
}


