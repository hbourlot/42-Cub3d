/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:58:41 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/11 16:59:56 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

t_matrix	translation_matrix(float tx, float ty, float tz)
{
	t_matrix result;

	result = identify_matrix();
	result.m[0][3] = tx;
	result.m[1][3] = ty;
	result.m[2][3] = tz;

	return (result);
}