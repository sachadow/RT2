/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui2_bottom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 19:28:53 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/20 19:40:48 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

void		ui2_bottom(t_env *e)
{
	t_rect	r;

	r = init_rect(2 * (WIN_W / 5 / 3), (BOTTOM_SPC) / 4, 150, 100);
	draw_rect(BOTTOM, r, WHITE, e);
	r = init_rect(WIN_W / 5 + 2 * (WIN_W / 5 / 3), (BOTTOM_SPC) / 4, 150, 100);
	draw_rect(BOTTOM, r, WHITE, e);
	r = init_rect(2 * WIN_W / 5 + 2 * (WIN_W / 5 / 3), (BOTTOM_SPC) / 4, 150, 100);
	draw_rect(BOTTOM, r, WHITE, e);
	r = init_rect(3 * WIN_W / 5 + 2 * (WIN_W / 5 / 3), (BOTTOM_SPC) / 4, 150, 100);
	draw_rect(BOTTOM, r, WHITE, e);
}
