/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:19:26 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/12 21:04:05 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"
#include <stdio.h>

static int	color_smooth(t_colo start, t_colo end, double k)
{
	int		i;
	t_colo	ret;

	i = -1;
	while (++i < 4)
		ret.argb[i] = start.argb[i] + (end.argb[i] - start.argb[i]) * k;
	return (ret.val);
}

static void	shade_rect(int tab[2], t_rect rect, t_env *e)
{
	int		i;
	int		j;
	t_pix	tmp;
	t_colo	start;
	t_colo	end;

	start.val = tab[0];
	end.val = tab[1];
	i = -1;
	while (++i < rect.height)
	{
		j = -1;
		while (++j < rect.width)
		{
			tmp.x = rect.x + j;
			tmp.y = rect.y + i;
			color_point(RIGHT, tmp,
					color_smooth(start, end, j / (double)(rect.width)), e);
		}
	}
}

void		shade_bar(t_env *e)
{
	int		tab[2];
	t_rect	rect;

	rect = init_rect(MARGE, M_IMG_H + RIGHT_SPC - 2 * MARGE + MARGE,
			(RIGHT_SPC - 2 * MARGE) / 2, MARGE);
	tab[0] = BLACK;
	tab[1] = e->interface.spec.val;
	shade_rect(tab, rect, e);
	rect = init_rect((RIGHT_SPC - 2 * MARGE) / 2 + MARGE, M_IMG_H + RIGHT_SPC
			- 2 * MARGE + MARGE, (RIGHT_SPC - 2 * MARGE) / 2, MARGE);
	tab[0] = e->interface.spec.val;
	tab[1] = WHITE;
	shade_rect(tab, rect, e);
}
