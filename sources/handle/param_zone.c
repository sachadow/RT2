/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_zone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:29:27 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/10 20:29:41 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

static const int	g_param_x = WIN_W / 8;
static const int	g_param_ys = IMG_H + BOTTOM_SPC / 6;
static const int	g_param_ye = IMG_H + 5 * BOTTOM_SPC / 6;

void		param_zone(t_mouse m, t_env *e)
{
	if (m.x >= g_param_x - 5 && m.x < g_param_x + 5 && m.y >= g_param_ys
			&& m.y < g_param_ye)
	{
		e->itf.mat.reflection = (double)pos_to_int(m.y, 0, 1000) / 1000.0f;
		ft_putendl("ok 1");
	}
	if (m.x >= 2 * g_param_x - 5 && m.x < 2 * g_param_x + 5
			&& m.y >= g_param_ys && m.y < g_param_ye)
	{
		e->itf.mat.transparency = (double)pos_to_int(m.y, 0, 1000) / 1000.0f;
		ft_putendl("ok 2");
	}
	if (m.x >= 3 * g_param_x - 5 && m.x < 3 * g_param_x + 5
			&& m.y >= g_param_ys && m.y < g_param_ye)
	{
		e->itf.mat.specvalue = (double)pos_to_int(m.y, 0, 1000);
		ft_putendl("ok 3");
	}
	if (m.x >= 4 * g_param_x - 5 && m.x < 4 * g_param_x + 5
			&& m.y >= g_param_ys && m.y < g_param_ye)
	{
		e->itf.mat.specpower = (double)pos_to_int(m.y, 1, 1000);
		ft_putnbr(e->itf.mat.specpower);
		ft_putendl("ok 4");
	}
	if (m.x >= 5 * g_param_x - 5 && m.x < 5 * g_param_x + 5
			&& m.y >= g_param_ys && m.y < g_param_ye)
	{
		e->itf.mat.n = (double)pos_to_int(m.y, 0, 5000) / 1000.0f;
		ft_putendl("ok 5");
	}
	if (m.x >= 6 * g_param_x - 5 && m.x < 6 * g_param_x + 5
			&& m.y >= g_param_ys && m.y < g_param_ye)
	{
		e->itf.mat.bump = (double)pos_to_int(m.y, 0, 1000) / 1000.0f;
		ft_putendl("ok 6");
	}
	if (m.x >= 7 * g_param_x - 5 && m.x < 7 * g_param_x + 5
			&& m.y >= g_param_ys && m.y < g_param_ye)
	{
		e->itf.mat.scale = (double)pos_to_int(m.y, 1, 1000);
		ft_putendl("ok 7");
	}
	ui3_param(e);
}
