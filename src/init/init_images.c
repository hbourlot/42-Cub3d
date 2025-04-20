/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:14:00 by joralves          #+#    #+#             */
/*   Updated: 2025/04/14 01:39:04 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_main_img(t_cub3d *game)
{
	game->main_img.img = mlx_new_image(game->mlx_ptr, S_WIDTH, S_HEIGHT);
	if (!game->main_img.img)
		return (ft_printf_fd(2, ME_NI), -1);
	game->main_img.addr = mlx_get_data_addr(game->main_img.img,
			&game->main_img.bpp, &game->main_img.size_line,
			&game->main_img.endian);
	if (!game->main_img.addr)
		return (ft_printf_fd(2, ME_NI), -1);
	game->main_img.width = S_WIDTH;
	game->main_img.height = S_HEIGHT;
	return (0);
}

static int	init_map_img(t_cub3d *game)
{
	t_map	*map;

	map = game->map;
	game->map_img.img = mlx_new_image(game->mlx_ptr, map->width * TILE_SIZE,
			map->height * TILE_SIZE);
	if (!game->map_img.img)
		return (ft_printf_fd(2, ME_NI), -1);
	game->map_img.addr = mlx_get_data_addr(game->map_img.img,
			&game->map_img.bpp, &game->map_img.size_line,
			&game->map_img.endian);
	if (!game->map_img.addr)
		return (ft_printf_fd(2, ME_NI), -1);
	game->map_img.width = map->width * TILE_SIZE;
	game->map_img.height = map->height * TILE_SIZE;
	return (0);
}

int	init_images(t_cub3d *game)
{
	if (init_main_img(game) == -1)
		return (-1);
	if (init_map_img(game) == -1)
		return (-1);
	return (0);
}
