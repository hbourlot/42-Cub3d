#include "../lib/minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TILE_SIZE 64
#define MAP_SIZE 12
#define WIDTH 640
#define HEIGHT 480
#define FOV 1.0472
#define NUM_TEXTURES 4

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}			t_texture;

typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
	double	speed;
	double	rot_speed;
}			t_player;

typedef struct s_ray
{
	double	dist;
	int		hit_side;
	int		tex_num;
	double	wall_x;
}			t_ray;

// Mapa del juego
int			map[MAP_SIZE][MAP_SIZE] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, {1, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1},
				{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 1, 0, 0, 0, 0, 0, 0,
				0, 1}, {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1}, {1, 0, 1, 0, 0, 0, 0,
				0, 0, 0, 1}, {1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1}, {1, 0, 1, 0, 1,
				1, 0, 1, 0, 0, 1}, {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1}, {1, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

// Variables globales
void		*mlx;
void		*win;
void		*img;
char		*addr;
int			bpp;
int			line_len;
int			endian;

int			key_w = 0;
int			key_a = 0;
int			key_s = 0;
int			key_d = 0;

t_texture	textures[NUM_TEXTURES];

// Cargar texturas
void	load_textures(void)
{
	textures[0].img = mlx_xpm_file_to_image(mlx, "texture/wall/grass_block.xpm",
			&textures[0].width, &textures[0].height);
	textures[1].img = mlx_xpm_file_to_image(mlx, "texture/wall/wall1.xpm",
			&textures[1].width, &textures[1].height);
	textures[2].img = mlx_xpm_file_to_image(mlx, "texture/wall/wall2.xpm",
			&textures[2].width, &textures[2].height);
	textures[3].img = mlx_xpm_file_to_image(mlx, "texture/wall/wall3.xpm",
			&textures[3].width, &textures[3].height);
	for (int i = 0; i < NUM_TEXTURES; i++)
	{
		if (!textures[i].img)
		{
			printf("Error loading texture %d\n", i);
			exit(1);
		}
		textures[i].addr = mlx_get_data_addr(textures[i].img, &textures[i].bpp,
				&textures[i].line_len, &textures[i].endian);
	}
}

// Obtener color de la textura
int	get_texture_color(t_texture *tex, int x, int y)
{
	int	color;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0x000000);
	color = *(int *)(tex->addr + (y * tex->line_len) + (x * (tex->bpp / 8)));
	return (color);
}

// Algoritmo DDA para raycasting
t_ray cast_ray(double x, double y, double angle)
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
	int		hit;

	ray.dist = 1000000.0;  // Valor grande como "infinito"
	ray.hit_side = 0;
	ray.tex_num = 0;
	ray.wall_x = 0;

	dir_x = cos(angle);
	dir_y = sin(angle);
	map_x = (int)x;
	map_y = (int)y;
	delta_dist_x = fabs(1 / dir_x);
	delta_dist_y = fabs(1 / dir_y);
	side_dist_x = dir_x < 0 ? (x - map_x) * delta_dist_x : (map_x + 1.0 - x) * delta_dist_x;
	side_dist_y = dir_y < 0 ? (y - map_y) * delta_dist_y : (map_y + 1.0 - y) * delta_dist_y;
	step_x = dir_x < 0 ? -1 : 1;
	step_y = dir_y < 0 ? -1 : 1;
	hit = 0;

	while (!hit)
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
		if (map_x < 0 || map_x >= MAP_SIZE || map_y < 0 || map_y >= MAP_SIZE)
			break ;
		if (map[map_x][map_y] > 0)
		{
			ray.dist = (ray.hit_side == 0) ? (map_x - x + (1 - step_x) / 2) / dir_x
										   : (map_y - y + (1 - step_y) / 2) / dir_y;
			if (ray.hit_side == 0)
			{
				ray.wall_x = y + ray.dist * dir_y;
				ray.tex_num = (dir_x > 0) ? 2 : 3;
			}
			else
			{
				ray.wall_x = x + ray.dist * dir_x;
				ray.tex_num = (dir_y > 0) ? 1 : 0;
			}
			ray.wall_x -= floor(ray.wall_x);
			hit = 1;
		}
	}
	return (ray);
}


