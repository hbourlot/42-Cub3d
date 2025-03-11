/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:56:59 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/11 17:00:26 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

t_matrix	identify_matrix()
{
	t_matrix	result;
	int			i;

	i = 0;
	result = (t_matrix){0};
	while (i < 4)
	{
		result.m[i][i] = 1.0f;
		i++;
	}
	return (result);
}