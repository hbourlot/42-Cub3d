/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:56:43 by hbourlot          #+#    #+#             */
/*   Updated: 2025/02/27 17:45:44 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int lines_in_cub(int fd)
{
	char	*line;
	int		nbr_of_line;

	nbr_of_line = 0;
	line = get_next_line(fd);
	while (line)
	{
		nbr_of_line++;
		free(line);
		line = get_next_line(fd);
	}
	return (nbr_of_line);
}

static int count_lines(const char *path)
{
	int fd;
	int nbr_of_lines;

	fd = open_cub(path);
	if (fd < 0)
		return (-1);
	nbr_of_lines = lines_in_cub(fd);
	close(fd);
	return (nbr_of_lines);
}

static char **allocate_cub_array(int nbr_of_lines, t_map *map)
{
	char **cub_array;

	cub_array = ft_calloc(nbr_of_lines + 1, sizeof(char *));
	if (!cub_array)
	{
		map->error = E_MALLOC;
		return (NULL);
	}
	return (cub_array);
}

static int fill_cub_array(char **cub_array, const char *path)
{
	int fd;
	int i;

	fd = open_cub(path);
	if (fd < 0)
		return (-1);
	i = 0;
	while ((cub_array[i] = get_next_line(fd)))
		i++;
	close(fd);
	return (0);
}

int cub_array(t_map *map)
{
	int		nbr_of_lines;

	nbr_of_lines = count_lines(map->path);
	if (nbr_of_lines < 0)
		return (E_FD);
	map->cub_array = allocate_cub_array(nbr_of_lines, map);
	if (!cub_array)
		return (E_MALLOC);
	if (fill_cub_array(map->cub_array, map->path) < 0)
		return (E_FD);
	return (SUCCESS);
}
