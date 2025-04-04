/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_range.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 14:44:13 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/04 14:57:31 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void map_range(t_map *map)
{
    int i;
    int j;
    
    i = 0;
    while(map->map_array[i])
    {
        j = 0;
        while(map->map_array[i][j])
        {
            j++;
            if (j > map->width)
                map->width = j;
        }
       i++; 
    }
    map->height = i;
}
