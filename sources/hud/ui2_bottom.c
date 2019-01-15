/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui2_bottom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:28:53 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/14 17:47:25 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

const int	g_checker_xs = WIN_W / 6 - WIN_W / 8 / 2;
const int	g_marble_xs = 2 * WIN_W / 6 - WIN_W / 8 / 2;
const int	g_perturb_xs = 3 * WIN_W / 6 - WIN_W / 8 / 2;
const int	g_wood_xs = 4 * WIN_W / 6 - WIN_W / 8 / 2;
const int	g_waves_xs = 5 * WIN_W / 6 - WIN_W / 8 / 2;

const int	g_mat_ys = IMG_H + BOTTOM_SPC / 4;

static void	ui2_frames(t_rect *r, t_env *e)
{
	int		i;

	i = -1;
	while (++i < 5)
	{
		frame(BOTTOM, r[i], DARK_GREY, e);
		if (i + 2 == e->itf.mat.type)
			frame(BOTTOM, r[i], C_GREEN, e);
	}
}

static void	set_frames(t_rect *r)
{
	r[0] = init_rect(g_checker_xs, g_mat_ys - IMG_H, WIN_W / 8, 100);
	r[1] = init_rect(g_marble_xs, g_mat_ys - IMG_H, WIN_W / 8, 100);
	r[2] = init_rect(g_perturb_xs, g_mat_ys - IMG_H, WIN_W / 8, 100);
	r[3] = init_rect(g_waves_xs, g_mat_ys - IMG_H, WIN_W / 8, 100);
	r[4] = init_rect(g_wood_xs, g_mat_ys - IMG_H, WIN_W / 8, 100);
}

static void	ui2_bottom_xpm(t_env *e)
{
	t_pix	pt;

	pt = init_point(g_checker_xs, g_mat_ys - IMG_H);
	insert_xpm(BOTTOM, pt, "resources/lil-damier.xpm", e);
	pt = init_point(g_marble_xs, g_mat_ys - IMG_H);
	insert_xpm(BOTTOM, pt, "resources/lil-marbre.xpm", e);
	pt = init_point(g_perturb_xs, g_mat_ys - IMG_H);
	insert_xpm(BOTTOM, pt, "resources/lil-perlin.xpm", e);
}

void		ui2_bottom(t_env *e)
{
	t_rect	r;
	t_rect	rect[5];

	r = init_rect(g_checker_xs, g_mat_ys - IMG_H, WIN_W / 8, 100);
	draw_rect(BOTTOM, r, WHITE, e);
	r = init_rect(g_marble_xs, g_mat_ys - IMG_H, WIN_W / 8, 100);
	draw_rect(BOTTOM, r, WHITE, e);
	r = init_rect(g_perturb_xs, g_mat_ys - IMG_H, WIN_W / 8, 100);
	draw_rect(BOTTOM, r, WHITE, e);
	r = init_rect(g_wood_xs, g_mat_ys - IMG_H, WIN_W / 8, 100);
	draw_rect(BOTTOM, r, WHITE, e);
	r = init_rect(g_waves_xs, g_mat_ys - IMG_H, WIN_W / 8, 100);
	draw_rect(BOTTOM, r, WHITE, e);
	ui2_bottom_xpm(e);
	set_frames(rect);
	ui2_frames(rect, e);
}
