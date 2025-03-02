/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:14:58 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/02 20:41:17 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube3d.h"

static void	free_map(t_map *map)
{
	int	i;

	i = 0;
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

void free_data(t_cube3d *data)
{
	free_map(&data->map);
	
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
