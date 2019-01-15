/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_zone.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 21:51:34 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/14 16:04:19 by qsebasti         ###   ########.fr       */
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

static void	ui_mat_type(t_mouse m, t_env *e)
{
	if (m.x >= g_checker_xs && m.x < g_checker_xs + WIN_W / 8
			&& m.y >= g_mat_ys && m.y < g_mat_ys + 100)
		e->itf.mat.type = CHECKER;
	else if (m.x >= g_marble_xs && m.x < g_marble_xs + WIN_W / 8
			&& m.y >= g_mat_ys && m.y < g_mat_ys + 100)
		e->itf.mat.type = MARBLE;
	else if (m.x >= g_perturb_xs && m.x < g_perturb_xs + WIN_W / 8
			&& m.y >= g_mat_ys && m.y < g_mat_ys + 100)
		e->itf.mat.type = PERTURB;
	else if (m.x >= g_wood_xs && m.x < g_wood_xs + WIN_W / 8
			&& m.y >= g_mat_ys && m.y < g_mat_ys + 100)
		e->itf.mat.type = WOOD;
	else if (m.x >= g_waves_xs && m.x < g_waves_xs + WIN_W / 8
			&& m.y >= g_mat_ys && m.y < g_mat_ys + 100)
		e->itf.mat.type = WAVES;
	if (e->itf.mat.type != TEXTURE)
		e->itf.nb_texture = 0;
}

static void	ui_texture(t_mouse m, t_env *e)
{
	if (m.x >= g_text1_xs && m.x < g_text1_xe && m.y >= g_text1_ys
			&& m.y < g_text1_ye)
		e->itf.nb_texture = (e->itf.nb_texture == 1 ? 0 : 1);
	else if (m.x >= g_text2_xs && m.x < g_text2_xe && m.y >= g_text1_ys
			&& m.y < g_text1_ye)
		e->itf.nb_texture = (e->itf.nb_texture == 2 ? 0 : 2);
	else if (m.x >= g_text1_xs && m.x < g_text1_xe && m.y >= g_text2_ys
			&& m.y < g_text2_ye)
		e->itf.nb_texture = (e->itf.nb_texture == 3 ? 0 : 3);
	else if (m.x >= g_text2_xs && m.x < g_text2_xe && m.y >= g_text2_ys
			&& m.y < g_text2_ye)
		e->itf.nb_texture = (e->itf.nb_texture == 4 ? 0 : 4);
	else if (m.x >= g_unif_xs && m.x < g_unif_xe && m.y >= g_unif_ys
			&& m.y < g_unif_ye)
	{
		e->itf.mat.type = UNIFORM;
		e->itf.nb_texture = 0;
	}
	if (e->itf.nb_texture)
		e->itf.mat.type = TEXTURE;
}

static void	filters(t_mouse m, t_env *e)
{
	if (m.x >= g_filter2_xs && m.x < g_filter2_xs + 100
			&& m.y >= g_filter1_ys && m.y < g_filter1_ys + 60)
		e->filter = (e->filter == SEPIA ? 0 : SEPIA);
	else if (m.x >= g_filter3_xs && m.x < g_filter3_xs + 100
			&& m.y >= g_filter1_ys && m.y < g_filter1_ys + 60)
		e->filter = (e->filter == GREYSCALE ? 0 : GREYSCALE);
	else if (m.x >= g_filter1_xs && m.x < g_filter1_xs + 100
			&& m.y >= g_filter2_ys && m.y < g_filter2_ys + 60)
		e->filter = (e->filter == SATURATE ? 0 : SATURATE);
	else if (m.x >= g_filter2_xs && m.x < g_filter2_xs + 100
			&& m.y >= g_filter2_ys && m.y < g_filter2_ys + 60)
		e->filter = (e->filter == REVERSE ? 0 : REVERSE);
	else if (m.x >= g_filter3_xs && m.x < g_filter3_xs + 100 
			&& m.y >= g_filter2_ys && m.y < g_filter2_ys + 60)
		e->cartoon = (e->cartoon == 1 ? 0 : 1);
	else if (m.x >= g_alias0_xs && m.x < g_alias0_xe
			&& m.y >= g_alias_ys && m.y < g_alias_ye)
		e->antialiasing = 0;
	else if (m.x >= g_alias0_xe + 1 && m.x < g_alias1_xe
			&& m.y >= g_alias_ys && m.y < g_alias_ye)
		e->antialiasing = 1;
	else if (m.x >= g_alias1_xe + 1 && m.x < g_alias2_xe
			&& m.y >= g_alias_ys && m.y < g_alias_ye)
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
	else if (nb == 2)
		ui_mat_type(mouse, e);
	else if (nb == 3)
		param_zone(mouse, e);
}
