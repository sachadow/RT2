/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:19:26 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/06 17:14:19 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"
#include <stdio.h>

void		ui1_shade(int button, int x, int y, t_env *e)
{
	t_pix	pt;

	if (x > Z4_XS && x < Z4_XE && y > Z4_YS && y < Z4_YE)
	{
		e->interface.shade.button = button;
		e->interface.shade.x = x - IMG_W;
		e->interface.shade.y = Z4_YS;
		pt = init_point(e->interface.spectrum.x, e->interface.spectrum.y);
		e->interface.spec_shade.val = color_picker(RIGHT, pt, e);
	}
}

int			ui1_spectrum(int button, int x, int y, t_env *e)
{
	int		a;
	int		b;
	t_pix	pt;

	a = IMG_W + (RIGHT_SPC) / 2;
	b = M_IMG_H + 85;
	if ((x - a) * (x - a) + (y - b) * (y - b) <= 85 * 85)
	{
		e->interface.spectrum.x = x - IMG_W;
		e->interface.spectrum.y = y;
		e->interface.spectrum.button = button;
		pt.x = x - IMG_W;
		pt.y = y;
		e->interface.spec.val = color_picker(RIGHT, pt, e);
		e->interface.shade.x = (RIGHT_SPC) / 2;
		e->interface.shade.y = Z4_YS;
		if (e->interface.spec.val != WHITE)
			e->interface.spec_shade.val = e->interface.spec.val;
		return (1);
	}
	return (0);
}

void	color_val(t_env *e)
{
	char *s;

	s = ft_itoa((int)(e->interface.spec_shade.argb[R]));
	mlx_string_put(e->mlx, e->win, IMG_W, IMG_H - 45, WHITE, "R:");
	mlx_string_put(e->mlx, e->win, IMG_W + 30, IMG_H - 45, WHITE, s);
	free(s);
	s = ft_itoa((int)(e->interface.spec_shade.argb[G]));
	mlx_string_put(e->mlx, e->win, IMG_W + (RIGHT_SPC) / 3, IMG_H - 45, WHITE,
	"G:");
	mlx_string_put(e->mlx, e->win, IMG_W + 30 + (RIGHT_SPC) / 3, IMG_H - 45,
	WHITE, s);
	free(s);
	s = ft_itoa((int)(e->interface.spec_shade.argb[B]));
	mlx_string_put(e->mlx, e->win, IMG_W +  2 * (RIGHT_SPC) / 3, IMG_H - 45,
	WHITE, "B:");
	mlx_string_put(e->mlx, e->win, IMG_W + 30 +  2 * (RIGHT_SPC) / 3,
	IMG_H - 45, WHITE, s);
	free(s);
}

void		ui1(t_env *e)
{
	t_pix	pt;

	pt = init_point(MARGE, M_IMG_H);
	insert_xpm(RIGHT, pt, "resources/little-color-wheel.xpm", e);
	shade_bar(e);
	cursor_spectrum(e);
	cursor_shade(e);
	ui1_bottom(e);
	int x;
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
	}
	pt = init_point((RIGHT_SPC) / 3, 0);
	for (x = -1; x < IMG_H ; ++x)
	{
		pt.y = 0 + x;
		color_point(RIGHT, pt, WHITE, e);
	}
	pt = init_point(2 * ((RIGHT_SPC) / 3) + 1, 0);
	for (x = -1; x < IMG_H ; ++x)
	{
		pt.y = 0 + x;
		color_point(RIGHT, pt, WHITE, e);
	}
}
