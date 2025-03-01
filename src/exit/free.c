/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:14:58 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/01 07:39:53 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube3d.h"

static void	free_map(t_map *map)
{
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
	
}

void free_data(t_cube3d *data)
{
	free_map(&data->map);
	
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
