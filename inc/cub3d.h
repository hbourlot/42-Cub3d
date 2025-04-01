/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:18:57 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/31 23:50:39 by joralves         ###   ########.fr       */
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
	int			gridX;
	int			gridY;
	float		dirX;
	float		dirY;
	float		sx_norm;
	float		sy_norm;
	float		sx;
	float		sy;
	float		initialX;
	float		initialY;
	int			stepX;
	int			stepY;
	float		acum_x;
	float		acum_y;
	float		dist;
	int			counterX;
	int			counterY;
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
	int			screen_y;
}				t_raycast;

typedef struct s_cube3d
{
	t_map		*map;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*name;
	t_sprite	*sprites;
	t_player	player;

}				t_cube3d;

// ***************************************************************************
// **							Utils Functions      						**
// ***************************************************************************
int				key_press(int keycode, t_cube3d *game);

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
int				init_s_map(t_map *map);
int				init_game(t_cube3d *game, int argc, char *argv[]);
int				init_s_cube3d(t_cube3d **game, int argc, char *argv[]);
void			init_player(t_cube3d *game, int x, int y);
int				init_dirt_sprite(t_cube3d *game);

// ***************************************************************************
// **							Draw Functions       						**
// ***************************************************************************
void			draw_pixel(t_sprite *sprite, int x, int y, int color);
int				create_rgb(int t, int r, int g, int b);
void			draw_map2d(t_cube3d *game);
void			draw_player2d(t_cube3d *game);
void			draw_line(t_cube3d *game, float x0, float y0, float x1,
					float y1, int color);
void			draw_square(t_cube3d *game, int x, int y, int width, int height,
					int color);
void			my_mlx_pixel_put(t_cube3d *game, int x, int y, int color);
void			cast_render_raycast(t_cube3d *game);
void			draw_background(t_cube3d *game);

// ***************************************************************************
// **							Exit Functions      						**
// ***************************************************************************
void			free_game(t_cube3d *game);

// ***************************************************************************
// **							Map Functions   							**
// ***************************************************************************
int				cub_array(t_map *map);
int				parse_s_map(t_map *map);
int				open_cub(const char *path);
int				init_window(t_cube3d *game);
int				count_lines(const char *path);
int				game_loop(t_cube3d *game);

// ***************************************************************************
// **							Player Functions   							**
// ***************************************************************************
void			move_player(t_map *map, t_player *player, int keycode);
void			rotate_player(t_player *player, int keycode);

float			dda(t_cube3d *game, float x0, float y0, float angle);
void			normalize_angle(float *angle);

int				init_dirt_sprite(t_cube3d *game);
t_screen		*init_s_screen(void);
void			locate_spawn_point(t_player *player, t_map *map);

int				init_s_sprite(t_cube3d *game);