/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:19:26 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/03 16:30:16 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"
#include <stdio.h>

static int	color_smooth(t_colo start, t_colo end, double k)
{
	int		i;
	t_colo	ret;

	i = -1;
	while (++i < 4)
		ret.argb[i] = start.argb[i] + (end.argb[i] - start.argb[i]) * k;
	return (ret.val);
}

static void	shade_rect(int tab[2], t_pix pt, t_size size, t_env *e)
{
	int		i;
	int		j;
	t_pix	tmp;
	t_colo	start;
	t_colo	end;

	start.val = tab[0];
	end.val = tab[1];
	i = -1;
	while (++i < size.width)
	{
		j = -1;
		while (++j < size.length)
		{
			tmp.x = pt.x + j;
			tmp.y = pt.y + i;
			color_point(RIGHT, tmp,
			color_smooth(start, end, j / (double)(size.length)), e);
		}
	}
}

void		ui1_spectrum(int x, int y, t_env *e)
{
	int a;
	int b;

	a = IMG_W + (RIGHT_SPC) / 2;
	b = M_IMG_H + 85;
	if ((x - a) * (x - a) + (y - b) * (y - b) <= 85 * 85)
	{
		e->interface.spectrum.x = x - IMG_W;
		e->interface.spectrum.y = y;
		e->interface.spec.val = color_picker(RIGHT, e->interface.spectrum, e);
	}
}

void		ui1(t_env *e)
{
	t_pix	pt;
	t_size	size;
	int		tab[2];
	int		marge;

	marge = 15;
	pt = init_point(marge, M_IMG_H);
//	size = init_size(RIGHT_SPC - 2 * marge, RIGHT_SPC - 2 * marge);
//	draw_rect(RIGHT, pt, size, WHITE, e);
	insert_xpm(RIGHT, pt, "resources/little_color_wheel.xpm", e);
	pt = init_point(marge, M_IMG_H + RIGHT_SPC - 2 * marge + marge);
	size = init_size(marge, (RIGHT_SPC - 2 * marge) / 2);
	tab[0] = BLACK;
	tab[1] = e->interface.spec.val;
	shade_rect(tab, pt, size, e);
//	draw_rect(RIGHT, pt, size, RED, e);
	pt = init_point((RIGHT_SPC - 2 * marge) / 2 + marge, M_IMG_H + RIGHT_SPC
	- 2 * marge + marge);
	size = init_size(marge, (RIGHT_SPC - 2 * marge) / 2);
	tab[0] = e->interface.spec.val;
	tab[1] = WHITE;
	shade_rect(tab, pt, size, e);
//	draw_rect(RIGHT, pt, size, BLUE, e);
	cursor_spectrum(e);
/*	int x;
	pt = init_point(0, IMG_H - 1);
	for (x = -1; x < RIGHT_SPC ; ++x)
	{
		pt.x = 0 + x;
		color_point(RIGHT, pt, WHITE, e);
	}
	pt = init_point((RIGHT_SPC) / 2, 0);
	for (x = -1; x < IMG_H ; ++x)
	{
		pt.y = 0 + x;
		color_point(RIGHT, pt, WHITE, e);
	}
	pt = init_point(0, M_IMG_H + 85);
	for (x = -1; x < IMG_H ; ++x)
	{
		pt.x = 0 + x;
		color_point(RIGHT, pt, WHITE, e);
		if (pt.x == (RIGHT_SPC) / 2)
			color_point(RIGHT, pt, BLACK, e);
	}*/
}
