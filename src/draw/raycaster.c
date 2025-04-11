#include "cub3d.h"

void	init_s_ray(t_ray *ray)
{
	ray->dist = 1000000.0;
	ray->hit_side = 0;
	ray->tex_num = 0;
	ray->wall_x = 0;
}
void	init_s_dda(t_dda *dda, double x, double y, double angle)
{
	dda->dir_x = cos(angle);
	dda->dir_y = -sin(angle);
	dda->map_x = (int)x;
	dda->map_y = (int)y;
	dda->delta_dist_x = fabs(1.0 / dda->dir_x);
	dda->delta_dist_y = fabs(1.0 / dda->dir_y);
	if (dda->dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - x) * dda->delta_dist_x;
	}
	if (dda->dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - y) * dda->delta_dist_y;
	}
}

void	perform_dda_loop(t_map *map, t_ray *ray, t_dda *dda)
{
	while (map->map_world[dda->map_y][dda->map_x] == 0)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			ray->hit_side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			ray->hit_side = 1;
		}
		if (dda->map_x < 0 || dda->map_y < 0 || dda->map_x >= map->width
			|| dda->map_y >= map->height)
			break ;
	}
}

void	fill_s_ray(t_map *map, t_ray *ray, t_dda *dda, double x, double y)
{
	ray->wall_hit = map->map_world[dda->map_y][dda->map_x];
	if (dda->map_x >= 0 && dda->map_x < map->width && dda->map_y >= 0
		&& dda->map_y < map->height)
	{
		if (ray->hit_side == 0)
		{
			ray->dist = (dda->map_x - x + (1 - dda->step_x) / 2.0) / dda->dir_x;
			ray->wall_x = y + ray->dist * dda->dir_y;
		}
		else
		{
			ray->dist = (dda->map_y - y + (1 - dda->step_y) / 2.0) / dda->dir_y;
			ray->wall_x = x + ray->dist * dda->dir_x;
		}
		set_texture(ray, dda);
		ray->wall_x -= floor(ray->wall_x);
	}
}

t_ray	cast_ray(t_map *map, double x, double y, double angle)
{
	t_ray	ray;
	t_dda	dda;

	// init_s_ray(&ray);
	init_s_dda(&dda, x, y, angle);
	perform_dda_loop(map, &ray, &dda);
	fill_s_ray(map, &ray, &dda, x, y);
	return (ray);
}

// Renderizar escena
void	render(t_cub3d *game, t_player *p)
{
	t_ray	ray;
	t_img	*tex;
	t_draw draw;
	int		x;
	int		y;
	double	ray_angle;
	int		color;
	double	step;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	int		pixel;

	ft_memset(game->main_img.addr, 0x33, S_WIDTH * S_HEIGHT
		* (game->main_img.bpp / 8));
	x = 0;
	while (x < S_WIDTH)
	{
		ray_angle = p->angle + FOV / 2 - (x * FOV / S_WIDTH);
		ray = cast_ray(game->map, p->x / TILE_SIZE, p->y / TILE_SIZE,
				ray_angle);
		draw.corrected_dist = ray.dist * cos(ray_angle - p->angle);
		draw.line_height = (int)(S_HEIGHT / draw.corrected_dist);
		draw.draw_start = -draw.line_height / 2 + S_HEIGHT / 2;
		if (draw.draw_start < 0)
			draw.draw_start = 0;
		draw.draw_end = draw.line_height / 2 + S_HEIGHT / 2;
		if (draw.draw_end >= S_HEIGHT)
			draw.draw_end = S_HEIGHT - 1;
		tex = get_texture2(game, &ray);
		tex_x = (int)(ray.wall_x * tex->width);
		if ((!ray.hit_side && cos(ray_angle) > 0) || (ray.hit_side
				&& sin(ray_angle) < 0))
			tex_x = tex->width - tex_x - 1;
		step = 1.0 * tex->height / draw.line_height;
		tex_pos = (draw.draw_start - S_HEIGHT / 2 + draw.line_height / 2) * step;
		y = draw.draw_start;
		while (y < draw.draw_end)
		{
			tex_y = (int)tex_pos & (tex->height - 1);
			tex_pos += step;
			color = get_texture_color(tex, tex_x, tex_y);
			pixel = (y * game->main_img.size_line) + (x * 4);
			*(int *)(game->main_img.addr + pixel) = color;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->main_img.img, 0,
		0);
}
