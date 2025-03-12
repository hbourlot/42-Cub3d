/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_cube3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:11:01 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/12 16:52:18 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cube3d.h"

int init_s_cube3d(t_cube3d **game, int argc, char *argv[])
{
	static t_cube3d data;
	static t_map	map;
	static t_img    sprites;
	
	ft_memset(&data, 0, sizeof(t_cube3d));
	*game = &data;
	(*game)->map = &map;
	(*game)->sprites = &sprites;
	data.map->path = argv[1];
	if (init_s_map(data.map) < 0)
		return (-1);
	printf("%s\n", map.ceiling);
	return (0);
}
