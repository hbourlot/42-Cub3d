/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:08:25 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/20 17:30:37 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static int set_path(t_map *map, char *line, const char *compass[])
{
	int			i;
	const char **paths[4] = {&map->no, &map->so, &map->we, &map->ea};
	int			status;
	i = 0;
	
	status = 0;
	while(i < 4)
	{
		if (ft_strncmp(line, compass[i], 2) == CMP_OK)
		{
			if (*paths[i])
				return (ft_printf_fd(2, ME_MMA) ,-1);
			status = allocate_path((char **)paths[i], line);
			if (status == -1)
				return (ft_printf_fd(2, ME_MALLOC), -1);
			break;
		}
		i++;
	}
	return (status);
}

static bool	parse_line(char *src, const char *compass[])
{
	char	**split;
	int		words;
	const char *FC[] = {"F", "C", NULL};

	if (ft_strcmps(src, FC) == CMP_OK)
		return (false);
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

//* [] Still got to check it there's './'
//* [X] Need to make sure if must be in the strict order of NO SO WE EA
//* [X] Need to make sure it ends with .xpm
bool	parse_texture(t_map *map)
{
	int			i;
	const char	*compass[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	char		c;
	
	i = 0;
	while (map->cub_array[i])
	{
		c = map->cub_array[i][0];
		if (c == '1' || c == '2' || c == '\t' || c == ' ')
			break ;
		if (parse_line(map->cub_array[i], compass))
		{
			if (set_path(map, map->cub_array[i], compass) < 0)
				return (true);
			ft_memset(map->cub_array[i], 0, ft_strlen(map->cub_array[i]));
		}
		i++;
	}
	if (!map->ea || !map->no || !map->so || !map->we)
		return (ft_printf_fd(2, ME_MMA), true);
	return (false);
}
