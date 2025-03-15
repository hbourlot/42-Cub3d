
#include "lib/minilibx-linux/mlx.h"
#include <math.h>
#include <stdlib.h>

#define mapX 8
#define mapY 8
#define mapS 64
#define WIDTH 1024
#define HEIGHT 510
#define FOV 60

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	float	px;
	float	py;
	float	pa;
	float	pdx;
	float	pdy;
}			t_data;

int			map[] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1,
		0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1,
		0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

// Funciones auxiliares
float	degToRad(float a)
{
	return (a * M_PI / 180.0f);
}
float	fixAng(float a)
{
	a = fmod(a, 360);
	return (a < 0 ? a + 360 : a);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(unsigned int *)(data->addr + (y * data->line_length + x
					* (data->bits_per_pixel / 8))) = color;
}

void	draw_vertical_line(t_data *img, int x, int y1, int y2, int color)
{
	if (y1 < 0)
		y1 = 0;
	if (y2 >= HEIGHT)
		y2 = HEIGHT - 1;
	for (int y = y1; y <= y2; y++)
		my_mlx_pixel_put(img, x, y, color);
}
void	draw_line(t_data *data, int x0, int y0, int x1, int y1, int color)
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;

	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = -abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = dx + dy, e2;
	while (1)
	{
		my_mlx_pixel_put(data, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

// Dibujar mapa
void	drawMap2D(t_data *data)
{
	int x, y, mx, my;
	for (y = 0; y < mapY; y++)
	{
		for (x = 0; x < mapX; x++)
		{
			mx = x * mapS;
			my = y * mapS;
			for (int i = mx; i < mx + mapS; i++)
				for (int j = my; j < my + mapS; j++)
					my_mlx_pixel_put(data, i, j, map[y * mapX + x] ? 0xFFFFFF : 0x000000);
		}
	}
}

// Dibujar jugador
void	drawPlayer(t_data *data)
{
	for (int i = -4; i <= 4; i++)
		for (int j = -4; j <= 4; j++)
			my_mlx_pixel_put(data, data->px + i, data->py + j, 0xFFFF00);
}

// Raycasting
void	drawRays2D(t_data *data, float vx, float vy, float hx, float hy,
		float disV, float disH)
{
	float	dis;
	int		color;
	float	endX;
	float	endY;

	dis = fminf(disV, disH);
	color = (dis == disV) ? 0x00FF00 : 0x009900;
	endX = (dis == disV) ? vx : hx;
	endY = (dis == disV) ? vy : hy;
	draw_line(data, data->px, data->py, endX, endY, color);
}

void	drawRays3D(t_data *data, int r, float dis, int vertical)
{
	int	lineH;
	int	yStart;
	int	color;

	dis *= cosf(degToRad(fixAng(data->pa - (data->pa + FOV / 2 - r))));
	lineH = (mapS * HEIGHT) / (dis + 0.0001);
	if (lineH > HEIGHT)
		lineH = HEIGHT;
	yStart = HEIGHT / 2 - lineH / 2;
	color = vertical ? 0x006600 : 0x00AA00;
	draw_vertical_line(data, r * (WIDTH / 2) / FOV + WIDTH / 2, yStart, yStart
		+ lineH, color);
}

void	draw_background(t_data *data)
{
	for (int x = WIDTH / 2; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT / 2; y++)
			my_mlx_pixel_put(data, x, y, 0x00FFFF);
		for (int y = HEIGHT / 2; y < HEIGHT; y++)
			my_mlx_pixel_put(data, x, y, 0x6B4F3B);
	}
}
void	castRays(t_data *data)
{
	float	ra;
	float	disV = 1e6, vx = data->px, vy;
	float	Tan;
	int		dof;
	int		mx;
	int		my;
	float	disH = 1e6, hx = data->px, hy;
	int		mx;
	int		my;
	float	dis;

	ra = fixAng(data->pa + FOV / 2);
	// Fondo 3D
	draw_background(data);
	for (int r = 0; r < FOV; r++)
	{
		// Verticales
		disV = 1e6, vx = data->px, vy = data->py;
		Tan = tanf(degToRad(ra));
		float rx, ry, xo, yo;
		dof = 0;
		if (cosf(degToRad(ra)) > 0.001)
		{
			rx = (((int)data->px >> 6) << 6) + 64;
			ry = (data->px - rx) * Tan + data->py;
			xo = 64;
			yo = -xo * Tan;
		}
		else if (cosf(degToRad(ra)) < -0.001)
		{
			rx = (((int)data->px >> 6) << 6) - 0.0001;
			ry = (data->px - rx) * Tan + data->py;
			xo = -64;
			yo = -xo * Tan;
		}
		else
		{
			rx = data->px;
			ry = data->py;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			if (mx >= 0 && my >= 0 && mx < mapX && my < mapY && map[my * mapX
				+ mx] == 1)
			{
				disV = sqrtf((rx - data->px) * (rx - data->px) + (ry - data->py)
						* (ry - data->py));
				vx = rx;
				vy = ry;
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof++;
			}
		}
		// Horizontales
		disH = 1e6, hx = data->px, hy = data->py;
		Tan = 1.0 / Tan;
		dof = 0;
		if (sinf(degToRad(ra)) > 0.001)
		{
			ry = (((int)data->py >> 6) << 6) - 0.0001;
			rx = (data->py - ry) * Tan + data->px;
			yo = -64;
			xo = -yo * Tan;
		}
		else if (sinf(degToRad(ra)) < -0.001)
		{
			ry = (((int)data->py >> 6) << 6) + 64;
			rx = (data->py - ry) * Tan + data->px;
			yo = 64;
			xo = -yo * Tan;
		}
		else
		{
			rx = data->px;
			ry = data->py;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int)(rx) >> 6;
			my = (int)(ry) >> 6;
			if (mx >= 0 && my >= 0 && mx < mapX && my < mapY && map[my * mapX
				+ mx] == 1)
			{
				disH = sqrtf((rx - data->px) * (rx - data->px) + (ry - data->py)
						* (ry - data->py));
				hx = rx;
				hy = ry;
				dof = 8;
			}
			else
			{
				rx += xo;
				ry += yo;
				dof++;
			}
		}
		// Dibujar
		dis = fminf(disV, disH);
		drawRays2D(data, vx, vy, hx, hy, disV, disH);
		drawRays3D(data, r, dis, (disV < disH));
		ra = fixAng(ra - 1);
	}
}

