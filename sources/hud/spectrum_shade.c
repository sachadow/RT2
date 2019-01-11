/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectrum_shade.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:23:56 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/10 20:27:58 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

const int	g_shad_xs = IMG_W + MARGE;
const int	g_shad_xe = IMG_W + RIGHT_SPC - MARGE;
const int	g_shad_ys = M_IMG_H + CIRCLE + MARGE;
const int	g_shad_ye = M_IMG_H + CIRCLE + 2 * MARGE;

void		ui_shade(int nb, t_pix pix, t_mouse mouse, t_env *e)
{
	t_pix	pt;

	if (mouse.x >= g_shad_xs && mouse.x < g_shad_xe && mouse.y >= pix.y
			&& mouse.y < pix.x)
	{
		e->itf.shade[nb].button = mouse.button;
		e->itf.shade[nb].x = mouse.x - IMG_W;
		e->itf.shade[nb].y = pix.y;
		pt = init_point(e->itf.spectrum[nb].x,
				e->itf.spectrum[nb].y);
		e->itf.spec_shade[nb].val = color_picker(RIGHT, pt, e);
	}
}

int			ui_spectrum(int nb, t_pix pix, t_mouse mouse, t_env *e)
{
	int		a;
	int		b;
	t_pix	pt;

	a = IMG_W + (RIGHT_SPC) / 2;
	b = pix.x;
	if ((mouse.x - a) * (mouse.x - a) + (mouse.y - b) * (mouse.y - b)
			< ((CIRCLE) / 2) * ((CIRCLE) / 2))
	{
		e->itf.spectrum[nb] = mouse;
		e->itf.spectrum[nb].x = mouse.x - IMG_W;
		pt = init_point(e->itf.spectrum[nb].x, mouse.y);
		e->itf.spec[nb].val = color_picker(RIGHT, pt, e);
		e->itf.shade[nb].x = (RIGHT_SPC) / 2;
		e->itf.shade[nb].y = pix.y;
		if (e->itf.spec[nb].val != WHITE)
			e->itf.spec_shade[nb].val = e->itf.spec[nb].val;
		return (1);
	}
	return (0);
}
