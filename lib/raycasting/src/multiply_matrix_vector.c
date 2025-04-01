/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix_vector.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:34:16 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/14 15:00:57 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	multiply_matrix_vector(float result[4], t_matrix m, float v[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		result[i] = m.m[i][0] * v[0] + m.m[i][1] * v[1] + m.m[i][2] * v[2]
			+ m.m[i][3] * v[3];
		i++;
	}
}