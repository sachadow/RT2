/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:28:45 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/14 17:50:51 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

void		ui2(t_env *e)
{
	t_pix	pt;

	pt = init_point(MARGE, 3 * MARGE);
	insert_xpm(RIGHT, pt, "resources/little-color-wheel.xpm", e);
	shade_bar(pt.y + RIGHT_SPC - MARGE, e->itf.spec[1].val, e);
//	if (e->itf.mat.type == CHECKER || e->itf.mat.type == MARBLE
//			|| e->itf.mat.type == PERTURB || e->itf.mat.type == WOOD)
//	{
		pt = init_point(MARGE, M_IMG_H + 35);
		insert_xpm(RIGHT, pt, "resources/little-color-wheel.xpm", e);
		shade_bar(pt.y + RIGHT_SPC - MARGE, e->itf.spec[2].val, e);
//	}
	cursor_spectrum(1, e);
	cursor_spectrum(2, e);
	cursor_shade(1, e);
	cursor_shade(2, e);
	ui2_bottom(e);
//	t_size box;
//	box = init_size((RIGHT_SPC) - 2 * MARGE, 60);
//	draw_rect(RIGHT, pt, box, WHITE, e);
//	right_ruler(e);
	bottom_ruler(e);
}
