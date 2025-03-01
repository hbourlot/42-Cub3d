/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:09:48 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/01 11:21:28 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	parse_s_map(t_map *map)
{
	if (map->nbr_of_lines < 9)
		return (ft_printf_fd(2, ME_MINFO), -1);
	if (parse_texture(map))
		return (-1);
	if (parse_fc(map))
		return (-1);
	if (invalid_file_name(map))
		return (-1);
	
}
