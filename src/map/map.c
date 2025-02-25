/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:00:46 by hbourlot          #+#    #+#             */
/*   Updated: 2025/02/27 17:35:23 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// static int	check_cub_end(t_cube3d *data)
// {
// 	char		*path;
// 	int			len;
// 	const char	end[] = ".ber";
// 	const char	error[] = "Map doesn't end with '.ber'\n";

// 	path = data->map.path;
// 	len = (int)ft_strlen(path);
// 	if (len >= 4)
// 	{
// 		if (ft_strcmp(path + (len - 4), end))
// 			return (ft_printf_fd(2, error), 1);
// 	}
// 	return (0);
// }


int	open_cub(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perror("Error opening file"), fd);
	return (fd);
}