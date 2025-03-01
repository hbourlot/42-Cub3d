/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:06:44 by hbourlot          #+#    #+#             */
/*   Updated: 2025/02/28 10:08:40 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	init_s_map(t_map *map)
{
	int			status;

	status = cub_array(map);
	if (status < 0)
		return (status); //TODO: Need to menage the error output
	map->nbr_of_lines = count_lines(map->path);
	if (parse_s_map(map))
		return (-1);
	return (0);
}
