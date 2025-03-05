#include "./inc/cube3d.h"

// #include <math.h>

// #define WIDTH  400
// #define HEIGHT 400
// #define TILE_SIZE 50
// #define FOV 60 * (M_PI / 180)  // Convert degrees to radians
// #define NUM_RAYS WIDTH         // One ray per column

// typedef struct {
//     void *mlx;
//     void *win;
//     int map[5][5];  // Simple 5x5 map
//     double player_x;
//     double player_y;
//     double player_angle;
// } Game;

// int map[5][5] = {
//     {1, 1, 1, 1, 1},
//     {1, 0, 0, 0, 1},
//     {1, 0, 0, 0, 1},
//     {1, 0, 0, 0, 1},
//     {1, 1, 1, 1, 1}
// };

// // Function to draw vertical line (wall slice)
// void draw_vertical_line(Game *game, int x, int wall_height, int color) {
//     int start = (HEIGHT / 2) - (wall_height / 2);
//     int end = (HEIGHT / 2) + (wall_height / 2);
//     for (int y = start; y < end; y++) {
//         mlx_pixel_put(game->mlx, game->win, x, y, color);
//     }
// }

// // Raycasting algorithm
// void render_3d(Game *game) {
//     int x;
//     for (x = 0; x < NUM_RAYS; x++) {
//         double ray_angle = game->player_angle + (x - (NUM_RAYS / 2)) * (FOV / NUM_RAYS);
//         double ray_x = game->player_x;
//         double ray_y = game->player_y;
//         double ray_dx = cos(ray_angle) * 0.1;
//         double ray_dy = sin(ray_angle) * 0.1;

//         while (map[(int)ray_y][(int)ray_x] == 0) {
//             ray_x += ray_dx;
//             ray_y += ray_dy;
//         }

//         double distance = sqrt((ray_x - game->player_x) * (ray_x - game->player_x) +
//                                (ray_y - game->player_y) * (ray_y - game->player_y));

//         int wall_height = (int)(HEIGHT / (distance + 0.01));  // Avoid division by zero
//         draw_vertical_line(game, x, wall_height, 0x999999);
//     }
// }

// // Handle player movement
// int key_hook(int keycode, Game *game) {
//     if (keycode == 65361) game->player_angle -= 0.1; // Left
//     if (keycode == 65363) game->player_angle += 0.1; // Right
//     if (keycode == 65362) { // Up
//         game->player_x += cos(game->player_angle) * 0.2;
//         game->player_y += sin(game->player_angle) * 0.2;
//     }
//     if (keycode == 65364) { // Down
//         game->player_x -= cos(game->player_angle) * 0.2;
//         game->player_y -= sin(game->player_angle) * 0.2;
//     }

//     mlx_clear_window(game->mlx, game->win);
//     render_3d(game);
//     return 0;
// }

// // Initialize the game
// void init_game(Game *game) {
//     game->mlx = mlx_init();
//     game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "MiniLibX 3D");
//     game->player_x = 2.5;
//     game->player_y = 2.5;
//     game->player_angle = 0;
    
//     render_3d(game);
//     mlx_key_hook(game->win, key_hook, game);
//     mlx_loop(game->mlx);
// }

// int main() {
//     Game game;
//     init_game(&game);
//     return 0;
// }




int	main(int argc, char *argv[])
{

	t_cube3d	*data;

	if (argc != 2)
		return (ft_printf_fd(2, ME_MMA), 1);
	data = init_s_cube3d(argc, argv);
	init_window(data);
	// if (data->map.map_array)
	// {
	// 	for (int i = 0; data->map.map_array[i]; i++)
	// 	{
	// 		printf("%s", data->map.map_array[i]);
	// 	}
	// }
	free_data(data);

	return (0);
}
