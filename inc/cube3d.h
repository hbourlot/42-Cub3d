#ifndef CUBE3D_H
#define CUBE3D_H

# include "../lib/libft/inc/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include "definitions.h"
# include "error.h"
// # include <X11/X.h>      // Button press
// # include <X11/keysym.h> // Key device
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>

// ***************************************************************************
// **						   Parsing Functions						    **
// ***************************************************************************


// ***************************************************************************
// **						   Initialize Functions 						**
// ***************************************************************************
int				init_s_map(t_map *map);
t_cube3d* 		init_s_cube3d(int argc, char *argv[]);


// ***************************************************************************
// **						    Draw Functions   							**
// ***************************************************************************

// ***************************************************************************
// **						    Exit Functions   							**
// ***************************************************************************
void	free_data(t_cube3d *data);

// ***************************************************************************
// **						    Map Functions   							**
// ***************************************************************************
int 	open_cub(const char *path);
int		init_window(t_cube3d *data);
int		cub_array(t_map *map);
int		count_lines(const char *path);




int		game_loop(t_cube3d *data);
#endif