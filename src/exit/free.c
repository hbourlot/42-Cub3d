/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:14:58 by hbourlot          #+#    #+#             */
/*   Updated: 2025/02/27 18:05:25 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube3d.h"

static void	free_map(t_map *map)
{
	if (map->cub_array)
		free_split(map->cub_array);
}

void free_data(t_cube3d *data)
{
	free_map(&data->map);
	
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
