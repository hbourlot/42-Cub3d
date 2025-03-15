#include "cube3d.h"

void	init_player(t_cube3d *game)
{
	t_player	*player;

	player = &game->player;
	player->x = 1;
	player->y = 1;
	player->angle = 0;
	player->pdx = cos(player->angle) * SPEED;
	player->pdy = sin(player->angle) * SPEED;
}

int	move_player_aux(t_cube3d *game, int new_x, int new_y)
{
	int	result;

	if ((new_x > 0 && new_x < game->map->width - 1) && (new_y > 0
			&& new_y < game->map->height)
		&& game->map->map_array[new_y][new_x] != '1')
		result = 1;
	else
		result = 0;
	return (result);
}

void	move_player(t_cube3d *game, float pa, float dx, float dy)
{
	float	new_x;
	float	new_y;

	if (pa)
	{
		game->player.angle += pa;
		if (game->player.angle < 0)
			game->player.angle += 2 * PI;
		else if (game->player.angle > 2 * PI)
			game->player.angle -= 2 * PI;
	}
	game->player.pdx = cos(game->player.angle) * SPEED;
	game->player.pdy = -sin(game->player.angle) * SPEED;
	new_x = game->player.x + dx;
	new_y = game->player.y + dy;
	if (move_player_aux(game, (int)new_x, (int)new_y))
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
	draw_map2d(game);
}
