#include "cub3d.h"

// t_img	*get_texture(t_cub3d *game, t_raycast *raycast)
// {
// 	t_img	*tex;

// 	if (raycast->dda.hitside == 0)
// 	{
// 		// Corregido: usamos EA si dir_x > 0 (este), WE si dir_x < 0 (oeste)
// 		if (raycast->dda.dir_x > 0)
// 			tex = game->sprites->ea;
// 		else
// 			tex = game->sprites->we;
// 	}
// 	else
// 	{
// 		// Norte (dir_y > 0) y Sur (dir_y < 0)
// 		if (raycast->dda.dir_y > 0)
// 			tex = game->sprites->no;
// 		else
// 			tex = game->sprites->so;
// 	}
// 	return (tex);
// }

t_img	*get_texture2(t_cub3d *game, t_ray *ray)
{
	t_img	*tex;

	if (ray->tex_num == 0)
		tex=game->sprites->so;
	if (ray->tex_num == 1)
		tex=game->sprites->ea;
	if (ray->tex_num == 2)
		tex=game->sprites->we;
	if (ray->tex_num == 3)
		tex=game->sprites->no;
	return (tex);
}

int	get_texture_color(t_img *tex, int x, int y)
{
	int color;

	if (x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0x000000);

	color = *(int *)(tex->addr + (y * tex->size_line) + (x * (tex->bpp / 8)));
	return (color);
}
