/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:01:03 by joralves          #+#    #+#             */
/*   Updated: 2025/05/15 18:42:28 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_sprite(t_cub3d *game, t_img **sprite, char *path)
{
	t_img	*new;

	new = malloc(sizeof(t_img));
	if (!new)
		return (printf("Error: Malloc failed for %s texture\n", path), -1);
	new->img = mlx_xpm_file_to_image(game->mlx_ptr, path, &new->width,
			&new->height);
	if (!new->img)
	{
		free(new);
		return (printf("Error: Failed to load XPM file %s\n", path), -1);
	}
	new->addr = mlx_get_data_addr(new->img, &new->bpp, &new->size_line,
			&new->endian);
	if (!new->addr)
	{
		mlx_destroy_image(game->mlx_ptr, new->img);
		free(new);
		return (printf("Error: Failed to get texture data address\n"), -1);
	}
	*sprite = new;
	return (SUCCESS);
}

void	init_s_sprite(t_cub3d *game)
{
	if (init_sprite(game, &game->sprites->no, (char *)game->map->no))
		return (ft_printf_fd(2, ME_MALLOC), free_game(1));
	if (init_sprite(game, &game->sprites->so, (char *)game->map->so))
		return (ft_printf_fd(2, ME_MALLOC), free_game(1));
	if (init_sprite(game, &game->sprites->ea, (char *)game->map->ea))
		return (ft_printf_fd(2, ME_MALLOC), free_game(1));
	if (init_sprite(game, &game->sprites->we, (char *)game->map->we))
		return (ft_printf_fd(2, ME_MALLOC), free_game(1));
	if (init_sprite(game, &game->sprites->door_close,
			"texture/door/door_close.xpm"))
		return (ft_printf_fd(2, ME_MALLOC), free_game(1));
	if (init_sprite(game, &game->sprites->door_open,
			"texture/door/door_open.xpm"))
		return (ft_printf_fd(2, ME_MALLOC), free_game(1));
}
