/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 00:59:33 by joralves          #+#    #+#             */
/*   Updated: 2025/05/15 20:25:16 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_greater_num(int a, int b)
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
