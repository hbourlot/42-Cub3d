/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:06:44 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/01 11:21:23 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	init_s_map(t_map *map)
{
	int			status;

	map->nbr_of_lines = count_lines(map->path);
	if (map->nbr_of_lines < 0)
		return (-1);
	if (map->nbr_of_lines == 0)
		return (ft_printf_fd(2, ME_EM), -1);
	if (cub_array(map) < 0)
		return (-1);
	if (parse_s_map(map))
		return (-1);
	return (0);
}
