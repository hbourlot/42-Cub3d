/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:28:50 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/28 22:28:15 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	allocate_fc(int *ptr_ref, char *src)
{
	char	**split_addr;
	char	**rgb;

	split_addr = ft_split(src, ' ');
	if (!split_addr)
		return (-1);
	rgb = ft_split(split_addr[1], ',');
	if (!rgb)
		return (free_split(split_addr), -1);
	free_split(split_addr);
	*ptr_ref = create_rgb(0, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free_split(rgb);
	return (SUCCESS);
}

static int	set_fc(t_sprite *sprite, char *src)
{
	char	c;
	int		status;

	status = -1;
	c = src[0];
	if ((c == 'F' && sprite->floor) || (c == 'C' && sprite->ceiling))
		return (ft_printf_fd(2, ME_MMA), status);
	if (c == 'F')
		status = allocate_fc(&sprite->floor, src);
	if (c == 'C')
		status = allocate_fc(&sprite->ceiling, src);
	if (status < 0)
		ft_printf_fd(2, ME_MALLOC);
	return (status);
}

static bool	parse_color(char *color)
{
	char	**split;
	int		i;
	int		j;

	i = 0;
	split = ft_split(color, ',');
	if (split_metadata()->word_count != 3)
		return (free_split(split), false);
	while (i < 3)
	{
		j = -1;
		if (ft_strlen(split[i]) > 3)
			return (free_split(split), false);
		while (split[i][++j])
		{
			truncate_character(split[i], '\n');
			if (!ft_isdigit(split[i][j]))
				return (free_split(split), false);
		}
		j = ft_atoi(split[i]);
		if (j < 0 || j > 255)
			return (free_split(split), false);
		i++;
	}
	return (free_split(split), true);
}

static bool	parse_line(char *src)
{
	char	**split;
	int		words;
	char	c;

	c = src[0];
	split = ft_split(src, ' ');
	if (!split)
		return (ft_printf_fd(2, ME_MALLOC), -1);
	words = split_metadata()->word_count;
	if (ft_strlen(split[0]) != 1 || words != 2)
		return (free_split(split), false);
	if (!parse_color(split[1]))
		return (free_split(split), false);
	free_split(split);
	if (c != 'F' && c != 'C')
		return (false);
	return (true);
}

//* [x] Need to make sure if wall texture can be mixed with floor and ceiling
void	init_fc(t_map *map, t_sprite *sprite)
{
	int		i;
	char	c;

	i = 0;
	while (map->cub_array[i])
	{
		c = map->cub_array[i][0];
		if (c == '1' || c == '2' || c == '\t' || c == ' ')
			break ;
		if (parse_line(map->cub_array[i]))
		{
			if (set_fc(sprite, map->cub_array[i]) < 0)
				free_game(1);
			ft_memset(map->cub_array[i], 0, ft_strlen(map->cub_array[i]));
		}
		++i;
	}
	if (!sprite->ceiling || !sprite->floor)
		return (ft_printf_fd(2, ME_MMA), free_game(1));
}
