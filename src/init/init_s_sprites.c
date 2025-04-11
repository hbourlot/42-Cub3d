/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 01:01:03 by joralves          #+#    #+#             */
/*   Updated: 2025/04/11 11:59:12 by joralves         ###   ########.fr       */
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

int	init_s_sprite(t_cub3d *game)
{
	if (init_sprite(game, &game->sprites->no, (char *)game->map->no))
		return (ft_printf_fd(2, ME_MALLOC), -1);
	if (init_sprite(game, &game->sprites->so, (char *)game->map->so))
		return (ft_printf_fd(2, ME_MALLOC), -1);
	if (init_sprite(game, &game->sprites->ea, (char *)game->map->ea))
		return (ft_printf_fd(2, ME_MALLOC), -1);
	if (init_sprite(game, &game->sprites->we, (char *)game->map->we))
		return (ft_printf_fd(2, ME_MALLOC), -1);
	return (SUCCESS);
}
