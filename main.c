#include "./inc/cube3d.h"

int	main(int argc, char *argv[])
{

	t_cube3d	*data;

	if (argc != 2)
		return (ft_printf_fd(2, ME_MMA), 1);
	data = init_s_cube3d(argc, argv);
	init_window(data);
	if (data->map.map_array)
	{
		for (int i = 0; data->map.map_array[i]; i++)
		{
			printf("%s", data->map.map_array[i]);
		}
	}
	free_data(data);

	return (0);
}
