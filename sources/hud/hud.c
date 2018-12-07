/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:39:40 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/04 19:36:28 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

/*
**	HUD function:
**	Creates new image to display UI
*/

void		hud(t_env *e)
{
	t_pix	pt;
	t_size	box;

	new_image(RIGHT, RIGHT_SPC, IMG_H, e);
	pt = init_point(0, 0);
	box = init_size(RIGHT_SPC, IMG_H);
	draw_rect(RIGHT, pt, box, DARK_GREY, e);
	new_image(BOTTOM, WIN_W, BOTTOM_SPC, e);
	pt = init_point(0, 0);
	box = init_size(WIN_W, BOTTOM_SPC);
	draw_rect(BOTTOM, pt, box, DARK_GREY, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img[BOTTOM], 0, IMG_H);
	tab(e);
}
