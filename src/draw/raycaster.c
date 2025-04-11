/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:24:49 by joralves          #+#    #+#             */
/*   Updated: 2025/04/11 12:06:36 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_draw	prepare_draw(t_ray *ray, t_player *p, double ray_angle, int x)
{
	t_draw	draw;

	draw.corrected_dist = ray->dist * cos(ray_angle - p->angle);
	draw.line_height = (int)(S_HEIGHT / draw.corrected_dist);
	draw.start = -draw.line_height / 2 + S_HEIGHT / 2;
	if (draw.start < 0)
		draw.start = 0;
	draw.end = draw.line_height / 2 + S_HEIGHT / 2;
	if (draw.end >= S_HEIGHT)
		draw.end = S_HEIGHT - 1;
	draw.x = x;
	return (draw);
}

static void	draw_walls(t_cub3d *game, t_ray *ray, t_draw *draw,
		double ray_angle)
{
	t_img	*tex;
	t_tex	p_tex;
	int		y;
	double	step;
	int		pixel;

	tex = get_texture(game, ray);
	p_tex.tex_x = (int)(ray->wall_x * tex->width);
	if ((!ray->hit_side && cos(ray_angle) > 0) || (ray->hit_side
			&& sin(ray_angle) < 0))
		p_tex.tex_x = tex->width - p_tex.tex_x - 1;
	step = 1.0 * tex->height / draw->line_height;
	p_tex.tex_pos = (draw->start - S_HEIGHT / 2 + draw->line_height / 2) * step;
	y = draw->start;
	while (y < draw->end)
	{
		p_tex.tex_y = (int)p_tex.tex_pos % (tex->height);
		p_tex.tex_pos += step;
		p_tex.color = get_texture_color(tex, p_tex.tex_x, p_tex.tex_y);
		pixel = (y * game->main_img.size_line) + (draw->x * 4);
		*(int *)(game->main_img.addr + pixel) = p_tex.color;
		y++;
	}
}

// Renderizar escena
void	render(t_cub3d *game, t_player *p)
{
	t_ray	ray;
	t_draw	draw;
	int		x;
	double	ray_angle;

	ft_memset(game->main_img.addr, 0x33, S_WIDTH * S_HEIGHT
		* (game->main_img.bpp / 8));
	x = 0;
	while (x < S_WIDTH)
	{
		ray_angle = p->angle + FOV / 2 - (x * FOV / S_WIDTH);
		ray = cast_ray(game->map, p->x / TILE_SIZE, p->y / TILE_SIZE,
				ray_angle);
		draw = prepare_draw(&ray, p, ray_angle, x);
		draw_walls(game, &ray, &draw, ray_angle);
		x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->main_img.img, 0,
		0);
}
