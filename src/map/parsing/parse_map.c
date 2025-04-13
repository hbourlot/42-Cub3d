/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:09:48 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/12 23:47:28 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	allocate_map_array(t_map *map, int i)
{
	int	j;
	int	len;

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
		len = ft_strlen(map->map_array[j]);
		if (map->map_array[j][len - 1] == '\n' && len > 1)
			map->map_array[j][len - 1] = '\0';
		j++;
		i++;
	}
	return (SUCCESS);
}


// !! CAN BE USEFULL
static int	allocate_map_world(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->map_world = ft_calloc(map->height + 1, sizeof(int *));
	if (!map->map_world)
		return (ft_printf_fd(2, ME_MALLOC), -1);
	while (map->map_array[i])
	{
		j = 0;
		map->map_world[i] = ft_calloc(map->width + 1, sizeof(int));
		if (!map->map_array[i])
		{
			while (i-- > 0)
				free(map->map_world[i]);
			free(map->map_world);
			return (ft_printf_fd(2, ME_MALLOC), -1);
		}
		while (map->map_array[i][j] && map->map_array[i][j] != '\n')
		{
			if (map->map_array[i][j] == '1')
				map->map_world[i][j] = 1;
			else if (map->map_array[i][j] == '2')
				map->map_world[i][j] = 2;
			else
				map->map_world[i][j] = 0;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

static bool	is_map_valid(char **cub_array, const char *valid_chars, int i)
{
	int	j;

	while (cub_array[i])
	{
		j = 0;
		while (cub_array[i][j])
		{
			if (!ft_strchr(valid_chars, cub_array[i][j]))
			{
				// printf("Caractere inválido encontrado: '%c' (ASCII: %d)\n",
				// cub_array[i][j], cub_array[i][j]);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

static int		parse_map_aux(t_map *map, int *i)
{
	*i = -1;
	while (map->cub_array[++(*i)])
	{
		if (map->cub_array[*i][0] == '\0' || all_same_char(map->cub_array[*i], ' ') || map->cub_array[*i][0] == '\n')
			continue;
		break;
	}
	if (!map->cub_array[*i])
		return (-1);

	return (0);
}

bool	parse_map(t_map *map)
{
	int			i;
	const char	*valid_chars = "102NSEW \t\n";

	if (parse_map_aux(map, &i) < 0)
		return (ft_printf_fd(2, ME_MINFO), true);
	if (is_map_valid(map->cub_array, valid_chars, i))
	{
		if (allocate_map_array(map, i))
			return (false);
		map_range(map);
		if (allocate_map_world(map))
			return (false);
	}
	else
		return (ft_printf_fd(2, ME_MINFO), true);
	return (SUCCESS);
}
