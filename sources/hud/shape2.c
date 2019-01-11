/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:21:21 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/14 22:16:52 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"
#include <stdio.h>

void		draw_tri_left(int nb, t_rect base, int color, t_env *e)
{
	int		i;
	int		j;
	t_pix	tmp;

	i = -1;
	while (++i < base.height)
	{
		j = -1;
		while (++j < base.width)
		{
			tmp.x = base.x - i;
			tmp.y = base.y + j - base.width / 2;
			color_point(nb, tmp, color, e);
		}
		base.width -= 2;
	}
}

void		draw_tri_right(int nb, t_rect base, int color, t_env *e)
{
	int		i;
	int		j;
	t_pix	tmp;

	i = -1;
	while (++i < base.height)
	{
		j = -1;
		while (++j < base.width)
		{
			tmp.x = base.x + i;
			tmp.y = base.y + j - base.width / 2;
			color_point(nb, tmp, color, e);
		}
		base.width -= 2;
	}
}
