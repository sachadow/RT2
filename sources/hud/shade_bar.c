/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:19:26 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/04 21:16:29 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"
#include <stdio.h>

void		frame(int num, t_pix pt, t_size rect, int color, t_env *e)
{
	t_pix	tmp;
	t_size	size;

	tmp = pt;
	tmp.x = pt.x - 2;
	tmp.y = pt.y - 2;
	size.width = 2;
	size.length = rect.length + 2 * 2;
	draw_rect(num, tmp, size, color, e);
	size.length = rect.width + 2 * 2;
	ft_swap(&size.width, &size.length);
	draw_rect(num, tmp, size, color, e);
	tmp.y = pt.y + rect.length;
	draw_rect(num, tmp, size, color, e);
	tmp.x = pt.x + rect.width;
	tmp.y = pt.y - 2;
	ft_swap(&size.width, &size.length);
	size.length = rect.length + 2 * 2;
	draw_rect(num, tmp, size, color, e);
}

static int	color_smooth(t_colo start, t_colo end, double k)
{
	int		i;
	t_colo	ret;

	i = -1;
	while (++i < 4)
		ret.argb[i] = start.argb[i] + (end.argb[i] - start.argb[i]) * k;
	return (ret.val);
}

static void	shade_rect(int tab[2], t_pix pt, t_size size, t_env *e)
{
	int		i;
	int		j;
	t_pix	tmp;
	t_colo	start;
	t_colo	end;

	start.val = tab[0];
	end.val = tab[1];
	i = -1;
	while (++i < size.length)
	{
		j = -1;
		while (++j < size.width)
		{
			tmp.x = pt.x + j;
			tmp.y = pt.y + i;
			color_point(RIGHT, tmp,
			color_smooth(start, end, j / (double)(size.width)), e);
		}
	}
}

void		shade_bar(t_env *e)
{
	t_pix	pt;
	t_size	size;
	int		tab[2];

	pt = init_point(MARGE, M_IMG_H + RIGHT_SPC - 2 * MARGE + MARGE);
	size = init_size((RIGHT_SPC - 2 * MARGE) / 2, MARGE);
	tab[0] = BLACK;
	tab[1] = e->interface.spec.val;
	shade_rect(tab, pt, size, e);
	pt = init_point((RIGHT_SPC - 2 * MARGE) / 2 + MARGE, M_IMG_H + RIGHT_SPC
	- 2 * MARGE + MARGE);
	size = init_size((RIGHT_SPC - 2 * MARGE) / 2, MARGE);
	tab[0] = e->interface.spec.val;
	tab[1] = WHITE;
	shade_rect(tab, pt, size, e);
}
