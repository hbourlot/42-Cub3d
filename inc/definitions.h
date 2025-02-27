#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "cube3d.h"

# define NORTH 	"NO"
# define SOUTH 	"SO"
# define WEST	"WE"
# define EAST	"EA"
# define CMP_OK	0

typedef struct s_map
{
	const char	*path;
	char		**cub_array;
	int			nbr_of_lines;
	int			width;
	int			height;
	const char	*path_no;
	const char	*path_so;
	const char	*path_we;
	const char	*path_ea;
	int			error; // ! Maybe i can use
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