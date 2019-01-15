/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:29:59 by qsebasti          #+#    #+#             */
/*   Updated: 2019/01/14 15:31:09 by qsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "hud.h"

int			int_to_pos(int val, int min, int max)
{
	int		pos;

	if (val == 0)
		return ((BOTTOM_SPC) / 6);
	pos = val / ((max - min) / 133) + (BOTTOM_SPC) / 6;
	return (pos);
}

int			pos_to_int(int pos, int min, int max)
{
	int		val;

	val = (pos - IMG_H - (BOTTOM_SPC) / 6) * ((max - min) / 133);
	if (val == 0)
		return (min);
	return (val);
}

void		conv_all_param(t_env *e)
{
	int i;

	i = -1;
	e->itf.param[0] = 0;
	while (++i < 8)
	{
		if (i == REFLECTION)
			e->itf.param[i] = int_to_pos((int)(e->itf.mat.reflection * 1000),
					0, 1000);
		if (i == TRANSPARENCY)
			e->itf.param[i] = int_to_pos((int)(e->itf.mat.transparency * 1000),
					0, 1000);
		if (i == SPECVALUE)
			e->itf.param[i] = int_to_pos((int)e->itf.mat.specvalue, 0, 1000);
		if (i == SPECPOWER)
			e->itf.param[i] = int_to_pos((int)e->itf.mat.specpower, 1, 1000);
		if (i == N)
			e->itf.param[i] = int_to_pos((int)(e->itf.mat.n * 1000), 0, 5000);
		if (i == BUMP)
			e->itf.param[i] = int_to_pos((int)(e->itf.mat.bump * 1000),
					0, 1000);
		if (i == SCALE)
			e->itf.param[i] = int_to_pos((int)e->itf.mat.scale, 1, 1000);
	}
}
