/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:40:08 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/12 19:13:18 by joralves         ###   ########.fr       */
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
		printf(" -> lenth: %ld | height: %d", ft_strlen(game->map->map_array[i]), i + 1);
		printf("\n");
		i++;
	}
	printf("--- END DEBUG MAP ---\n");	
}
void print_map_2(t_cub3d *game)
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