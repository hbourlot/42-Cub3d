#include "cube3d.h"

void	init_player(t_cube3d *game)
{
	t_player	*player;

	player = &game->player;
	player->x = 1;
	player->y = 1;
	player->angle = P3;  
	player->pdx = cos(player->angle) * 5;
	player->pdy = sin(player->angle) * 5;
}

void	move_player(t_cube3d *game, float pa, float dx, float dy)
{
	float	new_x;
	float	new_y;

	if (pa)
	{
		game->player.angle += pa;
		// printf("Aqui %f\n", game->player.angle);
		if (game->player.angle < 0)
			game->player.angle += 2 * PI;
		else if (game->player.angle > 2 * PI)
			game->player.angle -= 2 * PI;
	}
	game->player.pdx = cos(game->player.angle) * SPEED;
	game->player.pdy = -sin(game->player.angle) * SPEED;
	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	// printf("new_x %f new_y %f\n", new_x, new_y);
	if ((new_x > 0 && new_x < game->map->width) && (new_y > 0
			&& new_y < game->map->height)
		&& game->map->map_array[(int)new_y][(int)new_x] != '1')
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
	draw_map2d(game);
	// draw_rays2d(game, &game->player, game->map);
}
