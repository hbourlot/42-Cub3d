/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/04 16:58:25 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/04 17:44:03 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/cub3d.h"


int	main(int argc, char *argv[])
{
	t_cub3d *game;

	game = NULL;

	if (argc != 2)
		return (ft_printf_fd(2, ME_MMA), 1);
	if (init_s_cube3d(&game, argv) < 0)
		return (free_game(game), -1);
	if (init_game(game) < 0)
		return (free_game(game), -1);
	free_game(game);
	return (0);
}
