/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:56:43 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/17 01:41:19 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**allocate_cub_array(int nbr_of_lines)
{
	char	**cub_array;

	cub_array = ft_calloc(nbr_of_lines + 1, sizeof(char *));
	if (!cub_array)
		return (ft_printf_fd(2, ME_MALLOC), NULL);
	return (cub_array);
}

static int	fill_cub_array(char **cub_array, const char *path)
{
	int		fd;
	int		i;
	char	*line;

	fd = open_cub(path);
	if (fd < 0)
		return (ft_printf_fd(2, ME_FD), -1);
	i = 1;
	line = get_next_line(fd);
	if (!line)
		return (-1);
	cub_array[0] = line;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		cub_array[i] = line;
		i++;
	}
	close(fd);
	return (0);
}

int	cub_array(t_map *map)
{
	map->cub_array = allocate_cub_array(map->nbr_of_lines);
	if (!map->cub_array)
		return (-1);
	if (fill_cub_array(map->cub_array, map->path) < 0)
		return (-1);
	return (SUCCESS);
}
