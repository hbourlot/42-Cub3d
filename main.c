#include "./inc/cub3d.h"

int	main(int argc, char *argv[])
{
	t_cub3d	*game;

	game = NULL;
	if (argc != 2)
		return (ft_printf_fd(2, ME_MMA), 1);
	if (init_s_cube3d(&game, argc, argv) < 0)
		return (free_game(game), -1);
	init_game(game, argc, argv);
	free_game(game);
	return (0);
}
