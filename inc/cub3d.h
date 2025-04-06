/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:18:57 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/06 17:24:29 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../lib/libft/inc/libft.h"
#include "../lib/minilibx-linux/mlx.h"
#include "definitions.h"
#include "error.h"
#include <X11/X.h>      // Button press
#include <X11/keysym.h> // Key device
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	t_img		*dirt;
	t_img		*no;
	t_img		*so;
	t_img		*we;
	t_img		*ea;
	t_img		*floor;
	t_img		*ceiling;
}				t_sprite;

typedef struct s_screen
{
	int			width;
	int			height;
}				t_screen;

typedef struct s_map
{
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
}				t_player;

typedef struct s_line
{
	int			dx;
	int			dy;
	int			steps;
	float		x_inc;
	float		y_inc;
}				t_line;

typedef struct s_dda
{
	char		**grid;
	int			**grid_int;
	int			grid_x;
	int			grid_y;
	float		dir_x;
	float		dir_y;
	float		sx_norm;
	float		sy_norm;
	float		sx;
	float		sy;
	float		initial_x;
	float		initial_y;
	int			step_x;
	int			step_y;
	float		acum_x;
	float		acum_y;
	float		dist;
	int			counter_x;
	int			counter_y;
	int			hitside;
}				t_dda;

typedef struct s_raycast
{
	float		alpha;
	float		ray_angle;
	float		dist;
	float		wall_start;
	float		perp_dist;
	int			column_width;
	int			wall_height;
	int			x_start;
	int			x_end;
	double		hit_x;
	double		hit_y;
	int			screen_y;
	t_dda		dda;
}				t_raycast;

typedef struct s_cub3d
{
	t_map		*map;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*name;
	t_sprite	*sprites;
	t_player	player;

}				t_cub3d;

// ***************************************************************************
// **							Utils Functions      						**
// ***************************************************************************
int				key_press(int keycode, t_cub3d *game);

// ***************************************************************************
// **							map/parsing Functions 						**
// ***************************************************************************
bool			parse_fc(t_map *map);
bool			parse_map(t_map *map);
bool			parse_texture(t_map *map);
bool			invalid_file_name(t_map *map);

// ***************************************************************************
// **							Initialize Functions 						**
// ***************************************************************************
t_screen		*init_s_screen(void);
int				init_s_map(t_map *map);
int				init_s_sprite(t_cub3d *game);
int				init_dirt_sprite(t_cub3d *game);
void			init_player(t_cub3d *game, int x, int y);
int				init_game(t_cub3d *game, int argc, char *argv[]);
int				init_s_cube3d(t_cub3d **game, int argc, char *argv[]);

// ***************************************************************************
// **							Draw Functions       						**
// ***************************************************************************
void			draw_map2d(t_cub3d *game);
void			draw_player2d(t_cub3d *game);
void			draw_background(t_cub3d *game);
void			cast_render_raycast(t_cub3d *game);
int				create_rgb(int t, int r, int g, int b);
void			my_mlx_pixel_put(t_cub3d *game, int x, int y, int color);
void			draw_square(t_cub3d *game, int x, int y, int width, int height,
					int color);
void			draw_line(t_cub3d *game, float x0, float y0, float x1, float y1,
					int color);

// ***************************************************************************
// **							Exit Functions      						**
// ***************************************************************************
void			free_game(t_cub3d *game);

// ***************************************************************************
// **							Map Functions   							**
// ***************************************************************************
int				cub_array(t_map *map);
int				parse_s_map(t_map *map);
int				game_loop(t_cub3d *game);
int				open_cub(const char *path);
int				init_window(t_cub3d *game);
int				count_lines(const char *path);

// ***************************************************************************
// **							Player Functions   							**
// ***************************************************************************
void			normalize_angle(float *angle);
void			rotate_player(t_player *player, int keycode);
void			locate_spawn_point(t_player *player, t_map *map);
void			move_player(t_map *map, t_player *player, int keycode);

// void			dda(t_cub3d *game, t_raycast *raycast, float x0, float y0);
int				init_dirt_sprite(t_cub3d *game);
void			dda(t_cub3d *game, t_raycast *raycast, float x0, float y0);
int				get_texture_color(t_img *tex, int x, int y);
t_img			*get_texture(t_cub3d *game, t_raycast *raycast);