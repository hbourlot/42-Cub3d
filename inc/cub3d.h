/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:18:57 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/15 15:59:06 by joralves         ###   ########.fr       */
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
# define bool _Bool
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
	// t_img		*dirt;
	t_img		*no;
	t_img		*so;
	t_img		*we;
	t_img		*ea;
	t_img		*door_close;
	t_img		*door_open;
	t_img		*floor;
	t_img		*ceiling;
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
	int			wall_hit;
	int hit_side;
	double		wall_x;
	double		dist;
	t_dda dda;
	// t_ray		ray;
	// double timer; // Para animaciones
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
	double		wall_x;
	int			map_x;
	int			map_y;
	t_door *door;
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
	int			mouse_x;
	int			mouse_y;
	float		z_buffer[S_WIDTH];

}				t_cub3d;

// ***************************************************************************
// **							Utils Functions      						**
// ***************************************************************************
int				key_press(int keycode, t_cub3d *game);
int				mouse_signal(int x, int y, t_cub3d *game);

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
int				init_images(t_cub3d *game);
int				init_s_sprite(t_cub3d *game);
int				init_doors(t_map *map);
void			init_player(t_cub3d *game, int x, int y);
int				init_game(t_cub3d *game, int argc, char *argv[]);
int				init_s_cube3d(t_cub3d **game, int argc, char *argv[]);

// ***************************************************************************
// **							Draw Functions       						**
// ***************************************************************************
// void			draw_player2d(t_cub3d *game);
void			draw_player2d(t_cub3d *game, t_player *p);
void			draw_map2d(t_cub3d *game, t_map *map);
int				create_rgb(int t, int r, int g, int b);
// void			draw_line(t_cub3d *game, float x0, float y0, float x1, float y1,
// 					int color);

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
void			map_range(t_map *map);
int				map_reachability(t_cub3d *game, t_map *map, int x, int y);

// ***************************************************************************
// **							Player Functions   							**
// ***************************************************************************
void			normalize_angle(float *angle);
void			rotate_player(t_player *player, int keycode, int signal);
void			locate_spawn_point(t_player *player, t_map *map);
void			move_player(t_map *map, t_player *player, int keycode);

int				get_texture_color(t_img *tex, int x, int y);
t_img			*get_texture(t_cub3d *game, int tex_num);
void			render(t_cub3d *game, t_player *p);
void			set_texture(t_map *map, t_ray *ray, t_dda *dda);
t_ray			cast_ray(t_map *map, double x, double y, double angle);
void			clear_main_img(t_cub3d *game);
void			mouse_handler(t_cub3d *game);
int				collision_door(t_cub3d *game);
// void			init_s_ray(t_ray *ray);
// void			init_s_dda(t_dda *dda, double x, double y, double angle);
// void			fill_s_ray(t_ray *ray, t_dda *dda, double x, double y);
t_door			*find_door(t_map *map, int x, int y);
// t_door *populate_door(t_map *map, t_dda *dda, int x, int y);
t_door *populate_door(t_map *map, t_dda *dda , t_ray *ray);
#endif
