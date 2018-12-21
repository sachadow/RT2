/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:29:16 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/20 18:05:14 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keyboard.h"
#include "hud.h"
#include <stdio.h>

/*
**	UI_CHECKER
**	Check if the user click in 1 of the 3 tabulation zones
*/

static void	ui_checker(t_mouse m, t_env *e)
{
	t_pix	pt;

	if (e->itf.onglet == 1)
	{
		pt = init_point(M_IMG_H + (CIRCLE) / 2, SHAD1_YS);
		ui_spectrum(0, pt, m, e);
		pt.x = SHAD1_YE;
		ui_shade(0, pt, m, e);
	}
	if (e->itf.onglet == 2)
	{
		pt.x = 3 * MARGE + (RIGHT_SPC) / 2 - MARGE;
		pt.y = 3 * MARGE + RIGHT_SPC - MARGE;
		ui_spectrum(1, pt, m, e);
		pt.x = pt.y + MARGE;
		ui_shade(1, pt, m, e);
		pt = init_point(M_IMG_H + 35 + (RIGHT_SPC) / 2 - MARGE,
				M_IMG_H + 35 + RIGHT_SPC - MARGE);
		ui_spectrum(2, pt, m, e);
		pt.x = pt.y + MARGE;
		ui_shade(2, pt, m, e);
	}
	pick_item(m, e);
	ui1_zones(e->itf.onglet, m, e);
}

/*
**	MOUSEPRESS
**	Handle the pressed button, mouse pointer position at this moment
*/

int			mousepress(int button, int x, int y, t_env *e)
{
	t_mouse	mouse;

	mouse.button = button;
	mouse.x = x;
	mouse.y = y;
	if (x >= TAB1_XS && x <= TAB1_XE && y >= TAB1_YS && y <= TAB1_YE)
		e->itf.onglet = 1;
	else if (x >= TAB2_XS && x <= TAB2_XE && y >= TAB2_YS && y <= TAB2_YE)
		e->itf.onglet = 2;
	else if (x >= TAB3_XS && x <= TAB3_XE && y >= TAB3_YS && y <= TAB3_YE)
		e->itf.onglet = 3;
	ui_checker(mouse, e);
	printf("%d %d\n", x, y);
	hud(e);
	return (0);
}

/*
**	MOURELEASE
**	Replace de mouse button state at 0, useful for long click needed features
*/

int			mouserelease(int button, int x, int y, t_env *e)
{
	int i;

	i = -1;
	while (++i < 3)
	{
		e->itf.shade[i].button = 0;
		e->itf.spectrum[i].button = 0;
	}
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

/*
**	MOUSEMOVE
**	Save the mouse pointer position from the last movement
*/

static void	update_mouse(int nb, t_pix pt, t_pix coord, t_env *e)
{
	t_mouse	mouse;

	if (e->itf.shade[nb].button == L_CLICK)
	{
		if (pt.x < IMG_W + MARGE)
			e->itf.shade[nb].x = MARGE;
		else if (pt.x > WIN_W - MARGE)
			e->itf.shade[nb].x = RIGHT_SPC - MARGE - 1;
		else
			e->itf.shade[nb].x = pt.x - IMG_W;
	}
	if (e->itf.spectrum[nb].button == L_CLICK)
	{
		mouse.button = e->itf.spectrum[nb].button;
		mouse.x = pt.x;
		mouse.y = pt.y;
		ui_spectrum(nb, coord, mouse, e);
	}
}

int			mousemove(int x, int y, t_env *e)
{
	t_pix	pt;
	t_pix	coord;

	if (e->key[KEY_SPC] == 0)
		if (e->key[KEY_TAB])
		{
			e->cam->dir = rotate_y(e->cam->dir, x * M_PI / 8);
			e->cam->dir = rotate_x(e->cam->dir, y * M_PI / 8);
		}
	pt = init_point(x, y);
	coord = init_point(M_IMG_H + 85, SHAD1_YS);
	update_mouse(0, pt, coord, e);
	coord = init_point(3 * MARGE + (RIGHT_SPC) / 2 - MARGE,
			3 * MARGE + RIGHT_SPC - MARGE);
	update_mouse(1, pt, coord, e);
	coord = init_point(M_IMG_H + 35 + (RIGHT_SPC) / 2 - MARGE,
			M_IMG_H + 35 + RIGHT_SPC - MARGE);
	update_mouse(2, pt, coord, e);
	return (0);
}
