/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:50:04 by joralves          #+#    #+#             */
/*   Updated: 2025/04/14 01:39:57 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture(t_ray *ray, t_dda *dda)
{
	if (ray->wall_hit == 1)
	{
		if (ray->hit_side == 0)
		{
			if (dda->dir_x > 0)
				ray->tex_num = 2;
			else
				ray->tex_num = 3;
		}
		else
		{
			if (dda->dir_y > 0)
				ray->tex_num = 0;
			else
				ray->tex_num = 1;
		}
	}
	if (ray->wall_hit == 2)
		ray->tex_num = 4;
}

t_img	*get_texture(t_cub3d *game, t_ray *ray)
{
	t_img	*tex;

	if (ray->tex_num == 0)
		tex = game->sprites->so;
	if (ray->tex_num == 1)
		tex = game->sprites->no;
	if (ray->tex_num == 2)
		tex = game->sprites->ea;
	if (ray->tex_num == 3)
		tex = game->sprites->we;
	if (ray->tex_num == 4)
		tex = game->sprites->door;
	return (tex);
}

int	get_texture_color(t_img *tex, int x, int y)
{
	int	color;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0x000000);
	color = *(int *)(tex->addr + (y * tex->size_line) + (x * (tex->bpp / 8)));
	return (color);
}
