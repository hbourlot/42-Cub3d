/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:14:00 by joralves          #+#    #+#             */
/*   Updated: 2025/04/12 19:14:30 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_images(t_cub3d *game)
{
	t_map	*map;
	print_map_2(game);
	map = game->map;
	game->main_img.img = mlx_new_image(game->mlx_ptr, S_WIDTH, S_HEIGHT);
	if (!game->main_img.img)
		return (ft_printf_fd(2, ME_NI), -1);
	game->main_img.addr = mlx_get_data_addr(game->main_img.img,
			&game->main_img.bpp, &game->main_img.size_line,
			&game->main_img.endian);
	if (!game->main_img.addr)
		return (ft_printf_fd(2, ME_NI), -1);
	game->map_img.img = mlx_new_image(game->mlx_ptr, (map->width) * TILE_SIZE,
			map->height * TILE_SIZE);
	if (!game->map_img.img)
		return (ft_printf_fd(2, ME_NI), -1);
	game->map_img.addr = mlx_get_data_addr(game->map_img.img,
			&game->map_img.bpp, &game->map_img.size_line,
			&game->map_img.endian);
	if (!game->map_img.addr)
		return (ft_printf_fd(2, ME_NI), -1);
	// printf("map_img_width %d map_img_height %d \n", map->width * TILE_SIZE,map->height * TILE_SIZE);
	return (0);
}
