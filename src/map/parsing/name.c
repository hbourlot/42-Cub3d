/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:02:45 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/06 16:00:58 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube3d.h"

static bool	invalid_cub_name(const char *path)
{
	int			len;
	const char	end[] = ".cub";
	const char	error[] = "Map doesn't end with '.cub'\n";

	len = (int)ft_strlen(path);
	if (len >= 4)
	{
		if (ft_strcmp(path + (len - 4), end))
			return (ft_printf_fd(2, error), false);
	}
	return (0);
}

static  bool xpm_end(const char *src)
{
	int			len;
	const char	end[] = ".xpm";

	len = (int)ft_strlen(src);
	if (len >= 4)
	{
		if (ft_strcmp(src + (len - 4), end))
			return (ft_printf_fd(2, ME_PAX), false);
	}
	return (true);
}

bool	invalid_file_name(t_map *map)
{
	if (invalid_cub_name(map->path))
		return (false);
	if (!xpm_end(map->ea) || !xpm_end(map->no)
		|| !xpm_end(map->so) || !xpm_end(map->we))
		return (true);
	return (false);
}
