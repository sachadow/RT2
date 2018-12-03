/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2018/11/27 16:34:23 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	FIND_CLOSEST_ITEM function:
**	Finds the closest item hit by the ray
*/

int			find_closest_item(t_ray r, t_env *e, t_vec *newstart, int *curr)
{
	double	t;
	double	before;
	int		i;

	t = -1;
  e->ncurr = -1;
	e->hit_negative = 0;
	before = -1;
	*curr = -1;
	i = -1;
	while (++i < e->nbs[3])
	{
		if (e->hit[e->item[i].item_type](r, e->item[i], &t))
			if (before == -1 || (t < before && t >= 0))
			{
				before = t;
				*curr = i;
			}
	}
	if (*curr < 0)
		return (-1);
	e->hit[e->item[*curr].item_type](r, e->item[*curr], &t);
	*newstart = add(scale(t, r.dir), r.start);
	if (e->item[*curr].isNega == 0)
		return (e->item[*curr].item_type);
  e->hit_negative = 1;
	return (find_post_nega(r, e, newstart, curr));
}

int			find_post_nega(t_ray r, t_env *e, t_vec *newstart, int *curr)
{
	double	t;
	double	before;
	int		i;
	int		ncurr;
	t_ray	to_use;

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
}
