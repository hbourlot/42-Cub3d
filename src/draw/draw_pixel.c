/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:06:21 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/12 13:38:45 by joralves         ###   ########.fr       */
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

void	put_pixel_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	// if (x < 0 || y < 0 || x >= img->width || y >= img->height)
	// 	return ;
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_square_img(t_img *img, int pos[2], int size, int color)
{
	int	i;
	int	j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			put_pixel_img(img, pos[0] + i, pos[1] + j, color);
		}
	}
}

void	my_mlx_pixel_put(t_cub3d *game, int x, int y, int color)
{
	mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, color);
}

// void	draw_square(t_cub3d *game, int pos[2], int size, int color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			mlx_pixel_put(game->mlx_ptr, game->win_ptr, pos[0] + i, pos[1] + j,
// 				color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	draw_map2d(t_cub3d *game)
// {
// 	int	x;
// 	int	y;
// 	int	pos[2];
// 	int	color;

// 	ft_memset(game->map_img.addr, 0x90, ((game->map->width - 1) * TILE_SIZE)
// 		* (game->map->height * TILE_SIZE) * (game->map_img.bpp / 8));
// 	y = 0;
// 	while (game->map->map_world && game->map->map_world[y])
// 	{
// 		x = 0;
// 		// printf("%s", game->map->map_world[y]);
// 		while (game->map->map_world[y][x])
// 		{
// 			printf("%c", game->map->map_array[y][x]);
// 			if (game->map->map_array[y][x] == '1')
// 				color = 0xFFFFFF;
// 			else
// 				color = 0x000000;
// 			pos[0] = x * TILE_SIZE;
// 			pos[1] = y * TILE_SIZE;
// 			draw_square_img(&game->map_img, pos, TILE_SIZE, color);
// 			x++;
// 		}
// 		printf("\n");
// 		y++;
// 	}
// 	draw_player2d(game);
// 	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->map_img.img, 10,
// 		10);
// }

void	draw_map2d(t_cub3d *game)
{
	int	x;
	int	y;
	int	pos[2];
	int	color;

	ft_memset(game->map_img.addr, 0x90, ((game->map->width) * TILE_SIZE)
		* (game->map->height * TILE_SIZE) * (game->map_img.bpp / 8));
	y = 0;
	while (game->map->map_array && game->map->map_array[y])
	{
		x = 0;
		while (game->map->map_array[y][x] && game->map->map_array[y][x] != '\n')
		{
			if (game->map->map_array[y][x] == '1')
				color = 0xFFFFFF;
			else
				color = 0x000000;
			pos[0] = x * TILE_SIZE;
			pos[1] = y * TILE_SIZE;
			draw_square_img(&game->map_img, pos, TILE_SIZE, color);
			x++;
		}
		y++;
	}
	draw_player2d(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->map_img.img, 10,
		10);
}

void	draw_player2d(t_cub3d *game)
{
	int	pos[2];

	pos[0] = game->player.x - game->player.collider;
	pos[1] = game->player.y - game->player.collider;
	draw_square_img(&game->map_img, pos, game->player.collider * 2, 0xc0c0c0);
}

void	clear_main_img(t_cub3d *game)
{
	ft_memset(game->main_img.addr, 0x33, S_WIDTH * S_HEIGHT
		* (game->main_img.bpp / 8));
	// ft_memset(game->main_img.addr + (S_WIDTH * S_HEIGHT / 2), 0x83, S_WIDTH
	// 	* S_HEIGHT / 2 * (game->main_img.bpp / 8));
}
