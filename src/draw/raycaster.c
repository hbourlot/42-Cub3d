

#include "cub3d.h"

void	render_walls(t_cub3d *game, t_raycast *ray, int color)
{
	int	x;
	int	y;

	x = ray->x_start;
	while (x < ray->x_end)
	{
		y = 0;
		while (y < ray->wall_height)
		{
			ray->screen_y = ray->wall_start + y;
			if (ray->screen_y >= 0 && ray->screen_y < SCREEN_HEIGHT)
				my_mlx_pixel_put(game, x, ray->screen_y, color);
			y++;
		}
		x++;
	}
}

void	cast_render_raycast(t_cub3d *game)
{
	t_raycast	ray;
	int			i;
	int			color;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		ray.alpha = FOV / 2 - FOV / SCREEN_WIDTH * i;
		ray.ray_angle = game->player.angle + ray.alpha;
		dda(game, &ray, game->player.x, game->player.y);
		ray.perp_dist = ray.dist * cos(ray.alpha);
		ray.wall_height = (int)(WALL_SIZE * SCREEN_HEIGHT / ray.perp_dist);
		ray.wall_start = SCREEN_HEIGHT / 2 - ray.wall_height / 2;
		ray.x_start = i;
		ray.x_end = i + 1;
		if (ray.dda.hitside == 1)
			color = create_rgb(0, 255, 0, 0);
		else
			color = create_rgb(0, 0, 0, 255);
		render_walls(game, &ray, color);
		i++;
	}
}
