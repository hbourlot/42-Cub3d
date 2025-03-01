/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:09:48 by hbourlot          #+#    #+#             */
/*   Updated: 2025/02/28 10:12:51 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube3d.h"


int	parse_s_map(t_map *map)
{
	if (map->nbr_of_lines < 9)
		return (ft_printf_fd(2, ME_MINFO), -1);
	if (parse_texture(map) < 0)
		return (-1);		
}

