/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrix_z.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:02:47 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/11 17:06:09 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

t_matrix	rotation_matrix_z(float angle)
{
	t_matrix	result;
	float		rad;
	
	result = identify_matrix();
	rad = angle * (M_PI / 180.0f);
	result.m[0][0] = cos(rad);
	result.m[0][1] = -sin(rad);
	result.m[1][0] = sin(rad);
	result.m[1][1] = cos(rad);

	return (result);
}
