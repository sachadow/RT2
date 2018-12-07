/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:41:27 by squiquem          #+#    #+#             */
/*   Updated: 2018/12/06 16:23:31 by sderet           ###   ########.fr       */
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
		if (e->hit[e->item[k].item_type](lightray, e->item[k], &t) && t > 0.001f &&
				e->item[k].isNega == 0)
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
**	COUNT_SHADOW function:
**	Creates a lightray from the parameters and increments the light quantity
*/

static void	count_shadow(double *c, t_vec impact, t_vec dist, t_env *e)
{
	t_ray	lray;
	int		inshdw;

	if (magnitude(dist) <= 0.0f)
		return ;
	lray.start = impact;
	lray.dir = normalize(dist);
	inshdw = in_shadow(lray, e, magnitude(dist));
	if (inshdw == EMPTY)
		*c += 1;
	else if (inshdw != EMPTY && e->mat[e->item[inshdw].mat].n)
		*c += e->mat[e->item[inshdw].mat].transparency;
}

/*
**	SHADOW_FOM_SPHERE function:
**	Returns the quantity of light if the light source is a sphere
**	Calculates the quantity from the light sphere that are illuminating
**	the impact point
*/

double		shadow_from_sphere(t_light light, t_vec impact, t_work w, t_env *e)
{
	int		i;
	int		j;
	int		k;
	double	c;
	t_vec	d;

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
				d = sub(add(light.pos, scale(light.radius / 2,
								newvec(i, j, k))), impact);
				if (i * i + j * j + k * k > 4 || dotproduct(w.n_vec, d) <= 0.0f)
					continue ;
				count_shadow(&c, impact, d, e);
			}
		}
	}
	return (c / 33);
}

/*
**	SHADOW_FROM_POINT function:
**	Returns the quantity of light if the light source is a point
*/

double		shadow_from_point(t_ray lray, t_vec dist, t_env *e)
{
	int	inshdw;

	inshdw = in_shadow(lray, e, magnitude(dist));
	if (inshdw == EMPTY)
		return (1);
	else if (inshdw != EMPTY && e->mat[e->item[inshdw].mat].n)
		return (e->mat[e->item[inshdw].mat].transparency);
	else
		return (0);
}
