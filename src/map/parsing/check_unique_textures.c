/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unique_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:40:15 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/14 13:30:36 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_unique_textures(t_map *map)
{
	int			i;
	int			j;
	const char	*arr_ptr[] = {map->no, map->ea, map->we, map->so, NULL};

	
	i = 0;
	while (arr_ptr[i])
	{
		j = i + 1;
		while (arr_ptr[j])
		{
			if (ft_strcmp(arr_ptr[i], arr_ptr[j]) == 0)
			{
				ft_printf_fd(2, "Error: Using same textures '%s'!\n", arr_ptr[i]);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
