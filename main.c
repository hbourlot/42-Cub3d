#include "./inc/cube3d.h"




#include <math.h>
#include <stdlib.h>

#define WIDTH  400
#define HEIGHT 400
#define TILE_SIZE 50
#define FOV 60 * (M_PI / 180)
#define NUM_RAYS WIDTH

typedef struct {
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bpp;
    int line_length;
    int endian;
    int map[5][5];
    double player_x;
    double player_y;
    double player_angle;
} Game;

int map[5][5] = {
    {1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 1, 1, 1},
    {1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1}
};

void put_pixel(Game *game, int x, int y, int color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        int offset = (y * game->line_length) + (x * (game->bpp / 8));
        *(int *)(game->addr + offset) = color;
    }
}

void draw_vertical_line(Game *game, int x, int wall_height, int color) {
    int start = (HEIGHT / 2) - (wall_height / 2);
    int end = (HEIGHT / 2) + (wall_height / 2);
    for (int y = start; y < end; y++) {
        put_pixel(game, x, y, color);
    }
}

void render_3d(Game *game) {
    int x;

    for (x = 0; x < NUM_RAYS; x++) {
        double ray_angle = game->player_angle + (x - (NUM_RAYS / 2)) * (FOV / NUM_RAYS);
        double ray_x = game->player_x;
        double ray_y = game->player_y;
        double delta_x = cos(ray_angle);
        double delta_y = sin(ray_angle);

        int hit = 0;
        double distance = 0;

        while (!hit) {
            ray_x += delta_x;
            ray_y += delta_y;
            if (map[(int)ray_y][(int)ray_x] == 1) {
                hit = 1;
            }
            distance += 1;
        }

        int wall_height = (int)(HEIGHT / (distance + 0.01));
        draw_vertical_line(game, x, wall_height, 0x999999);
    }
}

int key_hook(int keycode, Game *game) {
    if (keycode == 65361) game->player_angle -= 0.1;
    if (keycode == 65363) game->player_angle += 0.1;
    if (keycode == 65362) {
        game->player_x += cos(game->player_angle) * 0.2;
        game->player_y += sin(game->player_angle) * 0.2;
    }
    if (keycode == 65364) {
        game->player_x -= cos(game->player_angle) * 0.2;
        game->player_y -= sin(game->player_angle) * 0.2;
    }

    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->addr = mlx_get_data_addr(game->img, &game->bpp, &game->line_length, &game->endian);
    
    render_3d(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    mlx_destroy_image(game->mlx, game->img);

    return 0;
}

void initt_game(Game *game) {
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "MiniLibX 3D");
    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->addr = mlx_get_data_addr(game->img, &game->bpp, &game->line_length, &game->endian);
    game->player_x = 2.5;
    game->player_y = 2.5;
    game->player_angle = 0;

    render_3d(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);

    mlx_key_hook(game->win, key_hook, game);
    mlx_loop(game->mlx);
}

int main() {
    Game game;
    initt_game(&game);
    return 0;
}


int	main(int argc, char *argv[])
{
	t_cube3d	*game;
	
	if (argc != 2)
		return (ft_printf_fd(2, ME_MMA), 1);
	if (init_s_cube3d(&game, argc, argv) < 0)
		return (free_game(game), 1);
	init_game(game);
	free_game(game);
	
	return (0);
}
