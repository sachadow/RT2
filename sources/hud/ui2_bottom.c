/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui2_bottom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:28:53 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/09 18:34:08 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

void		ui2_bottom(t_env *e)
{
	t_rect	r;

	r = init_rect(WIN_W / 6 - (WIN_W / 8 / 2), (BOTTOM_SPC) / 4, WIN_W / 8, 100);
	draw_rect(BOTTOM, r, WHITE, e);
	r = init_rect(2 * WIN_W / 6 - (WIN_W / 8 / 2), (BOTTOM_SPC) / 4, WIN_W / 8, 100);
	draw_rect(BOTTOM, r, WHITE, e);
	r = init_rect(3 * WIN_W / 6 - (WIN_W / 8 / 2), (BOTTOM_SPC) / 4, WIN_W / 8, 100);
	draw_rect(BOTTOM, r, WHITE, e);
	r = init_rect(4 * WIN_W / 6 - (WIN_W / 8 / 2), (BOTTOM_SPC) / 4, WIN_W / 8, 100);
	draw_rect(BOTTOM, r, WHITE, e);
	r = init_rect(5 * WIN_W / 6 - (WIN_W / 8 / 2), (BOTTOM_SPC) / 4, WIN_W / 8, 100);
	draw_rect(BOTTOM, r, WHITE, e);
}
