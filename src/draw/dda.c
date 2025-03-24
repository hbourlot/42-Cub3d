#include "cube3d.h"

float	DDA(t_cube3d *game, float x0, float y0, float angle)
{
	char	**grid;
	int		gridX;
	int		gridY;
	float	dirX;
	float	dirY;
	float	sx_norm;
	float	sy_norm;
	float	sx;
	float	sy;
	float	initialX;
	float	initialY;
	int		stepX;
	int		stepY;
	float	acum_x;
	float	acum_y;
	float	res;
	int		counterX;
	int		counterY;

	normalize_angle(&angle);
	grid = game->map->map_array;
	gridX = round(x0 / TILE_SIZE);
	gridY = round(y0 / TILE_SIZE);
	dirX = cos(angle);
	dirY = -sin(angle);
	printf(" dirY %f\n", dirY);
	if (dirX == 0)
		dirX = EPSILON;
	if (dirY == 0)
		dirY = EPSILON;
	sx_norm = sqrt(1 + (dirY / dirX) * (dirY / dirX));
	sy_norm = sqrt(1 + (dirX / dirY) * (dirX / dirY));
	sx = TILE_SIZE * sx_norm;
	sy = TILE_SIZE * sy_norm;
	initialX = 0;
	initialY = 0;
	stepX = 0;
	stepY = 0;
	if (dirX < 0)
	{
		stepX = -1;
		initialX = x0 - gridX * TILE_SIZE;
	}
	else
	{
		stepX = 1;
		initialX = (gridX + 1) * TILE_SIZE - x0;
	}
	if (dirY < 0)
	{
		stepY = -1;
		initialY = y0 - gridY * TILE_SIZE;
	}
	else
	{
		stepY = 1;
		initialY = (gridY + 1) * TILE_SIZE - y0;
	}
	acum_x = initialX * sx_norm;
	acum_y = initialY * sy_norm;
	draw_line(game, x0, y0, x0 + initialX * stepX, y0, 0xFF0000);
	draw_line(game, x0, y0, x0, y0 + initialY * stepY, 0x00FF00);
	counterX = 0;
	counterY = 0;
	while (grid[gridY][gridX] == '0')
	{
		if (acum_x <= acum_y)
		{
			gridX += stepX;
			res = acum_x;
			acum_x += sx;
			counterX++;
		}
		else
		{
			gridY += stepY;
			res = acum_y;
			acum_y = acum_y + sy;
			counterY++;
		}
		if (gridX < 0 || gridY < 0 || gridX >= game->map->width
			|| gridY >= game->map->height)
			break ;
	}
	draw_square(game, gridX * TILE_SIZE, gridY * TILE_SIZE, TILE_SIZE,
		TILE_SIZE, 0xc0c0c0);
	draw_line(game, x0, y0, x0 + initialX * stepX + TILE_SIZE * (counterX - 1)
		* stepX, y0, 0x80CC80);
	draw_line(game, x0, y0, x0, y0 + initialY * stepY + TILE_SIZE * (counterY
			- 1) * stepY, 0xCC8080);
	draw_line(game, x0 + TILE_SIZE / 2, y0 + TILE_SIZE / 2, x0 + initialX
		* stepX + TILE_SIZE * (counterX - 1) * stepX, y0 + initialY * stepY
		+ TILE_SIZE * (counterY - 1) * stepY, 0x8080CC);
	printf("%f\n", res);
	return (res);
}

void	drawRaycast(t_cube3d *game)
{
	int		i;
	float	alpha;
	float	ray_angle;
	float	dist;
	int		wallH;
	float	midLine;
	int		color;

	i = 0;
	while (i < CANT_RAYS - 1)
	{
		alpha = FOV / 2 - ANGLE_PER_RAY * i;
		ray_angle = game->player.angle + alpha;
		normalize_angle(&ray_angle);
		dist = DDA(game, game->player.x, game->player.y, ray_angle);
		// Evita divisiones por cero o distancias negativas
		if (dist <= 0)
			dist = 1;
		wallH = WALL_SIZE * GAME_HEIGHT / dist;
		midLine = GAME_HEIGHT / 2 - wallH / 2;
		color = 0xFFFFFF;
		for (int y = 0; y < wallH; y++)
		{
			if (midLine + y >= 0 && midLine + y < GAME_HEIGHT)
			{
				my_mlx_pixel_put(game, i * RENDER_LINE_WIDTH, midLine + y,
					color);
			}
		}
		i++;
	}
}
