/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui1_bottom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:50:52 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/06 17:17:16 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"

void		ui1_bottom(t_env *e)
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
	pt = init_point(3 * (WIN_W / 5), 0);
	for (x = -1; x < BOTTOM_SPC; ++x)
	{
		pt.y = 0  + x;
		color_point(BOTTOM, pt, WHITE, e);
	}
	pt = init_point(4 * (WIN_W / 5), 0);
	for (x = -1; x < BOTTOM_SPC; ++x)
	{
		pt.y = 0  + x;
		color_point(BOTTOM, pt, WHITE, e);
	}
	pt = init_point(0, (BOTTOM_SPC) / 2);
	for (x = -1; x < WIN_W; ++x)
	{
		pt.x = 0  + x;
		color_point(BOTTOM, pt, WHITE, e);
	}
}
