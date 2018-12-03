/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/11/27 16:34:23 by sderet           ###   ########.fr       */
=======
/*   Updated: 2018/11/29 18:11:20 by sderet           ###   ########.fr       */
>>>>>>> 9bb6ef917ac07142ede3f5b0bd805df97aba3b8d
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
<<<<<<< HEAD
	if (*curr < 0)
		return (-1);
	e->hit[e->item[*curr].item_type](r, e->item[*curr], &t);
	*newstart = add(scale(t, r.dir), r.start);
	if (e->item[*curr].isNega == 0)
		return (e->item[*curr].item_type);
  e->hit_negative = 1;
	return (find_post_nega(r, e, newstart, curr));
=======
	if (curr > -1)
		*newstart = add(scale(before, r.dir), r.start);
	return (curr);
>>>>>>> 9bb6ef917ac07142ede3f5b0bd805df97aba3b8d
}

/*
**	FIND_NEWSTART function:
**	Finds the hit point from a ray r
*/

t_vec		find_newstart(t_env *e, t_ray r)
{
	t_vec	newstart;
	int		curr;

<<<<<<< HEAD
  return (-1);
  e->ncurr = -1;
	t = -1;
  before = -1;
	ncurr = -1;
	i = -1;
	to_use.dir = r.dir;
	to_use.start = *newstart;
	while (++i < e->nbs[3])
	{
		if (e->hit[e->item[i].item_type](to_use, e->item[i], &t))
			if (before == -1 || (t < before))
			{
				before = t;
				ncurr = i;
			}
	}
	if (ncurr < 0)
		return (-1);
	e->ncurr = ncurr;
	e->hit[e->item[ncurr].item_type](to_use, e->item[ncurr], &t);
	*newstart = add(add(scale(t, r.dir), to_use.start), scale(0.01, r.dir));
  if (e->item[ncurr].isNega == 1 && ncurr == *curr)
    return (find_closest_item(r, e, newstart, curr));
  return (-1);
	if (e->item[ncurr].isNega && e->hit_negative == 1)
		return (find_closest_item(r, e, newstart, curr));
	else if (!e->item[ncurr].isNega && e->item[*curr].isNega)
	{
		e->hit_negative += 1;
		*curr = ncurr;
		find_post_nega(r, e, newstart, curr);
	}
	else if (e->item[ncurr].isNega && !e->item[ncurr].isNega)
		return (e->item[ncurr].item_type);
	return (-1);
=======
	curr = find_closest_item(r, e, &newstart);
	return (newstart);
}

/*
**	FIND_MATERIAL function:
**	Finds material of the hit item thanks to the index stored in the structure
*/

t_mat		find_material(int id, t_vec newstart, t_env *e)
{
	t_mat	m;
	int		type;

	m.diffuse = newcolor(0, 0, 0);
	m.reflection = 0;
	m.specvalue = 0;
	m.specpower = 0;
	if (e->item[id].mat > e->nbs[MAT])
		return (m);
	type = itemtype(id, e);
	if (type == PLANE
		&& ((int)(floor(newstart.x / 100) + floor(newstart.z / 100)) % 2))
		m = e->mat[e->item[id].mat];
	else if (type == PLANE
		&& !((int)(floor(newstart.x / 100) + floor(newstart.z / 100)) % 2))
		m = e->mat[(e->item[id].mat + 1) % e->nbs[MAT]];
	else
		m = e->mat[e->item[id].mat];
	return (m);
>>>>>>> 9bb6ef917ac07142ede3f5b0bd805df97aba3b8d
}
