/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:40:08 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/11 14:51:35 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void print_map_detailed(t_cub3d *game)
{
	int	i;
	int	j;
	char c;

	i = 0;
	printf("--- START DEBUG MAP ---\n");
	while (game->map->map_array[i])
	{
		j = 0;
		while (game->map->map_array[i][j])
		{
			c = game->map->map_array[i][j];
			printf("map_array[%d][%d]: char: '%c' value: '%d'\n", i, j, c, c);
			j++;
		}
		i++;
	}
	printf("--- END DEBUG MAP ---\n");
}

void print_map(t_cub3d *game)
{
	int	i;
	int	j;
	char c;

	i = 0;
	printf("--- START DEBUG MAP ---\n");
	while (game->map->map_array[i])
	{
		j = 0;
		while (game->map->map_array[i][j])
		{
			c = game->map->map_array[i][j];
			printf("%c", c);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("--- END DEBUG MAP ---\n");	
}