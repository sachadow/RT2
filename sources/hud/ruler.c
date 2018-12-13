/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruler.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:29:43 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/12 21:03:17 by qsebasti         ###   ########.fr       */
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
	pt = init_point((RIGHT_SPC) / 2, 0);
	for (x = -1; x < IMG_H; ++x)
	{
		pt.y = 0 + x;
		color_point(RIGHT, pt, WHITE, e);
	}
	pt = init_point(0, M_IMG_H + 85);
	for (x = -1; x < IMG_H; ++x)
	{
		pt.x = 0 + x;
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

	pt = init_point(WIN_W / 5, 0);
	for (x = -1; x < BOTTOM_SPC; ++x)
	{
		pt.y = 0  + x;
		color_point(BOTTOM, pt, WHITE, e);
	}
	pt = init_point(2 * WIN_W / 5, 0);
	for (x = -1; x < BOTTOM_SPC; ++x)
	{
		pt.y = 0  + x;
		color_point(BOTTOM, pt, WHITE, e);
	}
/*	pt = init_point(3 * (WIN_W / 5), 0);
	for (x = -1; x < BOTTOM_SPC; ++x)
	{
		pt.y = 0  + x;
		color_point(BOTTOM, pt, WHITE, e);
	}*/
/*	pt = init_point(4 * (WIN_W / 5), 0);
	for (x = -1; x < BOTTOM_SPC; ++x)
	{
		pt.y = 0  + x;
		color_point(BOTTOM, pt, WHITE, e);
	}*/
	pt = init_point(0, (BOTTOM_SPC) / 2);
	for (x = -1; x < WIN_W; ++x)
	{
		pt.x = 0  + x;
		color_point(BOTTOM, pt, WHITE, e);
	}
}

void		ui1_bottom_strokes(t_env *e)
{
	t_rect	rect;

	rect = init_rect(4 * (WIN_W / 5) - 1, 0, 1, BOTTOM_SPC);
	draw_rect(BOTTOM, rect, BLACK, e); 
	rect = init_rect(4 * (WIN_W / 5) + 1, 0, 1, BOTTOM_SPC);
	draw_rect(BOTTOM, rect, BLACK, e); 
	rect = init_rect(3 * (WIN_W / 5) - 1, 0, 1, BOTTOM_SPC);
	draw_rect(BOTTOM, rect, BLACK, e); 
	rect = init_rect(3 * (WIN_W / 5) + 1, 0, 1, BOTTOM_SPC);
	draw_rect(BOTTOM, rect, BLACK, e); 
	}
