/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:23:50 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/11 18:15:30 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

t_vec3	normalize(t_vec3 v)
{
	float	mag;
	t_vec3	result;

	mag = magnitude(v);
	result = (t_vec3){v.x / mag, v.y / mag, v.z / mag};
	
	return (result);
}