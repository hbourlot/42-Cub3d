/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s_dda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:20:20 by hbourlot          #+#    #+#             */
/*   Updated: 2025/05/15 20:20:43 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_s_dda_aux(t_dda *dda, double x, double y)
{
	if (dda->dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - x) * dda->delta_dist_x;
	}
	if (dda->dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - y) * dda->delta_dist_y;
	}
}

void	init_s_dda(t_dda *dda, double x, double y, double angle)
{
	dda->dir_x = cos(angle);
	dda->dir_y = -sin(angle);
	dda->map_x = (int)x;
	dda->map_y = (int)y;
	dda->delta_dist_x = fabs(1.0 / dda->dir_x);
	dda->delta_dist_y = fabs(1.0 / dda->dir_y);
	init_s_dda_aux(dda, x, y);
};
