/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:06:21 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/14 01:32:55 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	if (x >= img->width || y >= img->height)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_greater_num(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	draw_line(t_cub3d *game, float initial[2], float final[2], int color)
{
	t_line	lines;
	int		i;

	ft_memset(&lines, 0, sizeof(t_line));
	i = 0;
	lines.dx = final[0] - initial[0];
	lines.dy = final[1] - initial[1];
	lines.steps = get_greater_num(abs(lines.dx), abs(lines.dy));
	lines.x_inc = (float)lines.dx / lines.steps;
	lines.y_inc = (float)lines.dy / lines.steps;
	while (i <= lines.steps)
	{
		if (initial[0] < game->map->width * TILE_SIZE
			&& initial[1] < game->map->height * TILE_SIZE)
			put_pixel_img(&game->map_img, round(initial[0]), round(initial[1]),
				color);
		initial[0] += lines.x_inc;
		initial[1] += lines.y_inc;
		i++;
	}
}

int	create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
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

void	copy_main_img(t_cub3d *game)
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	*main_pixels;
	int	*map_pixels;
	int	map_line;
	int	offset_x;
	int	offset_y;
	int	main_px;

	width = game->map->width * TILE_SIZE;
	height = game->map->height * TILE_SIZE;
	main_pixels = (int *)game->main_img.addr;
	map_pixels = (int *)game->map_img.addr;
	int main_line = game->main_img.size_line / 4; // 4 bytes per pixel
	map_line = game->map_img.size_line / 4;
	// Posición en pantalla donde va el minimapa
	offset_x = 10;
	offset_y = 10;
	for (y = 0; y < height; y++)
	{
		for (x = 0; x < width; x++)
		{
			main_px = main_pixels[(y + offset_y) * main_line + (x + offset_x)];
			map_pixels[y * map_line + x] = main_px;
		}
	}
}

static int	set_color_map(char c)
{
	int	color;

	if (c == '1')
		color = 0xFFFFFF;
	else if (c == '2')
		color = 0x8B4513;
	else if (c == '0' || ft_strchr(VPL, c))
		color = 0x000000;
	else
		color = -1;
	return (color);
}

void	draw_map2d(t_cub3d *game, t_map *map)
{
	int	x;
	int	y;
	int	pos[2];
	int	color;

	copy_main_img(game);
	y = 0;
	while (map->map_array && map->map_array[y])
	{
		x = -1;
		while (map->map_array[y][++x] && map->map_array[y][x] != '\n')
		{
			color = set_color_map(map->map_array[y][x]);
			if (color == -1)
				continue ;
			pos[0] = x * TILE_SIZE;
			pos[1] = y * TILE_SIZE;
			draw_square_img(&game->map_img, pos, TILE_SIZE, color);
		}
		y++;
	}
	draw_player2d(game, &game->player);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->map_img.img, 10,
		10);
}

void	draw_player2d(t_cub3d *game, t_player *p)
{
	int		pos[2];
	float	f_pos[2];

	pos[0] = p->x - p->collider;
	pos[1] = p->y - p->collider;
	draw_square_img(&game->map_img, pos, p->collider * 2, 0xc0c0c0);
	f_pos[0] = p->x;
	f_pos[1] = p->y;
	p->director[0] = p->x + p->pdx * TILE_SIZE;
	p->director[1] = p->y + p->pdy * TILE_SIZE;
	draw_line(game, f_pos, p->director, create_rgb(0, 255, 0, 0));
}

void	clear_main_img(t_cub3d *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < S_WIDTH)
	{
		y = 0;
		while (y < S_HEIGHT)
		{
			if (y < S_HEIGHT / 2)
				put_pixel_img(&game->main_img, x, y, 0x4B4B4B);
			if (y > S_HEIGHT / 2 && y < S_HEIGHT)
				put_pixel_img(&game->main_img, x, y, 0x2F2F2F);
			y++;
		}
		x++;
	}
}

// void	my_mlx_pixel_put(t_cub3d *game, int x, int y, int color)
// {
// 	mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, color);
// }