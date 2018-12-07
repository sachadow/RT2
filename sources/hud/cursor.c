/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:04:25 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/04 21:17:25 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keyboard.h"
#include "hud.h"
#include <stdio.h>

void		cursor_shade(t_env *e)
{
	t_pix	pt;
	t_size	base;
	t_colo	color;

	if (e->interface.shade.x >= MARGE
			&& e->interface.shade.x < Z4_XE - IMG_W)
	{
		pt = init_point(e->interface.shade.x, e->interface.shade.y);
		e->interface.spec_shade.val = color_picker(RIGHT, pt, e);
		color = e->interface.spec_shade;
		if (e->interface.shade.x < (RIGHT_SPC) / 2) 
			color.val = WHITE;
		else
			color.val = BLACK;
		base = init_size(9, 5);
		draw_rev_tri(RIGHT, pt, base, color.val, e);
		pt = init_point(e->interface.shade.x, e->interface.shade.y + MARGE);
		draw_tri(RIGHT, pt, base, color.val, e);
		pt = init_point((RIGHT_SPC) / 2 - 2 * MARGE, Z4_YE + MARGE);
		base = init_size(MARGE * 4, MARGE * 2);
		draw_rect(RIGHT, pt, base, e->interface.spec_shade.val, e);
		frame(RIGHT, pt, base, GREY, e);
	}
}

void		cursor_spectrum(t_env *e)
{
	int i;
	int j;

	t_pix pt;
	j = -2;
	if (e->interface.spectrum.x > 0 && e->interface.spectrum.x < RIGHT_SPC
			&& e->interface.spectrum.y > 0 && e->interface.spectrum.y < IMG_H)
	{
		while (++j < 1)
		{
			i = -11;
			while (++i < 10)
			{
				pt.x = e->interface.spectrum.x + i;
				pt.y = e->interface.spectrum.y + j;
				if (i < -2 || i > 2)
					color_point(RIGHT, pt, WHITE, e);
				pt.x = e->interface.spectrum.x + j;
				pt.y = e->interface.spectrum.y + i;
				if (i < -2 || i > 2)
					color_point(RIGHT, pt, WHITE, e);
			}
		}
	}
}
