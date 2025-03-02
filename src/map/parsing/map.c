/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:09:48 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/02 20:45:17 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	allocate_map(t_map *map, int i)
{
	int		j;

	j = 0;
	map->map_array = ft_calloc(map->nbr_of_lines - i + 1, sizeof(char *));
	if (!map->map_array)
		return (ft_printf_fd(2, ME_MALLOC), -1);
	while (map->cub_array[i])
	{
		map->map_array[j] = ft_strdup(map->cub_array[i]);
		if (!map->map_array[j])
		{
			while (--j >= 0)
				free(map->map_array[j]);
			free(map->map_array);
			return (ft_printf_fd(2, ME_MALLOC), -1);
		}
		j++;
		i++;
	}
	return (SUCCESS);
}

static bool is_map_valid(char **cub_array, const char *valid_chars, int i)
{
    int j;

    while (cub_array[i])
    {
        j = 0;
        while (cub_array[i][j])
        {
			if (!ft_strchr(valid_chars, cub_array[i][j]))
			{
				// printf("Caractere inválido encontrado: '%c' (ASCII: %d)\n", cub_array[i][j], cub_array[i][j]);
				return (false);
			}
            j++;
        }
        i++;
    }
    return (true);
}

bool	parse_map(t_map *map)
{
	int		i;
	const char *valid_chars = "10NSEW \t\n";

	i = -1;
	while (map->cub_array[++i])
	{
		// printf("line: >%s<\n",  map->cub_array[i]);
		if (map->cub_array[i][0] == '\0' || all_same_char(map->cub_array[i], ' ')
			|| map->cub_array[i][0] == '\n')
			continue;
		break;
	}
	if (!map->cub_array[i])
		return (ft_printf_fd(2, ME_MINFO), true);
	if (is_map_valid(map->cub_array, valid_chars, i))
	{
		if (allocate_map(map, i))
			return (false);	
	}
	else
		return (ft_printf_fd(2, ME_MINFO), true);
	return (SUCCESS);
}
