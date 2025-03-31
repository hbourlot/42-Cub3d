/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:14:58 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/31 18:14:20 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	free_map(t_map *map)
{
	int	i;

	// printf("Here\n");
	i = 0;
	if (!map)
		return ;
	while (map->map_array && map->map_array[i])
	{
		free(map->map_array[i]);
		i++;
	}
	if (map->map_array)
		free(map->map_array);
	if (map->cub_array)
		free_split(map->cub_array);
	if (map->ea)
		free_pointers(1, &map->ea);
	if (map->no)
		free_pointers(1, &map->no);
	if (map->we)
		free_pointers(1, &map->we);
	if (map->so)
		free_pointers(1, &map->so);
	if (map->ceiling)
		free_pointers(1, &map->ceiling);
	if (map->floor)
		free_pointers(1, &map->floor);
}

void	free_game(t_cube3d *game)
{
	printf("HEre\n");
	free_map(game->map);
	if (game->img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->img_ptr);
	if (game->mlx_ptr)
	{
		if (game->mlx_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	exit(0);
}
