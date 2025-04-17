/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:02:50 by joralves          #+#    #+#             */
/*   Updated: 2025/04/17 01:03:59 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square_img(t_img *img, int pos[2], int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			put_pixel_img(img, pos[0] + i, pos[1] + j, color);
			j++;
		}
		i++;
	}
}

void	copy_main_img(t_cub3d *game, int pos_x, int pos_y)
{
	int	x;
	int	y;
	int	*main_pixels;
	int	*map_pixels;
	int	map_line;
	int	main_px;
	int	main_line;

	main_pixels = (int *)game->main_img.addr;
	map_pixels = (int *)game->map_img.addr;
	main_line = game->main_img.size_line / 4;
	map_line = game->map_img.size_line / 4;
	y = 0;
	while (y < game->map->height * TILE_SIZE)
	{
		x = 0;
		while (x < game->map->width * TILE_SIZE)
		{
			main_px = main_pixels[(y + pos_y) * main_line + (x + pos_x)];
			map_pixels[y * map_line + x] = main_px;
			x++;
		}
		y++;
	}
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
	p->director[0] = p->x + (p->pdx) * TILE_SIZE;
	p->director[1] = p->y + (p->pdy) * TILE_SIZE;
	draw_line(game, f_pos, p->director, create_rgb(0, 255, 0, 0));
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

	copy_main_img(game, 10, 10);
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
