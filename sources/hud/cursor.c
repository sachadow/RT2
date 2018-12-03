/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:04:25 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/03 15:39:45 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keyboard.h"
#include "hud.h"
#include <stdio.h>

void		cursor_spectrum(t_env *e)
{
	int i;
	int j;

	t_pix pt;
	j = -2;
	if (e->interface.spectrum.x > 0 && e->interface.spectrum.x < RIGHT_SPC
			&& e->interface.spectrum.y > 0 && e->interface.spectrum.y < IMG_H)
	{
		while (++j < 1)
		{
			i = -11;
			while (++i < 10)
			{
				pt.x = e->interface.spectrum.x + i;
				pt.y = e->interface.spectrum.y + j;
				if (i < -2 || i > 2)
					color_point(RIGHT, pt, WHITE, e);
				pt.x = e->interface.spectrum.x + j;
				pt.y = e->interface.spectrum.y + i;
				if (i < -2 || i > 2)
					color_point(RIGHT, pt, WHITE, e);
			}
		}
	}
}
