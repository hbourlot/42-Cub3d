/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_main_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:23:34 by hbourlot          #+#    #+#             */
/*   Updated: 2025/05/15 20:24:03 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
				put_pixel_img(&game->main_img, x, y, game->sprites->ceiling);
			if (y > S_HEIGHT / 2 && y < S_HEIGHT)
				put_pixel_img(&game->main_img, x, y, game->sprites->floor);
			y++;
		}
		x++;
	}
}
