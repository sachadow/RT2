/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2019/01/15 17:01:17 by qsebasti         ###   ########.fr       */
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
	t_curr	ncurr;

	curr = get_closest_item(r, e);
	if (curr < 0)
		return (curr);
	t = -1;
	e->hit[e->item[curr].item_type](r, e->item[curr], &t);
	if (curr > -1 && e->item[curr].isnega == 0)
		*newstart = add(scale(t, r.dir), r.start);
	else if (e->item[curr].isnega == 1)
		curr = find_post_nega(r, e, newstart, &ncurr);
	return (curr);
}

int			find_post_nega(t_ray r, t_env *e, t_vec *newstart, t_curr *t)
{
	t_hititem	i;
	int			last_hit;

	t->ncurr = -1;
	t->curr = -1;
	i.item_count = count_items(r, e);
	negative_firstadvance(&i, &r, e, &last_hit);
	while (got_out(i.item_count, i.hit_items, i.items_mod, e) != 0)
	{
		if ((last_hit = get_closest_item(r, e)) == -1)
			return (free_nega(last_hit, i.hit_items, i.items_mod));
		negative_bigadvance(&i, &r, e, &last_hit);
		if (e->item[last_hit].isnega == 0
				&& get_hits(i.hit_items, i.items_mod, last_hit) % 2 != 0)
			t->curr = last_hit;
	}
	if (is_empty(i.hit_items, i.item_count, i.items_mod, e) == 0)
		return (free_nega(find_closest_item(r, e, newstart), i.hit_items,
					i.items_mod));
		*newstart = r.start;
	if (e->item[last_hit].isnega == 1)
		t->curr += ((e->nbs[ITEM] + 1) * (last_hit + 1));
	return (free_nega(t->curr, i.hit_items, i.items_mod));
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

t_mat		find_material(int mod, t_env *e)
{
	t_mat	m;

	m.diffuse = newcolor(0, 0, 0);
	m.reflection = 0;
	m.specvalue = 0;
	m.specpower = 0;
	if (e->item[mod].mat > e->nbs[MAT])
		return (m);
	else
		m = e->mat[e->item[mod].mat];
	return (m);
}
