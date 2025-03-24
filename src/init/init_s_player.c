#include "cube3d.h"

void	init_player(t_cube3d *game, int x, int y)
{
	t_player	*player;

	player = &game->player;
	player->x = x * TILE_SIZE;
	player->y = y * TILE_SIZE;
	player->angle = 0;
	player->pdx = cos(player->angle) * SPEED;
	player->pdy = -sin(player->angle) * SPEED;
}

void	normalize_angle(float *angle)
{
	if (*angle < 0)
		*angle += 2 * PI;
	if (*angle > 2 * PI)
		*angle -= 2 * PI;
}

void	rotate_player(t_player *player, int keycode)
{
	if (keycode == XK_a)
		player->angle -= ROT_SPEED;
	if (keycode == XK_d)
		player->angle += ROT_SPEED;
	normalize_angle(&player->angle);
	player->pdx = cos(player->angle) * SPEED;
	player->pdy = -sin(player->angle) * SPEED;
}

void	move_player(t_map *map, t_player *player, int keycode)
{
	float new_x = player->x;
	float new_y = player->y;

	if (keycode == XK_w)
	{
		new_x += player->pdx;
		new_y += player->pdy;
	}
	else if (keycode == XK_s)
	{
		new_x -= player->pdx;
		new_y -= player->pdy;
	}

	int tile_x = (int)(new_x / TILE_SIZE);
	int tile_y = (int)(new_y / TILE_SIZE);

	if (tile_x > 0 && tile_x < map->width && tile_y > 0 && tile_y < map->height
		&& map->map_array[tile_y][tile_x] != '1')
	{
		player->x = new_x;
		player->y = new_y;
	}
}