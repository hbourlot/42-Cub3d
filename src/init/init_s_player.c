#include "cube3d.h"


void	init_player(t_cube3d *game, int x, int y)
{
	t_player	*player;

	player = &game->player;
	locate_spawn_point(&game->player, game->map);
	player->x = player->x * TILE_SIZE + TILE_SIZE / 2;
	player->y = player->y * TILE_SIZE + TILE_SIZE / 2;
	player->angle = P2;
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
		player->angle += ROT_SPEED;
	if (keycode == XK_d)
		player->angle -= ROT_SPEED;
	normalize_angle(&player->angle);
	player->pdx = cos(player->angle) * SPEED;
	player->pdy = -sin(player->angle) * SPEED;
}
int	wall_collision(t_map *map, float new_x, float new_y)
{
	int			tile_x;
	int			tile_y;
	int			i;
	const float	corners[4][2] = {{new_x - TILE_SIZE / 2, new_y - TILE_SIZE / 2},
			{new_x + TILE_SIZE / 2, new_y - TILE_SIZE / 2}, {new_x - TILE_SIZE
			/ 2, new_y + TILE_SIZE / 2}, {new_x + TILE_SIZE / 2, new_y
			+ TILE_SIZE / 2}};

	i = 0;
	while (i < 4)
	{
		tile_x = (int)(corners[i][0] / TILE_SIZE);
		tile_y = (int)(corners[i][1] / TILE_SIZE);
		if (tile_x < 0 || tile_x >= map->width || tile_y < 0
			|| tile_y >= map->height || map->map_array[tile_y][tile_x] == '1')
			return (1);
		i++;
	}
	return (0);
}

void	check_collision(t_player *player, t_map *map, float new_x, float new_y)
{
	int	collision_x;
	int	collision_y;

	collision_x = wall_collision(map, new_x, player->y);
	collision_y = wall_collision(map, player->x, new_y);
	if (!collision_x && !collision_y)
	{
		player->x = new_x;
		player->y = new_y;
	}
	else if (!collision_x)
		player->x = new_x;
	else if (!collision_y)
		player->y = new_y;
}

void	move_player(t_map *map, t_player *player, int keycode)
{
	float	new_x;
	float	new_y;

	new_x = player->x;
	new_y = player->y;
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
	check_collision(player, map, new_x, new_y);
}
