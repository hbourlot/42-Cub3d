/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joralves <joralves@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 01:01:46 by joralves          #+#    #+#             */
/*   Updated: 2025/04/17 01:05:20 by joralves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	clear_main_img(t_cub3d *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < S_WIDTH)
	{
		y = 0;
		while (y < S_HEIGHT)
		{
			if (y < S_HEIGHT / 2)
				put_pixel_img(&game->main_img, x, y, 0x4B4B4B);
			if (y > S_HEIGHT / 2 && y < S_HEIGHT)
				put_pixel_img(&game->main_img, x, y, 0x2F2F2F);
			y++;
		}
		x++;
	}
}

void	put_pixel_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0)
		return ;
	if (x >= img->width || y >= img->height)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
