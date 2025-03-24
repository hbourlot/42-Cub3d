/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:18:57 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/24 01:15:21 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../lib/libft/inc/libft.h"
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/raycasting/inc/raycasting.h"
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

typedef struct s_sprite
{
	char		*addr;
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	int			size_x;
	int			size_y;
	int			color;
	int			bpp;
	int			size_line;
	int			endian;
}				t_sprite;

typedef struct s_img
{
	t_sprite	*no;
	t_sprite	*so;
	t_sprite	*we;
	t_sprite	*ea;
	t_sprite	*floor;
	t_sprite	*ceiling;
}				t_img;

typedef struct s_map
{
	const char	*path;
	char		**cub_array;
	char		**map_array;
	int			nbr_of_lines;
	int			screen_width;
	int			screen_height;
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
	int			direction;
	float		x;
	float		y;
	float		pdx;
	float		pdy;
	float		angle;
}				t_player;

typedef struct s_dda
{
	int			dx;
	int			dy;
	int			steps;
	float		x_inc;
	float		y_inc;
}				t_dda;

typedef struct s_cube3d
{
	t_map		*map;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*name;
	t_img		*sprites;
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
int				init_game(t_cube3d *game);
int				init_s_cube3d(t_cube3d **game, int argc, char *argv[]);
void			init_player(t_cube3d *game, int x, int y);

// ***************************************************************************
// **							Draw Functions       						**
// ***************************************************************************
void			draw_pixel(t_sprite *sprite, int x, int y, int color);
int				create_rgb(int t, int r, int g, int b);
void			draw_map2d(t_cube3d *game);
void			draw_player2d(t_cube3d *game);
void			draw_line(t_cube3d *game, float x0, float y0, float x1,
					float y1, int color);
// void			draw_rays2d(t_cube3d *game, t_player *player, t_map *map);
void			draw_square(t_cube3d *game, int x, int y, int width, int height,
					int color);
void			my_mlx_pixel_put(t_cube3d *game, int x, int y, int color);
void			drawRaycast(t_cube3d *game);

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

float			DDA(t_cube3d *game, float x0, float y0, float angle);
void			normalize_angle(float *angle);
