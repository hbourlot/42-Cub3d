#include "cub3d.h"

// Algoritmo DDA para raycasting
t_ray	cast_ray(t_map *map, double x, double y, double angle)
{
	t_ray	ray;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;

	ray.dist = 1000000.0;
	ray.hit_side = 0;
	ray.tex_num = 0;
	ray.wall_x = 0;
	dir_x = cos(angle);
	dir_y = -sin(angle);
	map_x = (int)x;
	map_y = (int)y;
	delta_dist_x = fabs(1 / dir_x);
	delta_dist_y = fabs(1 / dir_y);
	if (dir_x < 0)
		side_dist_x = (x - map_x) * delta_dist_x;
	else
		side_dist_x = (map_x + 1.0 - x) * delta_dist_x;
	if (dir_y < 0)
		side_dist_y = (y - map_y) * delta_dist_y;
	else
		side_dist_y = (map_y + 1.0 - y) * delta_dist_y;
	if (dir_x < 0)
		step_x = -1;
	else
		step_x = 1;
	if (dir_y < 0)
		step_y = -1;
	else
		step_y = 1;
	while (map->map_world[map_y][map_x] == 0)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			ray.hit_side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			ray.hit_side = 1;
		}
		if (map_x < 0 || map_x >= map->width || map_y < 0
			|| map_y >= map->height)
			break ;
	}
	if (map_x >= 0 && map_x < map->width && map_y >= 0 && map_y < map->height)
	{
		if (ray.hit_side == 0)
			ray.dist = (map_x - x + (1 - step_x) / 2) / dir_x;
		else
			ray.dist = (map_y - y + (1 - step_y) / 2) / dir_y;
		if (ray.hit_side == 0)
		{
			if (dir_x > 0)
				ray.tex_num = 2;
			else
				ray.tex_num = 3;
			ray.wall_x = y + ray.dist * dir_y;
		}
		else
		{
			if (dir_y > 0)
				ray.tex_num = 1;
			else
				ray.tex_num = 0;
			ray.wall_x = x + ray.dist * dir_x;
		}
		ray.wall_x -= floor(ray.wall_x);
	}
	return (ray);
}

// Renderizar escena
void	render(t_cub3d *game, t_player *p)
{
	double	ray_angle;
	t_ray	ray;
	double	corrected_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;
	int		color;
	int		pixel;
	t_img	*tex;

	ft_memset(game->main_img.addr, 0x33, S_WIDTH * S_HEIGHT
		* (game->main_img.bpp / 8));
	for (int x = 0; x < S_WIDTH; x++)
	{
		ray_angle = p->angle + FOV / 2 - (x * FOV / S_WIDTH);
		ray = cast_ray(game->map, p->x / TILE_SIZE, p->y / TILE_SIZE,
				ray_angle);
		corrected_dist = ray.dist * cos(ray_angle - p->angle);
		line_height = (int)(S_HEIGHT / corrected_dist);
		draw_start = -line_height / 2 + S_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + S_HEIGHT / 2;
		if (draw_end >= S_HEIGHT)
			draw_end = S_HEIGHT - 1;
		tex = get_texture2(game, &ray);
		tex_x = (int)(ray.wall_x * tex->width);
		if ((!ray.hit_side && cos(ray_angle) > 0) || (ray.hit_side
				&& sin(ray_angle) < 0))
			tex_x = tex->width - tex_x - 1;
		step = 1.0 * tex->height / line_height;
		tex_pos = (draw_start - S_HEIGHT / 2 + line_height / 2) * step;
		for (int y = draw_start; y < draw_end; y++)
		{
			tex_y = (int)tex_pos & (tex->height - 1);
			tex_pos += step;
			color = get_texture_color(tex, tex_x, tex_y);
			pixel = (y * game->main_img.size_line) + (x * 4);
			*(int *)(game->main_img.addr + pixel) = color;
		}
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->main_img.img, 0,
		0);
}
