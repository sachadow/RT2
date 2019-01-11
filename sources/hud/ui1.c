/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:19:26 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/10 16:29:37 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

void		color_val(t_env *e)
{
	char *s;

	s = ft_itoa((int)(e->itf.spec_shade[0].argb[R]));
	mlx_string_put(e->mlx, e->win, IMG_W, IMG_H - 45, WHITE, "R:");
	mlx_string_put(e->mlx, e->win, IMG_W + 30, IMG_H - 45, WHITE, s);
	free(s);
	s = ft_itoa((int)(e->itf.spec_shade[0].argb[G]));
	mlx_string_put(e->mlx, e->win, IMG_W + (RIGHT_SPC) / 3, IMG_H - 45, WHITE,
			"G:");
	mlx_string_put(e->mlx, e->win, IMG_W + 30 + (RIGHT_SPC) / 3, IMG_H - 45,
			WHITE, s);
	free(s);
	s = ft_itoa((int)(e->itf.spec_shade[0].argb[B]));
	mlx_string_put(e->mlx, e->win, IMG_W + 2 * (RIGHT_SPC) / 3, IMG_H - 45,
			WHITE, "B:");
	mlx_string_put(e->mlx, e->win, IMG_W + 30 + 2 * (RIGHT_SPC) / 3,
			IMG_H - 45, WHITE, s);
	free(s);
}

void		ui1(t_env *e)
{
	t_pix	pt;

	pt = init_point(MARGE, M_IMG_H);
	insert_xpm(RIGHT, pt, "resources/little-color-wheel.xpm", e);
	shade_bar(M_IMG_H + RIGHT_SPC - MARGE, e->itf.spec[0].val, e);
	cursor_spectrum(0, e);
	cursor_shade(0, e);
	ui1_bottom(e);
	pt = init_point(MARGE, 2 * (M_IMG_H) / 3);
	insert_xpm(RIGHT, pt, "resources/lil-apply-button.xpm", e);
	bottom_ruler(e);
	//	t_size box;
	//	box = init_size((RIGHT_SPC) - 2 * MARGE, 60);
	//	draw_rect(RIGHT, pt, box, WHITE, e);
	//	right_ruler(e);
}