int	key_handler(int key, t_data *data)
{
	float	moveSpeed;
	float	rotSpeed;

	moveSpeed = 8;
	rotSpeed = 5;
	if (key == XK_Escape)
		exit(0); // ESC
	else if (key == XK_w)
	{ // W
		data->px += data->pdx * moveSpeed;
		data->py += data->pdy * moveSpeed;
	}
	else if (key == XK_s)
	{ // S
		data->px -= data->pdx * moveSpeed;
		data->py -= data->pdy * moveSpeed;
	}
	else if (key == XK_a)
	{ // A
		data->pa = fixAng(data->pa + rotSpeed);
		data->pdx = cosf(degToRad(data->pa));
		data->pdy = -sinf(degToRad(data->pa));
	}
	else if (key == XK_d)
	{ // D
		data->pa = fixAng(data->pa - rotSpeed);
		data->pdx = cosf(degToRad(data->pa));
		data->pdy = -sinf(degToRad(data->pa));
	}
	// Redibujar
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	drawMap2D(data);
	castRays(data);
	drawPlayer(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Raycaster MiniLibX");
	data.px = 300;
	data.py = 300;
	data.pa = 90;
	data.pdx = cosf(degToRad(data.pa));
	data.pdy = -sinf(degToRad(data.pa));
	// Primer render
	key_handler(0, &data);
	mlx_hook(data.win, 2, 1L << 0, key_handler, &data);
	mlx_loop(data.mlx);
	return (0);
}
