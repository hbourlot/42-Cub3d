/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_cub3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:11:01 by hbourlot          #+#    #+#             */
/*   Updated: 2025/05/13 23:17:59 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_screen	*init_s_screen(void)
{
	static t_screen	screen;

	return (&screen);
}

int	init_s_cube3d(t_cub3d **game, char *argv[])
{
	static t_cub3d	data;
	static t_map	map;
	static t_sprite	sprites;

	ft_memset(&data, 0, sizeof(t_cub3d));
	*game = &data;
	(*game)->map = &map;
	(*game)->sprites = &sprites;
	data.map->path = argv[1];
	data.mouse_on = true;
	if (init_s_map(data.map) < 0)
		return (-1);
	return (0);
}
