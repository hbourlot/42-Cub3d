

#include "cub3d.h"

void	render_walls(t_cub3d *game, t_raycast *ray, t_img *tex)
{
	int		x;
	int		y;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
	int		color;

	tex_x = (int)(ray->wall_hit * (double)tex->width);
	if ((ray->dda.hitside == 0 && ray->dda.dir_x < 0) || (ray->dda.hitside == 1
			&& ray->dda.dir_y > 0))
		tex_x = tex->width - tex_x - 1;
	step = (double)tex->height / ray->wall_height;
	tex_pos = 0;
	if (ray->wall_start < 0)
		tex_pos = -ray->wall_start * step;
	x = ray->x_start;
	y = 0;
	while (y < ray->wall_height)
	{
		ray->screen_y = ray->wall_start + y;
		if (ray->screen_y >= 0 && ray->screen_y < SCREEN_HEIGHT)
		{
			tex_y = (int)tex_pos & (tex->height - 1);
			color = get_texture_color(tex, tex_x, tex_y);
			my_mlx_pixel_put(game, x, ray->screen_y, color);
		}
		tex_pos += step;
		y++;
	}
}

void	cast_render_raycast(t_cub3d *game)
{
	int			i;
	t_img		*tex;
	t_raycast	ray;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		ray.alpha = FOV / 2 - FOV / SCREEN_WIDTH * i;
		ray.ray_angle = game->player.angle + ray.alpha;
		dda(game, &ray, game->player.x, game->player.y);
		ray.perp_dist = ray.dist * cos(ray.alpha);
		ray.wall_height = (int)(WALL_SIZE * SCREEN_HEIGHT / ray.perp_dist);
		ray.wall_start = SCREEN_HEIGHT / 2 - ray.wall_height / 2;
		ray.x_start = i;
		tex = get_texture(game, &ray);
		render_walls(game, &ray, tex);
		i++;
	}
}


// t_raycast cast_ray(t_cub3d *game, float x, float y, float angle)
// {
//     t_raycast ray;
//     t_dda *d;
//     int hit = 0;

//     ray.dda = (t_dda){0};
//     d = &ray.dda;
//     d->grid_int = game->map->map_world;
//     d->grid_x = (int)x;
//     d->grid_y = (int)y;
//     d->initial_x = x;
//     d->initial_y = y;
//     d->dir_x = cos(angle);
//     d->dir_y = sin(angle);

//     float delta_dist_x = fabs(1.0 / d->dir_x);
//     float delta_dist_y = fabs(1.0 / d->dir_y);
//     d->step_x = (d->dir_x < 0) ? -1 : 1;
//     d->step_y = (d->dir_y < 0) ? -1 : 1;
//     d->sx = (d->dir_x < 0) ? (x - d->grid_x) * delta_dist_x : (d->grid_x + 1.0 - x) * delta_dist_x;
//     d->sy = (d->dir_y < 0) ? (y - d->grid_y) * delta_dist_y : (d->grid_y + 1.0 - y) * delta_dist_y;

//     // Bucle principal de raycasting
//     while (!hit)
//     {
//         if (d->sx < d->sy)
//         {
//             d->sx += delta_dist_x;
//             d->grid_x += d->step_x;
//             d->hitside = 0;
//         }
//         else
//         {
//             d->sy += delta_dist_y;
//             d->grid_y += d->step_y;
//             d->hitside = 1;
//         }

//         // Asegura que no salga del mapa
//         if (d->grid_x < 0 || d->grid_x >= game->map->width || d->grid_y < 0 || d->grid_y >= game->map->height)
//             break;

//         // Detecta colisiones con paredes
//         if (d->grid_int[d->grid_y][d->grid_x] > 0)
//             hit = 1;
//     }

//     // Calcula la distancia perpendicular
//     ray.perp_dist = (d->hitside == 0)
//                     ? (d->grid_x - x + (1 - d->step_x) / 2) / d->dir_x
//                     : (d->grid_y - y + (1 - d->step_y) / 2) / d->dir_y;

//     // Imprime datos de depuración
//     printf("Ray (%d,%d) -> perp_dist: %f, angle: %f\n", d->grid_x, d->grid_y, ray.perp_dist, angle);

//     ray.dda = *d;

//     // Coordenada de impacto en la pared (para textura)
//     if (d->hitside == 0)
//         ray.wall_hit = y + ray.perp_dist * d->dir_y;
//     else
//         ray.wall_hit = x + ray.perp_dist * d->dir_x;

//     ray.wall_hit -= floor(ray.wall_hit);
//     return (ray);
// }


// int darken_color(int color)
// {
// 	int r = ((color >> 16) & 0xFF) * 0.6;
// 	int g = ((color >> 8) & 0xFF) * 0.6;
// 	int b = (color & 0xFF) * 0.6;
// 	return (r << 16) | (g << 8) | b;
// }

// void cast_render_raycast(t_cub3d *game)
// {
//     for (int x = 0; x < SCREEN_WIDTH; x++)
//     {
//         // Cálculo del ángulo del rayo
//         float camera_x = 2 * x / (float)SCREEN_WIDTH - 1;
//         float ray_angle = game->player.angle + camera_x * (FOV / 2);

//         // Dispara el rayo
//         t_raycast ray = cast_ray(game, game->player.x / TILE_SIZE, game->player.y / TILE_SIZE, ray_angle);

//         // Calcula la distancia corregida
//         float corrected_dist = ray.perp_dist * cos(ray_angle - game->player.angle);

//         // Calcula la altura de la línea del rayo
//         int line_height = (int)(SCREEN_HEIGHT / corrected_dist);
//         int draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
//         int draw_end = line_height / 2 + SCREEN_HEIGHT / 2;

//         draw_start = (draw_start < 0) ? 0 : draw_start;
//         draw_end = (draw_end >= SCREEN_HEIGHT) ? SCREEN_HEIGHT - 1 : draw_end;

//         // Usa un color constante para probar
//         int color = create_rgb(0, 123, 123, 123);

//         // Dibuja la línea vertical en la pantalla para cada rayo
//         for (int y = draw_start; y < draw_end; y++)
//         {
//             mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, color);
//         }

//         // Depuración: imprime el ángulo y la distancia de cada rayo
//         printf("Ray %d: angle = %f, perp_dist = %f, corrected_dist = %f, line_height = %d\n",
//                x, ray_angle, ray.perp_dist, corrected_dist, line_height);
//     }
// }







