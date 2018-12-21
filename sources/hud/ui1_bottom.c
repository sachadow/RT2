/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui1_bottom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:50:52 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/20 20:46:15 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

static void	texture_frame(t_rect *r, t_env *e)
{
	if (e->itf.nb_texture == 1)
		frame(BOTTOM, r[6], C_GREEN, e);
	if (e->itf.nb_texture == 2)
		frame(BOTTOM, r[7], C_GREEN, e);
	if (e->itf.nb_texture == 3)
		frame(BOTTOM, r[8], C_GREEN, e);
	if (e->itf.nb_texture == 4)
		frame(BOTTOM, r[9], C_GREEN, e);
	if (e->itf.item.mat == 0)
		frame(BOTTOM, r[10], C_GREEN, e);
}

static void	set_frames(t_rect *r)
{
	r[0] = init_rect(0, 0, 0, 0);
	r[1] = init_rect(SEPIA_XS, (SEPIA_YS) - IMG_H, (SEPIA_XE) - (SEPIA_XS),
			(SEPIA_YE - IMG_H) - (SEPIA_YS - IMG_H));
	r[2] = init_rect(GSCAL_XS, (GSCAL_YS) - IMG_H, (GSCAL_XE) - (GSCAL_XS),
			(GSCAL_YE - IMG_H) - (GSCAL_YS - IMG_H));
	r[3] = init_rect(REVER_XS, (REVER_YS) - IMG_H, (REVER_XE) - (REVER_XS),
			(REVER_YE - IMG_H) - (REVER_YS - IMG_H));
	r[4] = init_rect(SATUR_XS, (SATUR_YS) - IMG_H, (SATUR_XE) - (SATUR_XS),
			(SATUR_YE - IMG_H) - (SATUR_YS - IMG_H));
	r[5] = init_rect(CARTO_XS, (CARTO_YS) - IMG_H, (CARTO_XE) - (CARTO_XS),
			(CARTO_YE - IMG_H) - (CARTO_YS - IMG_H));
	r[6] = init_rect(TEXT1_XS, (TEXT1_YS) - IMG_H, (TEXT1_XE) - (TEXT1_XS),
			(TEXT1_YE - IMG_H) - (TEXT1_YS - IMG_H));
	r[7] = init_rect(TEXT2_XS, (TEXT1_YS) - IMG_H, (TEXT2_XE) - (TEXT2_XS),
			(TEXT1_YE - IMG_H) - (TEXT1_YS - IMG_H));
	r[8] = init_rect(TEXT1_XS, (TEXT2_YS) - IMG_H, (TEXT1_XE) - (TEXT1_XS),
			(TEXT2_YE - IMG_H) - (TEXT2_YS - IMG_H));
	r[9] = init_rect(TEXT2_XS, (TEXT2_YS) - IMG_H, (TEXT2_XE) - (TEXT2_XS),
			(TEXT2_YE - IMG_H) - (TEXT2_YS - IMG_H));
	r[10] = init_rect(UNIF_XS, (UNIF_YS) - IMG_H, (UNIF_XE) - (UNIF_XS),
			(UNIF_YE - IMG_H) - (UNIF_YS - IMG_H));
}

static void	ui1_frame(t_rect *r, t_env *e)
{
	int i;

	i = -1;
	while (++i < 5)
	{
		frame(BOTTOM, r[i], DARK_GREY, e);
		if (i == e->filter)
			frame(BOTTOM, r[i], C_GREEN, e);
	}
	if (e->cartoon)
		frame(BOTTOM, r[i], C_GREEN, e);
	else
		frame(BOTTOM, r[i], DARK_GREY, e);
}

static void	ui1_bottom_xpm(t_env *e)
{
	t_pix	pt;

	pt = init_point((WIN_W / 5) + WIN_W / 5 / 4, (BOTTOM_SPC) / 8);
	insert_xpm(BOTTOM, pt, "resources/lil-sepia.xpm", e);
	pt = init_point(2 * (WIN_W / 5) + WIN_W / 5 / 4, (BOTTOM_SPC) / 8);
	insert_xpm(BOTTOM, pt, "resources/lil-greyscale.xpm", e);
	pt = init_point(WIN_W / 5 / 4, 3 * (BOTTOM_SPC) / 5);
	insert_xpm(BOTTOM, pt, "resources/lil-saturate.xpm", e);
	pt = init_point((WIN_W / 5) + WIN_W / 5 / 4, 3 * (BOTTOM_SPC) / 5);
	insert_xpm(BOTTOM, pt, "resources/lil-reverse.xpm", e);
	pt = init_point(2 * (WIN_W / 5) + WIN_W / 5 / 4, 3 * (BOTTOM_SPC) / 5);
	insert_xpm(BOTTOM, pt, "resources/lil-cartoon.xpm", e);
	pt = init_point(3 * WIN_W / 5 + (WIN_W / 5) / 10, 20);
	insert_xpm(BOTTOM, pt, "textures/redbrick.xpm", e);
	pt = init_point(3 * WIN_W / 5 + ((WIN_W / 5) / 10) * 6, 20);
	insert_xpm(BOTTOM, pt, "textures/bluestone.xpm", e);
	pt = init_point(3 * WIN_W / 5 + ((WIN_W / 5) / 10) * 6,
			(BOTTOM_SPC) / 2 + 20);
	insert_xpm(BOTTOM, pt, "textures/colorstone.xpm", e);
	pt = init_point(3 * WIN_W / 5 + (WIN_W / 5) / 10, (BOTTOM_SPC) / 2 + 20);
	insert_xpm(BOTTOM, pt, "textures/wood.xpm", e);
}

void		ui1_bottom(t_env *e)
{
	t_rect	rect[11];

	ui1_bottom_xpm(e);
	rect[0] = init_rect(4 * (WIN_W / 5) + (WIN_W / 5) / 6 - 7, (BOTTOM_SPC) / 8,
			140, 30);
	draw_rect(BOTTOM, rect[0], LIGHT_GREY, e);
	rect[0] = init_rect(4 * (WIN_W / 5) + (WIN_W / 7) / 4 - 14,
			5 * (BOTTOM_SPC) / 8 + 9, 159, 50);
	draw_rect(BOTTOM, rect[0], LIGHT_GREY, e);
	ui1_bottom_strokes(e);
	set_frames(rect);
	ui1_frame(rect, e);
	if (e->itf.nb_texture || e->itf.item.mat == 0)
		texture_frame(rect, e);
	//bottom_ruler(e);

	//	rect = init_rect(WIN_W / 5 / 4, 3 * (BOTTOM_SPC) / 5, 100, 60);
	//	draw_rect(BOTTOM, rect, WHITE, e);
	//	rect = init_rect((WIN_W / 5) + WIN_W / 5 / 4, 3 * (BOTTOM_SPC) / 5, 100,
	//			60);
	//	draw_rect(BOTTOM, rect, WHITE, e);
	//	rect = init_rect((WIN_W / 5) + WIN_W / 5 / 4, (BOTTOM_SPC) / 8, 100, 60);
	//	draw_rect(BOTTOM, rect, WHITE, e);
	//	rect = init_rect(2 * (WIN_W / 5) + WIN_W / 5 / 4, 3 * (BOTTOM_SPC) / 5, 100,
	//			60);
	//	draw_rect(BOTTOM, rect, WHITE, e);
	//	rect = init_rect(2 * (WIN_W / 5) + WIN_W / 5 / 4, (BOTTOM_SPC) / 8, 100,
	//			60);
	//	draw_rect(BOTTOM, rect, WHITE, e);
}
