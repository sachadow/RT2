/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:21:21 by qsebasti          #+#    #+#             */
/*   Updated: 2018/12/04 19:35:20 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hud.h"
#include "rt.h"
#include <stdio.h>

void		draw_tri(int num, t_pix pt, t_size base, int color, t_env *e)
{
	int i;
	int	j;
	t_pix	tmp;

	i = -1;
	while (++i < base.length)
	{
		j = -1;
		while (++j < base.width)
		{
			tmp.x = pt.x + j - base.width / 2;
			tmp.y = pt.y - i;
			color_point(num, tmp, color, e);
		}
		base.width -= 2;
	}
}

void		draw_rev_tri(int num, t_pix pt, t_size base, int color, t_env *e)
{
	int i;
	int	j;
	t_pix	tmp;

	i = -1;
	while (++i < base.length)
	{
		j = -1;
		while (++j < base.width)
		{
			tmp.x = pt.x + j - base.width / 2;
			tmp.y = pt.y + i;
			color_point(num, tmp, color, e);
		}
		base.width -= 2;
	}
}

void		draw_rect(int num, t_pix pt, t_size rect, int color, t_env *e)
{
	t_pix	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < rect.length)
	{
		j = -1;
		while (++j < rect.width)
		{
			tmp.x = pt.x + j;
			tmp.y = pt.y + i;
			color_point(num, tmp, color, e);
		}
	}
}
