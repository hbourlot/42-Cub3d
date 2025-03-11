/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbourlot <hbourlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:35:51 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/11 18:51:24 by hbourlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <math.h>

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

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}			t_color;

typedef	struct s_matrix
{
	float	m[4][4];
}			t_matrix;


t_vec3		normalize(t_vec3 v);
t_vec3		add(t_vec3 a, t_vec3 b);
t_vec3		cross(t_vec3 a, t_vec3 b);
t_vec3		subtract(t_vec3 a, t_vec3 b);

float		magnitude(t_vec3 v);
float		dot(t_vec3 a, t_vec3 b);

void		multiply_matrix_vector(float result[4], t_matrix m, float v[4]);
t_matrix	identify_matrix();
t_matrix	translation_matrix(float tx, float ty, float tz);
t_matrix	rotation_matrix_z(float angle);
