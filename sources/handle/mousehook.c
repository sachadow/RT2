/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 17:29:16 by qsebasti          #+#    #+#             */
/*   Updated: 2018/11/30 19:51:05 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keyboard.h"
#include "hud.h"
#include <stdio.h>

static void	ui_checker(int x, int y, t_env *e)
{
	if (x >= ZONE1_XS && x <= ZONE1_XE && y >= ZONE1_YS && y <= ZONE1_YE)
		e->interface.onglet = 1;
	else if (x >= ZONE2_XS && x <= ZONE2_XE && y >= ZONE2_YS && y <= ZONE2_YE)
		e->interface.onglet = 2;
	else if (x >= ZONE3_XS && x <= ZONE3_XE && y >= ZONE3_YS && y <= ZONE3_YE)
		e->interface.onglet = 3;
}

int			mousepress(int button, int x, int y, t_env *e)
{
	e->mouse.button = button;
	e->mouse.x = x;
	e->mouse.y = y;
	ui_checker(x, y, e);
	ui1_spectrum(x, y, e);
//	printf("%d %d\n", x, y);
	hud(e);
	return (0);
}

int			mouserelease(int button, int x, int y, t_env *e)
{
	e->mouse.button = 0;
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

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
	return (0);
}
