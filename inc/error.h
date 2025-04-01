/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 09:19:57 by hbourlot          #+#    #+#             */
/*   Updated: 2025/04/01 01:02:30 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "cub3d.h"

#define ME_MMA "Error: Map argument!\n"
#define ME_MALLOC "Error: Malloc!\n"
#define ME_MF "Error: mlx_init fail!\n"
#define ME_NW "Error: mlx_new_window fail!\n"
#define ME_IMP "Error: Invalid map path!\n"
#define ME_FD "Error: Opening file!\n"
#define ME_EM "Error: Map is empty!\n"
#define ME_PAX "Error: Parameter doesn't end with '.xpm'!\n"
#define ME_MINFO "Error: The map doesn't have all the necessary information!\n"

typedef enum s_status
{
	E_MALLOC = -10,
	E_FD,
	SUCCESS = 0,
}	t_status;