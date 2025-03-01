#include "cube3d.h"

# define ME_MMA "Error: Missing map argument!\n"
# define ME_MALLOC "Error: Malloc!\n"
# define ME_MF "Error: mlx_init fail!\n"
# define ME_NW "Error: mlx_new_window fail!\n"
# define ME_IMP "Error: Invalid map path!\n"
# define ME_MINFO "Error: The map doesn't have all the necessary information!\n"

typedef enum s_status {
	E_MALLOC = -10,
	E_FD,
	SUCCESS = 0,
}		t_status;