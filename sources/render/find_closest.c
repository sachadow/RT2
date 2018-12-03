/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2018/12/03 15:59:10 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	FIND_CLOSEST_ITEM function:
**	Finds the closest item hit by the ray
*/

int			find_closest_item(t_ray r, t_env *e, t_vec *newstart)
{
	double	t;
	double	before;
	int		i;
	int		curr;

	if (!magnitude2(r.dir))
		return (EMPTY);
	t = -1;
	before = -1;
	e->hit_negative = 0;
	curr = -1;
	i = -1;
	while (++i < e->nbs[ITEM])
	{
		if (e->hit[e->item[i].item_type](r, e->item[i], &t)
			&& (before == -1 || (t < before && t > 0.001f)))
		{
			before = t;
			curr = i;
		}
	}
	if (curr > -1)
		*newstart = add(scale(before, r.dir), r.start);
	return (curr);
}

/*
**	FIND_NEWSTART function:
**	Finds the hit point from a ray r
*/

t_vec		find_newstart(t_env *e, t_ray r)
{
	t_vec	newstart;
	int		curr;

	curr = find_closest_item(r, e, &newstart);
	return (newstart);
}

/*
**	FIND_MATERIAL function:
**	Finds material of the hit item thanks to the index stored in the structure
*/

t_mat		find_material(int id, t_env *e)
{
	t_mat	m;

	m.diffuse = newcolor(0, 0, 0);
	m.reflection = 0;
	m.specvalue = 0;
	m.specpower = 0;
	if (e->item[id].mat > e->nbs[MAT])
		return (m);
	else
		m = e->mat[e->item[id].mat];
	return (m);
}