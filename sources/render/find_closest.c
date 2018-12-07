/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2018/12/07 15:33:39 by sderet           ###   ########.fr       */
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
	int		curr;

	e->hit_negative = 0;
	curr = get_closest_item(r, e);
	if (curr < 0)
		return (curr);
	t = -1;
	e->hit[e->item[curr].item_type](r, e->item[curr], &t);
	if (curr > -1)
		*newstart = add(scale(t, r.dir), r.start);
	if (e->item[curr].isNega == 1)
	{
//		e->hit_negative = 1;
		curr = find_post_nega(r, e, newstart, &curr);
	}
	return (curr);
}

int			find_post_nega(t_ray r, t_env *e, t_vec *newstart, int *curr)
{
	double	t;
	int		ncurr;
	t_ray	to_use;

	curr += 0;
	e->ncurr = -1;
	to_use.dir = r.dir;
	to_use.start = *newstart;
	ncurr = get_closest_item(to_use, e);
	if (ncurr < 0)
		return (-1);
	e->ncurr = ncurr;
	t = -1;
	e->hit[e->item[ncurr].item_type](to_use, e->item[ncurr], &t);
	*newstart = add(add(scale(t, r.dir), *newstart), scale(0.001, r.dir));
	r.start = *newstart;
	if (e->item[ncurr].isNega == 1)
	{
		return (find_closest_item(r, e, newstart));
	}
	return (-1);
}

int			get_closest_item(t_ray r, t_env *e)
{
	double	t;
	double	before;
	int		i;
	int		curr;

	if (!magnitude2(r.dir))
		return (-1);
	t = -1;
	before = -1;
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
