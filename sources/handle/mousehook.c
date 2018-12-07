/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:29:16 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/06 17:12:53 by qsebasti         ###   ########.fr       */
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

static void	ui_checker(int x, int y, t_env *e)
{
	if (x >= Z1_XS && x <= Z1_XE && y >= Z1_YS && y <= Z1_YE)
		e->interface.onglet = 1;
	else if (x >= Z2_XS && x <= Z2_XE && y >= Z2_YS && y <= Z2_YE)
		e->interface.onglet = 2;
	else if (x >= Z3_XS && x <= Z3_XE && y >= Z3_YS && y <= Z3_YE)
		e->interface.onglet = 3;
}

/*
**	MOUSEPRESS
**	Handle the pressed button, mouse pointer position at this moment
*/

int			mousepress(int button, int x, int y, t_env *e)
{
	e->mouse.button = button;
	e->mouse.x = x;
	e->mouse.y = y;
	ui_checker(x, y, e);
	ui1_spectrum(button, x, y, e);
	ui1_shade(button, x, y, e);
//	printf("%d %d\n", x, y);
	hud(e);
	return (0);
}

/*
**	MOURELEASE
**	Replace de mouse button state at 0, useful for long click needed features
*/

int			mouserelease(int button, int x, int y, t_env *e)
{
	e->mouse.button = 0;
	e->interface.shade.button = 0;
	e->interface.spectrum.button = 0;
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

/*
**	MOUSEMOVE
**	Save the mouse pointer position from the last movement
*/

int			mousemove(int x, int y, t_env *e)
{
	e->mouse.x = x;
	e->mouse.y = y;
	if (e->key[KEY_SPC] == 0)
		if (e->key[KEY_TAB])
		{
			e->cam->dir = rotate_y(e->cam->dir, x * M_PI / 8);
			e->cam->dir = rotate_x(e->cam->dir, y * M_PI / 8);
		}
	if (e->interface.shade.button == L_CLICK)
	{
		if (x < IMG_W + MARGE)
			e->interface.shade.x = MARGE;
		else if (x > WIN_W - MARGE)
			e->interface.shade.x = RIGHT_SPC - MARGE - 1;
		else
			e->interface.shade.x = x - IMG_W;
	}
	if (e->interface.spectrum.button == L_CLICK)
		ui1_spectrum(e->interface.spectrum.button, x, y, e);
	return (0);
}
