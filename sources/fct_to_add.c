/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_to_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2018/10/22 14:44:53 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	FT_RESOLVE function:
**	Test for tree of rays
*/

t_color			ft_resolve(t_env *e, t_work w, int lvl)
{
	int		itemtype;
	int		curr;
	t_mat	currmat;
	t_vec	newstart;

	if (lvl > 2)
		return (e->backgroundcolor);
	curr = -1;
	itemtype = find_closest_item(w.r, e, &newstart, &curr);
	if (itemtype == EMPTY)
		return (e->backgroundcolor);
	currmat = find_material(itemtype, curr, newstart, e);
	if (currmat.n)
		return (add_colors(multiply_color(ft_resolve(e, newwork(w,
			refracted_ray(w.r.dir, w.n_vec, w.n / currmat.n, newstart), 1, e),
			lvl + 1), 1 - fresnel(w.r.dir, w.n_vec, w.n, currmat.n)),
			multiply_color(ft_resolve(e, newwork(w, reflected_ray(w.r.dir,
			w.n_vec, newstart), 0, e), lvl + 1), fresnel(w.r.dir, w.n_vec,
			w.n, currmat.n))));
	else if (!currmat.n && currmat.reflection)
		return (add_colors(get_light_value(w, newstart, currmat, e),
			multiply_color(ft_resolve(e, newwork(w, reflected_ray(w.r.dir,
			w.n_vec, newstart), 0, e), lvl + 1), currmat.reflection)));
	else
		return (get_light_value(w, newstart, currmat, e));
}

t_vec			find_normal_vec(t_ray r, int itemtype, int curr, t_env *e)
{
	t_vec	newstart;
	t_vec	n;
	double	finite;

	n = newvec(0, 0, 0);
	if (itemtype == EMPTY)
		return (n);
	newstart = find_newstart(e, r);
	finite = dotproduct(e->item[curr].dir, sub(newstart, e->item[curr].center))
		/ magnitude2(e->item[curr].dir);
	if (itemtype == PLANE || itemtype == DISK || (itemtype == F_CYL
				&& (finite <= 0 || finite >= e->item[curr].height)))
		n = (dotproduct(r.dir, e->item[curr].dir) < 0 ? e->item[curr].dir
				: opposite(e->item[curr].dir));
	else
		n = find_normal_vec_if_not_plane(itemtype, curr, newstart, e);
	if (!magnitude2(n))
		return (newvec(0, 0, 0));
	return (normalize(n));
}

t_vec			find_newstart(t_env *e, t_ray r)
{
	t_vec	newstart;
	int		curr;
	int		k;

	k = find_closest_item(r, e, &newstart, &curr);
	return (newstart);
}

t_work			newwork(t_work oldwork, t_ray newray, int r, t_env *e)
{
	t_work	w;
	int		itemtype;
	int		curr;
	t_mat	currmat;
	t_vec	newstart;

	w = oldwork;
	w.r = newray;
	itemtype = find_closest_item(oldwork.r, e, &newstart, &curr);
	currmat = find_material(itemtype, curr, newstart, e);
	w.n_vec = find_normal_vec(oldwork.r, itemtype, curr, e);
	if (r)
		w.n = currmat.n;
	w.coef = oldwork.coef * currmat.reflection;
	return (w);
}
