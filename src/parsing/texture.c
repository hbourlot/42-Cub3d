/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:08:25 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/01 08:51:20 by hbourlot         ###   ########.fr       */
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

static int	set_path(t_map *map, char *src, const char *compass[])
{
	int				status;
	
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
	char		**split;
	int			words;
	
	split = ft_split(src, ' ');
	if (!split)
		return (ft_printf_fd(2, ME_MALLOC), -1);
	words = split_metadata()->word_count;
	if (ft_strcmps(src, compass) != CMP_OK || ft_strlen(src) <= 2)
		return (free_split(split), false);
	if (src[2] != ' ' || words != 2)
		return (free_split(split), false);
	return (free_split(split), true);
}

int	parse_texture(t_map *map)
{
	int			i;
	const char 	*compass[] = {"NO", "SO", "WE", "EA", NULL};
	
	i = 0;
	while (map->cub_array[i] && i < 4)
	{
		if (parse_line(map->cub_array[i], compass))
		{
			if (set_path(map, map->cub_array[i], compass) < 0)
				return (ft_printf_fd(2, ME_MALLOC), -1);
		}
		i++;
	}
	if (!map->ea || !map->no || !map->so || ! map->we)
		return (ft_printf_fd(2, ME_MMA), -1);
	return	(SUCCESS);
}
