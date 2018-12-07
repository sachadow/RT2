/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:17:53 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/06 16:57:20 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"
#include <stdio.h>

t_size	init_size(int width, int length)
{
	t_size size;

	size.width = width;
	size.length = length;
	return (size);
}

t_pix	init_point(int x, int y)
{
	t_pix pt;

	pt.x = x;
	pt.y = y;
	return (pt);
}

static void		top_right(t_env *e)
{
	t_pix	pt;
	t_size	size;

	pt = init_point(0, 0);
	size = init_size((RIGHT_SPC) / 3, 2 * MARGE);
	draw_rect(RIGHT, pt, size, LIGHT_GREY, e);
	pt = init_point((RIGHT_SPC) / 3 + 1, 0);
	draw_rect(RIGHT, pt, size, LIGHT_GREY, e);
	pt = init_point(2 * ((RIGHT_SPC) / 3 + 1), 0);
	draw_rect(RIGHT, pt, size, LIGHT_GREY, e);
}

static void		ui_writting(t_env *e)
{
	int color;

	color = e->interface.onglet;
	mlx_string_put(e->mlx, e->win, 829, 2, (color == 1 ? RED : BLACK), "1");
	mlx_string_put(e->mlx, e->win, 895, 2, (color == 2 ? RED : BLACK), "2");
	mlx_string_put(e->mlx, e->win, 961, 2, (color == 3 ? RED : BLACK), "3");
	color_val(e);
}

void			tab(t_env *e)
{
	top_right(e);
	if (e->interface.onglet == 1)
		ui1(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img[RIGHT], IMG_W, 0);
	ui_writting(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img[BOTTOM], 0, IMG_H);
	mlx_destroy_image(e->mlx, e->img[RIGHT]);
	mlx_destroy_image(e->mlx, e->img[BOTTOM]);
}
