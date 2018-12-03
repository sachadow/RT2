/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 18:37:14 by qsebasti          #+#    #+#             */
/*   Updated: 2018/11/23 19:22:15 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"
#include <stdio.h>

static int	get_color(int x, int y, t_img img)
{
	int color;

	if (x < img.w && x >= 0 && y < img.h && y >= 0)
	{
		color = *(int *)&img.pixel_img[x * (img.bpp / 8) + y * img.s_line];
		return (color);
	}
	return (0);
}

void		insert_xpm(int num, t_point pt, char *name, t_env *e)
{
	t_img	img;
	int		i;
	int		j;
	t_colo	col;
	t_point	tmp;

	if (!(img.img = mlx_xpm_file_to_image(e->mlx, name, &img.w, &img.h))
	|| !(img.pixel_img = (unsigned char*)mlx_get_data_addr(img.img, &img.bpp,
			&img.s_line, &img.ed)))
		ft_printerror("Error mlx");
	j = -1;
	while (++j < img.h)
	{
		i = -1;
		while (++i < img.w)
		{
			tmp.x = i + pt.x;
			tmp.y = j + pt.y;
			col.val = get_color(i, j, img);
			if (col.argb[R] > 180 && col.argb[G] > 180 && col.argb[B] > 180) 
				col.val = BLACK;
			color_point(num, tmp, col.val, e);
		}
	}
}

void		color_point(int num, t_point pt, int color, t_env *e)
{
	int width;
	int height;

	width = 0;
	height = 0;
	if (num == RIGHT)
	{
		width = WIN_W - IMG_W;
		height = IMG_H;
	}
	else if (num == BOTTOM)
	{
		width = WIN_W;
		height = WIN_H - IMG_H;
	}
	if (pt.x < width && pt.x >= 0 && pt.y < height && pt.y >= 0)
		*(int *)&e->pixel_img[num][(int)pt.x * (e->bpp[num] / 8) + (int)pt.y *
			e->s_line[num]] = color;
}

void		draw_rect(int num, t_point pt, t_size rect, int color, t_env *e)
{
	t_point	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < rect.width)
	{
		j = -1;
		while (++j < rect.length)
		{
			tmp.y = pt.y + i;
			tmp.x = pt.x + j;
			color_point(num, tmp, color, e);
		}
	}
}
