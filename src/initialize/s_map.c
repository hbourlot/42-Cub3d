/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:06:44 by hbourlot          #+#    #+#             */
/*   Updated: 2025/02/27 17:43:07 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	init_s_map(t_map *map)
{
	int			status;
	const char *compass[] = {"NO", "SO", "WE", "EA", NULL};

	status = cub_array(map);
	if (status < 0)
		return (status); //TODO: Need to menage the output error
	return (0);
}