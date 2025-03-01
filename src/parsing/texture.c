/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:08:25 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/01 11:29:10 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	allocate_path(char **path_ref, char *src)
{
	int		i;
	char	*ref;
	size_t	length;

	i = 0;
	src += 2;
	ref = NULL;
	while (src[i] && src[i] == ' ')
		i++;
	if (src[i])
	{
		ref = &src[i];
		*path_ref = ft_strdup(ref);
		if (!*path_ref)
			return (-1);
		length = ft_strlen(*path_ref);
		if (length > 0 && (*path_ref)[length - 1] == '\n')
			(*path_ref)[length - 1] = '\0';
		return (0);
	}
	return (-1);
}

static int	set_path(t_map *map, char *src, const char *compass[])
{
	int	status;

	status = -1;
	if (ft_strncmp(src, compass[0], 2) == CMP_OK)
		status = allocate_path((char **)&map->no, src);
	if (ft_strncmp(src, compass[1], 2) == CMP_OK)
		status = allocate_path((char **)&map->so, src);
	if (ft_strncmp(src, compass[2], 2) == CMP_OK)
		status = allocate_path((char **)&map->we, src);
	if (ft_strncmp(src, compass[3], 2) == CMP_OK)
		status = allocate_path((char **)&map->ea, src);
	return (status);
}

static bool	parse_line(char *src, const char *compass[])
{
	char	**split;
	int		words;

	split = ft_split(src, ' ');
	if (!split)
		return (ft_printf_fd(2, ME_MALLOC), -1);
	words = split_metadata()->word_count;
	free_split(split);
	if (ft_strcmps(src, compass) != CMP_OK || ft_strlen(src) <= 2)
		return (false);
	if (src[2] != ' ' || words != 2)
		return (false);
	return (true);
}

// [] Need to make sure if must be in the strict order of NO SO WE EA
// [X] Need to make sure it ends with .xpm
bool	parse_texture(t_map *map)
{
	int			i;
	const char	*compass[] = {"NO", "SO", "WE", "EA", NULL};

	i = 0;
	while (map->cub_array[i] && i < 4)
	{
		if (parse_line(map->cub_array[i], compass))
		{
			if (set_path(map, map->cub_array[i], compass) < 0)
				return (ft_printf_fd(2, ME_MALLOC), true);
		}
		i++;
	}
	if (!map->ea || !map->no || !map->so || !map->we)
		return (ft_printf_fd(2, ME_MMA), true);
	return (false);
}
