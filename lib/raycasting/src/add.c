/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:10:15 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/11 16:11:37 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

t_vec3 add(t_vec3 a, t_vec3 b)
{
	t_vec3	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;

	return (result);
}