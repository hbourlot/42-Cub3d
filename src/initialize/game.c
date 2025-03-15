/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:00:36 by hbourlot          #+#    #+#             */
/*   Updated: 2025/03/15 18:38:10 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// t_vec3 vec3_sub(t_vec3 a, t_vec3 b) {
//     t_vec3 result = {a.x - b.x, a.y - b.y, a.z - b.z};
//     return result;
// }

// double vec3_dot(t_vec3 a, t_vec3 b) {
//     return a.x * b.x + a.y * b.y + a.z * b.z;
// }

// t_vec3 vec3_unit(t_vec3 v) {
//     double length = sqrt(vec3_dot(v, v));
//     t_vec3 result = {v.x / length, v.y / length, v.z / length};
//     return result;
// }

// int hit_sphere(t_sphere sphere, t_ray r) {
//     t_vec3 oc = vec3_sub(sphere.center, r.origin);
//     double a = vec3_dot(r.direction, r.direction);
//     double b = -2.0 * vec3_dot(r.direction, oc);
//     double c = vec3_dot(oc, oc) - (sphere.radius * sphere.radius);
//     double discriminant = (b * b) - (4 * a * c);
//     return (discriminant >= 0);
// }

// t_color ray_color(t_ray r) {
//     t_sphere sphere = {{0, 0, -1}, 0.5};

//     if (hit_sphere(sphere, r))
//         return (t_color){1, 0, 0}; // Red if hit

//     t_vec3 unit_direction = vec3_unit(r.direction);
//     double a = 0.5 * (unit_direction.y + 1.0);

//     t_color white = {1.0, 1.0, 1.0};
//     t_color blue = {0.5, 0.7, 1.0};

//     return (t_color){
//         (1.0 - a) * white.r + a * blue.r,
//         (1.0 - a) * white.g + a * blue.g,
//         (1.0 - a) * white.b + a * blue.b
//     };
// }

// void	render(t_cube3d *game)
// {
// 	int	i;
// 	int j;
// 	t_ray	ray;
// 	t_color	color;

// 	t_vec3	origin ;
// 	origin = (t_vec3){0, 0, 0};
// 	t_vec3	lower_left_corner = {-2.0, -1.0, -1.0};
// 	t_vec3	horizontal = {4.0, 0.0, 0.0};
// 	t_vec3	vertical = {0.0, 2.0, 0.0};


// 	j = 0;
// 	while (j < MAP_HEIGHT)
// 	{
// 		i = 0;
// 		while (i < MAP_WIDTH)
// 		{
// 			double u = (double)i / (MAP_WIDTH - 1);
// 			double v = (double)j / (MAP_HEIGHT - 1);

// 			t_vec3 dir = {
// 				lower_left_corner.x + u * horizontal.x + v * vertical.x - origin.x,
// 				lower_left_corner.y + u * horizontal.y + v * vertical.y - origin.y,
// 				lower_left_corner.z + u * horizontal.z + v * vertical.z - origin.z
// 			};
// 			ray = (t_ray){origin, dir};
// 			color = ray_color(ray);
// 			int ir = (int)(255.999 * color.r);
// 			int ig = (int)(255.999 * color.g);
// 			int ib = (int)(255.999 * color.b);
// 			int pixel_color = (ir << 16) | (ig << 8) | ib;

// 			mlx_pixel_put(game->mlx_ptr, game->win_ptr, i, j, pixel_color);
// 			i++;
// 		}
// 		j++;
// 	}
// }


int	init_game(t_cube3d *game)
{

	if (init_window(game) < 0)
		return (-1);
	// render(game);
	draw_map2d(game);
	// draw_player2d(game);
	game_loop(game);
	return(0);
}
