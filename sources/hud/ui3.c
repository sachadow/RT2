/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:27:08 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/28 19:54:01 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	DRAW_LVL_BAR function:
**	Draw the lvl bar for the scene from the e->lvl variable
*/

static void	draw_lvl_bar(t_env *e)
{
	t_rect	r;

	r = init_rect(RIGHT_SPC / 2 - 45, IMG_H / 2, 90, 1);
	draw_rect(RIGHT, r, BLACK, e);
	r = init_rect(RIGHT_SPC / 2 - 45 + e->lvl * 3, M_IMG_H - 5, 9, 5);
	draw_rev_tri(RIGHT, r, WHITE, e);
	r = init_rect(RIGHT_SPC / 2 - 45 + e->lvl * 3, M_IMG_H + 5, 9, 5);
	draw_tri(RIGHT, r, WHITE, e);
}

/*
**	UI3 function
**	Centralize the functions calls for the tab 3, insert shadow blur image,
**	draw shadow blur frame if needed
*/

void		ui3(t_env *e)
{
	t_rect	r;
	t_pix	pt;

	pt = init_point(MARGE, CIRCLE);
	insert_xpm(RIGHT, pt, "resources/lil-ombre.xpm", e);
	draw_lvl_bar(e);
	r = init_rect(27, M_IMG_H + 50, 146, 26);
	draw_rect(RIGHT, r, LIGHT_GREY, e);
	//	r = init_rect(MARGE, CIRCLE, BOTTOM_SPC - 2 * MARGE, 4 * MARGE);
	//	draw_rect(RIGHT, r, WHITE, e);
	if (e->itf.mat.type != TEXTURE)
		ui3_bottom(e);
	r = init_rect(pt.x, pt.y, CIRCLE, 4 * MARGE);
	if (e->light[0].radius == 100)
		frame(RIGHT, r, C_GREEN, e);
	else if (e->light[0].radius == 0)
		frame(RIGHT, r, DARK_GREY, e);
}
