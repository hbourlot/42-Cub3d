/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:05:13 by joralves          #+#    #+#             */
/*   Updated: 2025/04/17 15:05:13 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"


t_cub3d	*get_cub()
{
	static	t_cub3d data;

	return (&data);
}

int	main(int argc, char *argv[])
{
	t_cub3d			*game;
	static t_map	map;
	static t_sprite	sprites;

	if (argc != 2)
		return (ft_printf_fd(2, ME_MMA), 1);
	game = get_cub();
	game->map = &map;
	game->sprites = &sprites;
	init_s_cub3d(game, argv);
	game_loop(game);
	free_game(0);
	return (0);
}
