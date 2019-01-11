/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruler.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:29:43 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/10 16:59:05 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

void		right_ruler(t_env *e)
{
	t_pix	pt;

	int x;
	pt = init_point(0, IMG_H - 1);
	for (x = -1; x < RIGHT_SPC; ++x)
	{
		pt.x = 0 + x;
		color_point(RIGHT, pt, WHITE, e);
	}
	pt = init_point(0, M_IMG_H + 2 * MARGE);
	for (x = -1; x < RIGHT_SPC; ++x)
	{
		pt.x = 0 + x;
		color_point(RIGHT, pt, BLACK, e);
	}
	pt = init_point(0, M_IMG_H + 85);
	for (x = -1; x < RIGHT_SPC; ++x)
	{
		pt.x = 0 + x;
		color_point(RIGHT, pt, WHITE, e);
	}
	pt = init_point(0, M_IMG_H + 35 + RIGHT_SPC - MARGE);
	for (x = -1; x < RIGHT_SPC; ++x)
	{
		pt.x = 0 + x;
		color_point(RIGHT, pt, WHITE, e);
	}
	pt = init_point(0, M_IMG_H + 35 + (RIGHT_SPC) / 2 - MARGE);
	for (x = -1; x < RIGHT_SPC; ++x)
	{
		pt.x = 0 + x;
		color_point(RIGHT, pt, WHITE, e);
	}
	pt = init_point((RIGHT_SPC) / 2, 0);
	for (x = -1; x < IMG_H; ++x)
	{
		pt.y = 0 + x;
		color_point(RIGHT, pt, WHITE, e);
	}
	pt = init_point((RIGHT_SPC) / 3, 0);
	for (x = -1; x < IMG_H; ++x)
	{
		pt.y = 0 + x;
		color_point(RIGHT, pt, WHITE, e);
	}
	pt = init_point(2 * ((RIGHT_SPC) / 3) + 1, 0);
	for (x = -1; x < IMG_H; ++x)
	{
		pt.y = 0 + x;
		color_point(RIGHT, pt, WHITE, e);
	}
}

void		bottom_ruler(t_env *e)
{
	t_pix	pt;
	int		x;

	if (e->itf.onglet == 2)
	{
		pt = init_point(WIN_W / 6, 0);
		for (x = -1; x < BOTTOM_SPC; ++x)
		{
			pt.y = 0 + x;
			color_point(BOTTOM, pt, WHITE, e);
		}
		pt = init_point(2 * WIN_W / 6, 0);
		for (x = -1; x < BOTTOM_SPC; ++x)
		{
			pt.y = 0 + x;
			color_point(BOTTOM, pt, WHITE, e);
		}
		pt = init_point(3 * (WIN_W / 6), 0);
		for (x = -1; x < BOTTOM_SPC; ++x)
		{
			pt.y = 0 + x;
			color_point(BOTTOM, pt, WHITE, e);
		}
		pt = init_point(4 * (WIN_W / 6), 0);
		for (x = -1; x < BOTTOM_SPC; ++x)
		{
			pt.y = 0 + x;
			color_point(BOTTOM, pt, WHITE, e);
		}
		pt = init_point(5 * (WIN_W / 6), 0);
		for (x = -1; x < BOTTOM_SPC; ++x)
		{
			pt.y = 0 + x;
			color_point(BOTTOM, pt, WHITE, e);
		}
		pt = init_point(0, (BOTTOM_SPC) / 2);
		for (x = -1; x < WIN_W; ++x)
		{
			pt.x = 0 + x;
			color_point(BOTTOM, pt, WHITE, e);
		}
	}
/*	if (e->itf.onglet == 1)
	{
		pt = init_point(WIN_W - RIGHT_SPC / 3, 0);
		for (x = -1; x < BOTTOM_SPC; ++x)
		{
			pt.y = 0 + x;
			color_point(BOTTOM, pt, WHITE, e);
		}
	}*/
	/*	if (e->itf.onglet == 3)
		{
		pt = init_point(WIN_W / 8, 0);
		for (x = -1; x < BOTTOM_SPC; ++x)
		{
		pt.y = 0 + x;
		color_point(BOTTOM, pt, WHITE, e);
		}
		pt = init_point(2 * WIN_W / 8, 0);
		for (x = -1; x < BOTTOM_SPC; ++x)
		{
		pt.y = 0 + x;
		color_point(BOTTOM, pt, WHITE, e);
		}
		pt = init_point(3 * WIN_W / 8, 0);
		for (x = -1; x < BOTTOM_SPC; ++x)
		{
		pt.y = 0 + x;
		color_point(BOTTOM, pt, WHITE, e);
		}
		pt = init_point(4 * WIN_W / 8, 0);
		for (x = -1; x < BOTTOM_SPC; ++x)
		{
		pt.y = 0 + x;
		color_point(BOTTOM, pt, WHITE, e);
		}
		pt = init_point(5 * WIN_W / 8, 0);
		for (x = -1; x < BOTTOM_SPC; ++x)
		{
		pt.y = 0 + x;
		color_point(BOTTOM, pt, WHITE, e);
		}
		pt = init_point(6 * WIN_W / 8, 0);
		for (x = -1; x < BOTTOM_SPC; ++x)
		{
		pt.y = 0 + x;
		color_point(BOTTOM, pt, WHITE, e);
		}
		pt = init_point(7 *WIN_W / 8, 0);
		for (x = -1; x < BOTTOM_SPC; ++x)
		{
		pt.y = 0 + x;
		color_point(BOTTOM, pt, WHITE, e);
		}
		}*/
}

