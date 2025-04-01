/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:56:43 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/01 01:01:39 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**allocate_cub_array(int nbr_of_lines, t_map *map)
{
	char	**cub_array;

	cub_array = ft_calloc(nbr_of_lines + 1, sizeof(char *));
	if (!cub_array)
		return (ft_printf_fd(2, ME_MALLOC), NULL);
	return (cub_array);
}

static int	fill_cub_array(char **cub_array, const char *path)
{
	int	fd;
	int	i;

	fd = open_cub(path);
	if (fd < 0)
		return (ft_printf_fd(2, ME_FD), -1);
	i = 0;
	while ((cub_array[i] = get_next_line(fd)))
		i++;
	close(fd);
	return (0);
}

int	cub_array(t_map *map)
{
	map->cub_array = allocate_cub_array(map->nbr_of_lines, map);
	if (!map->cub_array)
		return (-1);
	if (fill_cub_array(map->cub_array, map->path) < 0)
		return (-1);
	return (SUCCESS);
}
