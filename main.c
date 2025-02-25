#include "./inc/cube3d.h"

int	main(int argc, char *argv[])
{

	t_cube3d	*data;

	if (argc != 2)
		return (ft_printf_fd(2, E_MMA), 1);
	data = init_s_cube3d(argc, argv);
	init_window(data);
	free_data(data);

	return 0;
}