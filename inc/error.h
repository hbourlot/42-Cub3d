#include "cube3d.h"

# define E_MMA "Error: Missing map argument\n"
# define E_MF "Error: mlx_init fail\n"
# define E_NW "Error: mlx_new_window fail\n"
# define E_IMP "Error: Invalid map path\n"
# define E_MINFO "Error: The map doesn't have all the necessary information!\n"

typedef enum s_status {
	E_MALLOC = -10,
	E_FD,
	MMA,
	MF,
	NW,
	IMP,
	SUCCESS = 0,
}		t_status;