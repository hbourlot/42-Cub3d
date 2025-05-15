/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:18:57 by hbourlot          #+#    #+#             */
/*   Updated: 2025/05/15 20:50:44 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/inc/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include "definitions.h"
# include "error.h"
# include <X11/X.h>      // Button press
# include <X11/keysym.h> // Key device
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			color;
	int			endian;
}				t_img;

typedef struct s_sprite
{
	t_img		*no;
	t_img		*so;
	t_img		*we;
	t_img		*ea;
	t_img		*door_close;
	t_img		*door_open;
	int 		floor;
	int 		ceiling;
}				t_sprite;

typedef struct s_screen
{
	int			width;
	int			height;
}				t_screen;

typedef struct s_dda
{
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			step_x;
	int			step_y;
}				t_dda;

typedef struct s_door
{
	int			x;
	int			y;
	int			is_open;
	// double timer;
}				t_door;

typedef struct s_map
{
	t_door		*doors;
	int			num_doors;
	const char	*path;
	char		**cub_array;
	char		**map_array;
	int			**map_world;
	int			nbr_of_lines;
	int			width;
	int			height;
	const char	*no;
	const char	*so;
	const char	*we;
	const char	*ea;
	const char	*floor;
	const char	*ceiling;
}				t_map;

typedef struct s_player
{
	char		dir;
	float		x;
	float		y;
	float		pdx;
	float		pdy;
	float		angle;
	float		collider;
	float		director[2];
}				t_player;

typedef struct s_line
{
	int			dx;
	int			dy;
	int			steps;
	float		x_inc;
	float		y_inc;
}				t_line;

typedef struct s_ray
{
	double		dist;
	int			hit_side;
	int			tex_num;
	int			wall_hit;
	int			map_x;
	int			map_y;
	double		wall_x;
	t_door		*door;
}				t_ray;

typedef struct s_draw
{
	double		corrected_dist;
	int			line_height;
	int			start;
	int			end;
	int			x;
}				t_draw;

typedef struct s_tex
{
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	int			color;
}				t_tex;

typedef struct s_cub3d
{
	t_map		*map;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		main_img;
	t_img		map_img;
	char		*name;
	t_sprite	*sprites;
	t_player	player;
	bool		mouse_on;
	int			mouse_x;
	int			mouse_y;

}				t_cub3d;

// ***************************************************************************
// **                            Core Functions                            **
// ***************************************************************************
t_cub3d         *get_cub();
t_screen        *init_s_screen(void);
void            init_s_map(t_map *map);
void            init_s_ray(t_ray *ray);
void            init_doors(t_map *map);
void            init_s_ray(t_ray *ray);
void            free_world(int **world);
void			game_loop(t_cub3d *game);
void            init_images(t_cub3d *game);
void			init_window(t_cub3d *game);
void            init_player(t_cub3d *game);
void            free_game(int exit_status);
void            init_s_sprite(t_cub3d *game);
void            init_s_cub3d(t_cub3d *game, char *argv[]);
void            init_s_dda(t_dda *dda, double x, double y, double angle);

// ***************************************************************************
// **                            Gameplay Functions                        **
// ***************************************************************************
void            normalize_angle(float *angle);
int             collision_door(t_cub3d *game);
t_door          *find_door(t_map *map, int x, int y);
void            set_player_spawn(t_player *player, t_map *map);
void            move_player(t_map *map, t_player *player, int keycode);
void            rotate_player(t_player *player, int keycode, int signal);
void            handle_player_collision(t_player *player, t_map *map, float new_x, float new_y);

// ***************************************************************************
// **                            Graphics Functions                        **
// ***************************************************************************
void            clear_main_img(t_cub3d *game);
void            raycaster(t_cub3d *game, t_player *p);
void            draw_map2d(t_cub3d *game, t_map *map);
int             create_rgb(int t, int r, int g, int b);
t_img           *get_texture(t_cub3d *game, int tex_num);
int             get_texture_color(t_img *tex, int x, int y);
void            set_texture(t_map *map, t_ray *ray, t_dda *dda);
void            put_pixel_img(t_img *img, int x, int y, int color);
void            perform_dda_loop(t_map *map, t_ray *ray, t_dda *dda);
t_ray           cast_ray(t_map *map, double x, double y, double angle);
void            fill_s_ray(t_ray *ray, t_dda *dda, double x, double y);
t_ray           cast_ray_door(t_map *map, double x, double y, double angle);
void            draw_line(t_cub3d *game, float initial[2], float final[2], int color);

// ***************************************************************************
// **                            Parsing Functions                         **
// ***************************************************************************
bool            parse_map(t_map *map);
void            map_range(t_map *map);
void            parse_s_map(t_map *map);
bool            parse_texture(t_map *map);
int             open_cub(const char *path);
void            init_cub_array(t_map *map);
int             map_reachability(t_map *map);
bool            invalid_file_name(t_map *map);
int             count_lines(const char *path);
int             check_unique_textures(t_map *map);
void            parse_fc(t_map *map, t_sprite *sprite);

// ***************************************************************************
// **                            Helper Functions                          **
// ***************************************************************************
void            mouse_handler(t_cub3d *game);
int             key_press(int keycode, t_cub3d *game);
int             mouse_signal(int x, int y, t_cub3d *game);

#endif
