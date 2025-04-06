

#include "cub3d.h"

void	render_walls(t_cub3d *game, t_raycast *raycast, int color)
{
	int	x;
	int	y;

	x = raycast->x_start;
	while (x < raycast->x_end)
	{
		y = 0;
		while (y < raycast->wall_height)
		{
			raycast->screen_y = raycast->wall_start + y;
			if (raycast->screen_y >= 0 && raycast->screen_y < SCREEN_HEIGHT)
				my_mlx_pixel_put(game, x, raycast->screen_y, color);
			y++;
		}
		x++;
	}
}

void	cast_render_raycast(t_cub3d *game)
{
	t_raycast raycast;
	int i;
	int color;

	i = 0;
	raycast.column_width = (int)((float)SCREEN_WIDTH / (float)SCREEN_WIDTH);
	if (raycast.column_width < 1)
		raycast.column_width = 1;
	while (i < SCREEN_WIDTH)
	{
		raycast.alpha = FOV / 2 - FOV / SCREEN_WIDTH * i;
		raycast.ray_angle = game->player.angle + raycast.alpha;
		normalize_angle(&raycast.ray_angle);
		dda(game, &raycast, game->player.x, game->player.y);
		raycast.perp_dist = raycast.dist * cos(raycast.alpha);
		raycast.wall_height = (int)(WALL_SIZE * SCREEN_HEIGHT
				/ raycast.perp_dist);
		raycast.wall_start = SCREEN_HEIGHT / 2 - raycast.wall_height / 2;
		raycast.x_start = i * raycast.column_width;
		raycast.x_end = (i + 1) * raycast.column_width;
		if (raycast.x_end > SCREEN_WIDTH)
			raycast.x_end = SCREEN_WIDTH;
		if (raycast.dda.hitside == 1)
			color = create_rgb(0, 255, 0, 0);
		else
			color = create_rgb(0, 0, 0, 255);
		render_walls(game, &raycast, color);
		i++;
	}
}