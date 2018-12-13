/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui1_bottom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:50:52 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/12 21:06:29 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

void		ui1_bottom(t_env *e)
{
	t_pix	pt;
	t_rect	rect;

	pt = init_point(3 * WIN_W / 5 + (WIN_W / 5) / 10, 20);
	insert_xpm(BOTTOM, pt, "textures/redbrick.xpm", e);
	pt = init_point(3 * WIN_W / 5 + ((WIN_W / 5) / 10) * 6, 20);
	insert_xpm(BOTTOM, pt, "textures/bluestone.xpm", e);
	pt = init_point(3 * WIN_W / 5 + ((WIN_W / 5) / 10) * 6,
			(BOTTOM_SPC) / 2 + 20);
	insert_xpm(BOTTOM, pt, "textures/colorstone.xpm", e);
	pt = init_point(3 * WIN_W / 5 + (WIN_W / 5) / 10, (BOTTOM_SPC) / 2 + 20);
	insert_xpm(BOTTOM, pt, "textures/wood.xpm", e);
	bottom_ruler(e);

	rect = init_rect(WIN_W / 5 / 4, 3 * (BOTTOM_SPC) / 5, 100, 60);
	draw_rect(BOTTOM, rect, WHITE, e);
	rect = init_rect((WIN_W / 5) + WIN_W / 5 / 4, 3 * (BOTTOM_SPC) / 5, 100,
			60);
	draw_rect(BOTTOM, rect, WHITE, e);
	rect = init_rect((WIN_W / 5) + WIN_W / 5 / 4, (BOTTOM_SPC) / 8, 100, 60);
	draw_rect(BOTTOM, rect, WHITE, e);
	rect = init_rect(2 * (WIN_W / 5) + WIN_W / 5 / 4, 3 * (BOTTOM_SPC) / 5, 100,
			60);
	draw_rect(BOTTOM, rect, WHITE, e);
	rect = init_rect(2 * (WIN_W / 5) + WIN_W / 5 / 4, (BOTTOM_SPC) / 8, 100,
			60);
	draw_rect(BOTTOM, rect, WHITE, e);
	rect = init_rect(4 * (WIN_W / 5) + (WIN_W / 7) / 4, 3 * (BOTTOM_SPC) / 5,
			140, 60);
	draw_rect(BOTTOM, rect, WHITE, e);
	rect = init_rect(4 * (WIN_W / 5) + (WIN_W / 5) / 4, (BOTTOM_SPC) / 8, 100,
			60);
	draw_rect(BOTTOM, rect, WHITE, e);
	ui1_bottom_strokes(e);
}
