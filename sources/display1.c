/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 19:14:35 by qsebasti          #+#    #+#             */
/*   Updated: 2018/11/23 19:06:42 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"
#include <stdio.h>

static t_size	init_size(int width, int length)
{
	t_size size;

	size.width = width;
	size.length = length;
	return (size);
}

static t_point	init_point(int x, int y)
{
	t_point pt;

	pt.x = x;
	pt.y = y;
	return (pt);
}

static void		tab2(t_env *e)
{
	t_point	pt;
	t_size	small;
	int		marge;

	marge = 15;
	pt = init_point(marge, IMG_H / 2);
	small = init_size(WIN_W - IMG_W - 2 * marge, WIN_W - IMG_W - 2 * marge);
	draw_rect(RIGHT, pt, small, WHITE, e);
	insert_xpm(RIGHT, pt, "resources/little_circle_color_spectrum.xpm", e);
	pt = init_point(marge, IMG_H / 2 + WIN_W - IMG_W - 2 * marge  + marge);
	small = init_size(marge, WIN_W - IMG_W - 2 * marge);
	draw_rect(RIGHT, pt, small, WHITE, e);
}

void			tab(t_env *e)
{
	t_point	pt;
	t_size	small;
	int color;

	color = e->interface.onglet;
	pt = init_point(0, 0);
	small = init_size(30, (WIN_W - IMG_W) / 3);
	draw_rect(RIGHT, pt, small, GREY, e);
	pt = init_point((WIN_W - IMG_W) / 3 + 1, 0);
	small = init_size(30, (WIN_W - IMG_W) / 3);
	draw_rect(RIGHT, pt, small, GREY, e);
	pt = init_point(2 * ((WIN_W - IMG_W) / 3 + 1), 0);
	small = init_size(30, (WIN_W - IMG_W) / 3);
	draw_rect(RIGHT, pt, small, GREY, e);
	tab2(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img[RIGHT], IMG_W, 0);
	mlx_string_put(e->mlx, e->win, 827, 2, (color == 1 ? RED : BLACK), "1");
	mlx_string_put(e->mlx, e->win, 893, 2, (color == 2 ? RED : BLACK), "2");
	mlx_string_put(e->mlx, e->win, 959, 2, (color == 3 ? RED : BLACK), "3");
	mlx_destroy_image(e->mlx, e->img[RIGHT]);
}