static void	separations(t_env *e)
{
	t_rect	rect;

	rect = init_rect(3 * (WIN_W / 5) - 3, 0, 1, BOTTOM_SPC);
	draw_rect(BOTTOM, rect, BLACK, e);
	rect = init_rect(3 * (WIN_W / 5) - 1, 0, 1, BOTTOM_SPC);
	draw_rect(BOTTOM, rect, BLACK, e);
	rect = init_rect(4 * (WIN_W / 5) - 3, 0, 1, BOTTOM_SPC);
	draw_rect(BOTTOM, rect, BLACK, e);
	rect = init_rect(4 * (WIN_W / 5) - 1, 0, 1, BOTTOM_SPC);
	draw_rect(BOTTOM, rect, BLACK, e);
	rect = init_rect(4 * (WIN_W / 5), (BOTTOM_SPC) / 2, WIN_W / 5, 1);
	draw_rect(BOTTOM, rect, BLACK, e);
}

void		ui1_bottom_strokes(t_env *e)
{
	t_rect	rect;
	t_rect	r1;
	t_rect	r2;

	separations(e);
	r1 = init_rect(4 * (WIN_W / 5) + RIGHT_SPC / 3,
			5 * (BOTTOM_SPC) / 8 + 9, 1, 50);
	draw_rect(BOTTOM, r1, BLACK, e);
	r2 = init_rect(4 * (WIN_W / 5) + 2 * RIGHT_SPC / 3 + 1,
			5 * (BOTTOM_SPC) / 8 + 9, 1, 50);
	draw_rect(BOTTOM, r2, BLACK, e);
	if (!e->antialiasing)
		rect = init_rect(4 * (WIN_W / 5) + WIN_W / 7 / 4 - 14, r1.y,
				r1.x - (4 * (WIN_W / 5) + WIN_W / 7 / 4 - 14), 50);
	else if (e->antialiasing == 1)
		rect = init_rect(r1.x + 1, r1.y, r2.x - r1.x - 1, 50);
	else
		rect = init_rect(r2.x + 1, r2.y,
				(4 * (WIN_W / 5) + (WIN_W / 7) / 4 + 144) - r2.x, 50);
	frame(BOTTOM, rect, C_GREEN, e);
}

void		param_bar(t_env *e)
{
	t_rect	r;
	int		i;

	i = 0;
	while (++i < 8)
	{
		conv_all_param(e);
		r = init_rect(i * WIN_W / 8, e->itf.param[i], 9, 5);
		draw_tri_right(BOTTOM, r, WHITE, e);
		draw_tri_left(BOTTOM, r, WHITE, e);
	}
}

void		ui3_param(t_env *e)
{
	t_rect	r;

	r = init_rect(WIN_W / 8, (BOTTOM_SPC) / 6, 1, 4 * (BOTTOM_SPC) / 6);
	draw_rect(BOTTOM, r, BLACK, e);
	r = init_rect(2 * WIN_W / 8, (BOTTOM_SPC) / 6, 1, 4 * (BOTTOM_SPC) / 6);
	draw_rect(BOTTOM, r, BLACK, e);
	r = init_rect(3 * WIN_W / 8, (BOTTOM_SPC) / 6, 1, 4 * (BOTTOM_SPC) / 6);
	draw_rect(BOTTOM, r, BLACK, e);
	r = init_rect(4 * WIN_W / 8, (BOTTOM_SPC) / 6, 1, 4 * (BOTTOM_SPC) / 6);
	draw_rect(BOTTOM, r, BLACK, e);
	r = init_rect(5 * WIN_W / 8, (BOTTOM_SPC) / 6, 1, 4 * (BOTTOM_SPC) / 6);
	draw_rect(BOTTOM, r, BLACK, e);
	r = init_rect(6 * WIN_W / 8, (BOTTOM_SPC) / 6, 1, 4 * (BOTTOM_SPC) / 6);
	draw_rect(BOTTOM, r, BLACK, e);
	r = init_rect(7 * WIN_W / 8, (BOTTOM_SPC) / 6, 1, 4 * (BOTTOM_SPC) / 6);
	draw_rect(BOTTOM, r, BLACK, e);
	param_bar(e);
	/*	r = init_rect(WIN_W / 8, (BOTTOM_SPC) / 2, 9, 5);
		draw_tri_right(BOTTOM, r, WHITE, e);
		draw_tri_left(BOTTOM, r, WHITE, e);
		r = init_rect(2 * WIN_W / 8, (BOTTOM_SPC) / 2, 9, 5);
		draw_tri_right(BOTTOM, r, WHITE, e);
		draw_tri_left(BOTTOM, r, WHITE, e);
		r = init_rect(3 * WIN_W / 8, (BOTTOM_SPC) / 2, 9, 5);
		draw_tri_right(BOTTOM, r, WHITE, e);
		draw_tri_left(BOTTOM, r, WHITE, e);
		r = init_rect(4 * WIN_W / 8, (BOTTOM_SPC) / 2, 9, 5);
		draw_tri_right(BOTTOM, r, WHITE, e);
		draw_tri_left(BOTTOM, r, WHITE, e);
		r = init_rect(5 * WIN_W / 8, (BOTTOM_SPC) / 2, 9, 5);
		draw_tri_right(BOTTOM, r, WHITE, e);
		draw_tri_left(BOTTOM, r, WHITE, e);
		r = init_rect(6 * WIN_W / 8, (BOTTOM_SPC) / 2, 9, 5);
		draw_tri_right(BOTTOM, r, WHITE, e);
		draw_tri_left(BOTTOM, r, WHITE, e);
		r = init_rect(7 * WIN_W / 8, (BOTTOM_SPC) / 2, 9, 5);
		draw_tri_right(BOTTOM, r, WHITE, e);
		draw_tri_left(BOTTOM, r, WHITE, e);*/
}
