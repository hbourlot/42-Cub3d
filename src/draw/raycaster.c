/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:24:49 by joralves          #+#    #+#             */
/*   Updated: 2025/04/17 14:58:17 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_s_ray(t_ray *ray)
{
	ray->dist = 1000000.0;
	ray->hit_side = 0;
	ray->tex_num = 0;
	ray->wall_x = 0;
	ray->door = NULL;
}

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

	tex = get_texture(game, ray->tex_num);
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
		if (p_tex.color != 0xFF00FF)
			put_pixel_img(&game->main_img, draw->x, y, p_tex.color);
		y++;
	}
}

static void	render_door(t_cub3d *game, t_ray *ray, float ray_angle, int x)
{
	double		new_x;
	double		new_y;
	t_ray		second_ray;
	t_draw		second_draw;
	t_player	*p;

	p = &game->player;
	new_x = p->x + cos(ray_angle) * (ray->dist);
	new_y = p->y - sin(ray_angle) * (ray->dist);
	new_x /= TILE_SIZE;
	new_y /= TILE_SIZE;
	second_ray = cast_ray_door(game->map, new_x, new_y, ray_angle);
	second_draw = prepare_draw(&second_ray, p, ray_angle, x);
	draw_walls(game, &second_ray, &second_draw, ray_angle);
}

//*Render to image now
void	render(t_cub3d *game, t_player *p)
{
	t_ray	ray;
	t_draw	draw;
	int		x;
	double	ray_angle;

	clear_main_img(game);
	x = 0;
	while (x < S_WIDTH)
	{
		ray_angle = p->angle + (PI / 3) / 2 - (x * (PI / 3) / S_WIDTH);
		ray = cast_ray(game->map, p->x / TILE_SIZE, p->y / TILE_SIZE,
				ray_angle);
		draw = prepare_draw(&ray, p, ray_angle, x);
		if (ray.door && ray.door->is_open)
			render_door(game, &ray, ray_angle, x);
		draw_walls(game, &ray, &draw, ray_angle);
		x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->main_img.img, 0,
		0);
}
