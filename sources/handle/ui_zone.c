/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_zone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 21:51:34 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/10 20:04:14 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

static const int	g_apply_xs = IMG_W + MARGE;
static const int	g_apply_xe = WIN_W - MARGE;
static const int	g_apply_ys = 2 * M_IMG_H / 3;
static const int	g_apply_ye = 2 * M_IMG_H / 3 + 100;

static const int	g_alias0_xs = IMG_W + WIN_W / 7 / 4 - 14;
static const int	g_alias0_xe = IMG_W + RIGHT_SPC / 3;
static const int	g_alias1_xe = IMG_W + 2 * RIGHT_SPC / 3 + 1;
static const int	g_alias2_xe = g_alias0_xs + 159;
static const int	g_alias_ys = IMG_H + 5 * BOTTOM_SPC / 8 + 9;
static const int	g_alias_ye = IMG_H + 5 * BOTTOM_SPC / 8 + 59;

static void	ui_texture(t_mouse m, t_env *e)
{
	if (m.x >= g_text1_xs && m.x < g_text1_xe && m.y >= g_text1_ys
			&& m.y < g_text1_ye)
		e->itf.nb_texture = (e->itf.nb_texture == 1 ? 0 : 1);
	if (m.x >= g_text2_xs && m.x < g_text2_xe && m.y >= g_text1_ys
			&& m.y < g_text1_ye)
		e->itf.nb_texture = (e->itf.nb_texture == 2 ? 0 : 2);
	if (m.x >= g_text1_xs && m.x < g_text1_xe && m.y >= g_text2_ys
			&& m.y < g_text2_ye)
		e->itf.nb_texture = (e->itf.nb_texture == 3 ? 0 : 3);
	if (m.x >= g_text2_xs && m.x < g_text2_xe && m.y >= g_text2_ys
			&& m.y < g_text2_ye)
		e->itf.nb_texture = (e->itf.nb_texture == 4 ? 0 : 4);
	if (m.x >= UNIF_XS && m.x < UNIF_XE && m.y >= UNIF_YS && m.y < UNIF_YE)
		ft_putendl("unif");
}

static void	filters(t_mouse m, t_env *e)
{
	if (m.x >= g_filter2_xs && m.x < g_filter2_xs + 100 && m.y >= g_filter1_ys
			&& m.y < g_filter1_ys + 60)
		e->filter = (e->filter == SEPIA ? 0 : SEPIA);
	if (m.x >= g_filter3_xs && m.x < g_filter3_xs + 100 && m.y >= g_filter1_ys
			&& m.y < g_filter1_ys + 60)
		e->filter = (e->filter == GREYSCALE ? 0 : GREYSCALE);
	if (m.x >= g_filter1_xs && m.x < g_filter1_xs + 100 && m.y >= g_filter2_ys
			&& m.y < g_filter2_ys + 60)
		e->filter = (e->filter == SATURATE ? 0 : SATURATE);
	if (m.x >= g_filter2_xs && m.x < g_filter2_xs + 100 && m.y >= g_filter2_ys
			&& m.y < g_filter2_ys + 60)
		e->filter = (e->filter == REVERSE ? 0 : REVERSE);
	if (m.x >= g_filter3_xs && m.x < g_filter3_xs + 100 && m.y >= g_filter2_ys
			&& m.y < g_filter2_ys + 60)
		e->cartoon = (e->cartoon == 1 ? 0 : 1);
	if (m.x >= g_alias0_xs && m.x < g_alias0_xe && m.y >= g_alias_ys
			&& m.y < g_alias_ye)
		e->antialiasing = 0;
	if (m.x >= g_alias0_xe + 1 && m.x < g_alias1_xe && m.y >= g_alias_ys
			&& m.y < g_alias_ye)
		e->antialiasing = 1;
	if (m.x >= g_alias1_xe + 1 && m.x < g_alias2_xe && m.y >= g_alias_ys
			&& m.y < g_alias_ye)
		e->antialiasing = 2;
}

void		ui_zones(int nb, t_mouse mouse, t_env *e)
{
	if (nb == 1)
	{
		if (mouse.x >= g_apply_xs && mouse.x < g_apply_xe
				&& mouse.y >= g_apply_ys && mouse.y < g_apply_ye)
		{
			e->loading = 0;
			e->apply = 1;
			reload(e);
		}
		filters(mouse, e);
		ui_texture(mouse, e);
	}
	if (nb == 3)
		param_zone(mouse, e);
}
