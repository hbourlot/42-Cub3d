/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:03:23 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/01 01:01:36 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	lines_in_cub(int fd)
{
	char	*line;
	int		nbr_of_line;

	nbr_of_line = 0;
	line = get_next_line(fd);
	while (line)
	{
		nbr_of_line++;
		free(line);
		line = get_next_line(fd);
	}
	return (nbr_of_line);
}

int	count_lines(const char *path)
{
	int	fd;
	int	nbr_of_lines;

	fd = open_cub(path);
	if (fd < 0)
		return (ft_printf_fd(2, ME_FD), -1);
	nbr_of_lines = lines_in_cub(fd);
	close(fd);
	return (nbr_of_lines);
}
