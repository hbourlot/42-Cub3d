/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:08:25 by hbourlot          #+#    #+#             */
/*   Updated: 2025/02/27 22:05:01 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube3d.h"


static int allocate_path(char **path_ref, char *src)
{
	int		i;
	char	*ref;

	i = 0;
	src += 2;
	while (src[i] && src[i] == ' ')
		i++;
	if (src[i])
	{
		ref = &src[i];
		*path_ref = ft_strdup(ref);
		if (!*path_ref)
			return (-1);
		return (0);
	}
	return (-1);
}

static int	set_path(t_map *map, char *src)
{
	const char *compass[] = {"NO", "SO", "WE", "EA", NULL};
	int			status;
	
	status = -1;
	if (ft_strncmp(src, compass[0], 2) == CMP_OK)
		status = allocate_path(&map->path_no, src);
	if (ft_strncmp(src, compass[1], 2) == CMP_OK)
		status = allocate_path(&map->path_so, src);
	if (ft_strncmp(src, compass[2], 2) == CMP_OK)
		status = allocate_path(&map->path_we, src);
	if (ft_strncmp(src, compass[3], 2) == CMP_OK)
		status = allocate_path(&map->path_ea, src);
	return (status);
}

int	parsing_texture(t_map *map, const char *compass[])
{
	int	i;
	const char *compass[] = {"NO", "SO", "WE", "EA", NULL};

	i = 0;
	while (map->cub_array[i] && i < 4)
	{
		if (ft_strcmps(map->cub_array[i], compass) == CMP_OK)
		{
			if (set_path(map, map->cub_array[i]))
				return (-1);
		}
		i++;
	}
	if (!map->path_ea || !map->path_no || !map->path_so || ! map->path_we)
		return -1;

	return	0;
}

