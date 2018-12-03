/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:41:27 by squiquem          #+#    #+#             */
/*   Updated: 2018/12/02 21:11:26 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	IN_SHADOW function:
**	Determines if the point is in the shadow
**	Returns the item id creating the shadow or -1 if not in shadow
*/

int			in_shadow(t_ray lightray, t_env *e, double t)
{
	int		k;
	int		x;

	k = -1;
	x = -1;
	while (++k < e->nbs[ITEM])
	{
		if (e->hit[e->item[k].item_type](lightray, e->item[k], &t) && t > 0.001f/* &&
				e->item[k].isNega == 0*/)
		{
			if (!(e->mat[e->item[k].mat].n))
				return (k);
			else
				x = k;
		}
	}
	return (x);
}

/*
**
**
*/

static void	count_shadow(int *c, t_vec impact, t_vec dist, t_env *e)
{
	t_ray	lray;

	lray.start = impact;
	lray.dir = normalize(dist);
	if (in_shadow(lray, e, magnitude(dist)) != EMPTY)
		(*c)++;
}

/*
**
**
*/

double		shadow(t_light light, t_vec impact, t_env *e)
{
	int		i;
	int		j;
	int		k;
	int		c;
	t_vec	dist;

	c = 0;
	i = -3;
	while (++i < 3)
	{
		j = -3;
		while (++j < 3)
		{
			k = -3;
			while (++k < 3)
			{
				dist = sub(newvec(light.pos.x + i * 50, light.pos.y + j * 50,
						light.pos.z + k * 50), impact);
				if (magnitude(dist) < 0.0f)
					continue ;
				count_shadow(&c, impact, dist, e);
			}
		}
	}
	printf("shadow=%f\n", (double)(c / 125));
	return ((double)(c / 125));
}