// Renderizar escena
void	render(t_player *p)
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

	// Limpiar buffer de imagen
	memset(addr, 0x33, WIDTH * HEIGHT * (bpp / 8));
	// Lanzar rayos
	for (int x = 0; x < WIDTH; x++)
	{
		ray_angle = p->angle + FOV / 2 - (x * FOV / WIDTH);
		ray = cast_ray(p->x / TILE_SIZE, p->y / TILE_SIZE, ray_angle);
		if (ray.dist < INFINITY)
		{
			corrected_dist = ray.dist * cos(ray_angle - p->angle);
			line_height = (int)(HEIGHT / corrected_dist);
			draw_start = -line_height / 2 + HEIGHT / 2;
			draw_start = draw_start < 0 ? 0 : draw_start;
			draw_end = line_height / 2 + HEIGHT / 2;
			draw_end = draw_end >= HEIGHT ? HEIGHT - 1 : draw_end;
			// Mapeo de textura
			tex_x = (int)(ray.wall_x * textures[ray.tex_num].width);
			if ((!ray.hit_side && cos(ray_angle) > 0) || (ray.hit_side
					&& sin(ray_angle) < 0))
				tex_x = textures[ray.tex_num].width - tex_x - 1;
			step = 1.0 * textures[ray.tex_num].height / line_height;
			tex_pos = (draw_start - HEIGHT / 2 + line_height / 2) * step;
			// Dibujar columna texturizada
			for (int y = draw_start; y < draw_end; y++)
			{
				tex_y = (int)tex_pos & (textures[ray.tex_num].height - 1);
				tex_pos += step;
				color = get_texture_color(&textures[ray.tex_num], tex_x, tex_y);
				pixel = (y * line_len) + (x * 4);
				*(int *)(addr + pixel) = color;
			}
		}
	}
	mlx_put_image_to_window(mlx, win, img, 0, 0);
}

// Loop principal del juego
int	game_loop(t_player *p)
{
	static clock_t	last = 0;
	clock_t			now;
	double			delta;
	double			move_speed;
	double			rot_speed;

	now = clock();
	delta = (double)(now - last) / CLOCKS_PER_SEC;
	last = now;
	// Movimiento
	move_speed = p->speed * delta;
	rot_speed = p->rot_speed * delta;
	if (key_w)
	{
		p->x += cos(p->angle) * move_speed;
		p->y += sin(p->angle) * move_speed;
	}
	if (key_s)
	{
		p->x -= cos(p->angle) * move_speed;
		p->y -= sin(p->angle) * move_speed;
	}
	if (key_a)
		p->angle -= rot_speed;
	if (key_d)
		p->angle += rot_speed;
	// Colisión simple
	if (map[(int)(p->x / TILE_SIZE)][(int)(p->y / TILE_SIZE)] != 0)
	{
		p->x -= cos(p->angle) * move_speed;
		p->y -= sin(p->angle) * move_speed;
	}
	render(p);
	return (0);
}

// Manejadores de teclado
int	key_press(int key, void *param)
{
	if (key == XK_w)
		key_w = 1;
	if (key == XK_a)
		key_a = 1;
	if (key == XK_s)
		key_s = 1;
	if (key == XK_d)
		key_d = 1;
	if (key == XK_Escape)
		exit(0);
	return (0);
}

int	key_release(int key, void *param)
{
	if (key == XK_w)
		key_w = 0;
	if (key == XK_a)
		key_a = 0;
	if (key == XK_s)
		key_s = 0;
	if (key == XK_d)
		key_d = 0;
	return (0);
}

int	main(void)
{
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Raycaster");
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);

	load_textures();

	t_player player = {.x = 3 * TILE_SIZE + TILE_SIZE / 2, .y = 3 * TILE_SIZE
		+ TILE_SIZE / 2, .angle = 0, .speed = 200, .rot_speed = 2};

	mlx_hook(win, KeyPress, KeyPressMask, key_press, &player);
	mlx_hook(win, KeyRelease, KeyReleaseMask, key_release, &player);
	mlx_loop_hook(mlx, game_loop, &player);
	mlx_loop(mlx);

	return (0);
}