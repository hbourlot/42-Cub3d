

#include "cub3d.h"

void	render_walls(t_cub3d *game, t_raycast *ray, t_img *tex)
{
	int		x;
	int		y;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
	int		color;

	tex_x = (int)(ray->wall_hit * tex->width);
	if ((ray->dda.hitside == 0 && ray->dda.dir_x < 0) || (ray->dda.hitside == 1
			&& ray->dda.dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	step = (double)tex->height / ray->wall_height;
	tex_pos = 0;
	if (ray->wall_start < 0)
		tex_pos = -ray->wall_start * step;
	x = ray->x_start;
	y = 0;
	while (y < ray->wall_height)
	{
		ray->screen_y = ray->wall_start + y;
		if (ray->screen_y >= 0 && ray->screen_y < SCREEN_HEIGHT)
		{
			tex_y = (int)tex_pos % tex->height;
			color = get_texture_color(tex, tex_x, tex_y);
			my_mlx_pixel_put(game, x, ray->screen_y, color);
		}
		tex_pos += step;
		y++;
	}
}

void	cast_render_raycast(t_cub3d *game)
{
	int			i;
	t_img		*tex;
	t_raycast	ray;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		ray.alpha = FOV / 2 - FOV / SCREEN_WIDTH * i;
		ray.ray_angle = game->player.angle + ray.alpha;
		dda(game, &ray, game->player.x, game->player.y);
		ray.perp_dist = ray.dist * cos(ray.alpha);
		ray.wall_height = (int)(SCREEN_HEIGHT / ray.perp_dist);
		ray.wall_start = SCREEN_HEIGHT / 2 - ray.wall_height / 2;
		ray.x_start = i;
		tex = get_texture(game, &ray);
		render_walls(game, &ray, tex);
		i++;
	}
}
