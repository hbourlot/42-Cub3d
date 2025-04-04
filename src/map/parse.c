/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:22:06 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/04 14:56:41 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int	parse_s_map(t_map *map)
{
	if (map->nbr_of_lines < 9)
		return (ft_printf_fd(2, ME_MINFO), -1);
	if (parse_texture(map))
		return (-1);
	if (parse_fc(map))
		return (-1);
	if (invalid_file_name(map))
		return (-1);
	if (parse_map(map))
		return (-1);
	return (0);
}
