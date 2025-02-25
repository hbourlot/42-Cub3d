#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "cube3d.h"

typedef struct s_map
{
	const char	*path;
	char		**cub_array;
	int			width;
	int			height;
	int			error;
}	t_map;


typedef struct s_player
{
	int		direction;
}	t_player;


typedef struct s_cube3d
{
	t_map	map;
	void	*mlx_ptr;
	void	*mlx_win;
	char 	*name;


}	t_cube3d;

#endif