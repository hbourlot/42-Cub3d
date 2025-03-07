/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:35:51 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/06 14:39:19 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	direction;
}			t_ray;

typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
}			t_sphere;

typedef struct t_color
{
	double	r;
	double	g;
	double	b;
}			t_color;
