/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_to_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2019/02/05 16:59:15 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	FT_RESOLVE function:
**	Test for tree of rays
*/

t_color			ft_resolve(t_env *e, t_work w, int lvl)
{
	t_mat		mat;
	t_vec		hit;
	double		nrefr;

	w.item_hit = find_closest_item(w.r, e, &hit);
	if (w.item_hit == EMPTY || lvl > e->lvl)
		return (add_2colors(lens_flaring(w.r, e), e->backgroundcolor));
	mat = find_material(w.item_hit % (e->nbs[ITEM] + 1), e);
	nrefr = find_nrefr(w, mat, w.item_hit % (e->nbs[ITEM] + 1), e);
	w.n_vec = find_normal_vec(w.r, w.item_hit, e);
	w.item_hit %= (e->nbs[ITEM] + 1);
	if (mat.n)
		return (add_3colors(get_light_value(w, hit, mat, e),
			multp_color(ft_resolve(e, newwork(w, refracted_ray(w.r.dir,
			w.n_vec, w.n / nrefr, hit), 1, e), lvl + 1), 1 - fresnel(w.r.dir,
			w.n_vec, w.n, nrefr)), multp_color(ft_resolve(e, newwork(w,
			reflected_ray(w.r.dir, w.n_vec, hit), 0, e), lvl + 1),
			fresnel(w.r.dir, w.n_vec, w.n, nrefr))));
	else if (!mat.n && (mat.reflection || mat.transparency))
		return (add_3colors(get_light_value(w, hit, mat, e),
			multp_color(ft_resolve(e, newwork(w, reflected_ray(w.r.dir, w.n_vec,
			hit), 0, e), lvl + 1), mat.reflection), multp_color(ft_resolve(e,
			newwork(w, transp_r(w.r, hit), 0, e), lvl + 1), mat.transparency)));
	else
		return (get_light_value(w, hit, mat, e));
}

/*
**	NEWWORK function:
**	Creation of a new work structure (for refraction and reflection)
*/

t_work			newwork(t_work oldwork, t_ray newray, int refr, t_env *e)
{
	t_work		w;
	int			itemstart;
	int			itemend;
	t_mat		mat;
	t_vec		newstart;

	w = oldwork;
	w.r = newray;
	itemstart = find_closest_item(oldwork.r, e, &newstart);
	mat = find_material(itemstart, e);
	itemend = find_closest_item(newray, e, &newstart);
	w.n_vec = find_normal_vec(newray, itemend, e);
	itemend %= (e->nbs[ITEM] + 1);
	itemstart %= (e->nbs[ITEM] + 1);
	if (refr)
	{
		if (itemtype(itemstart, e) != 2 && itemtype(itemstart, e) != 5
			&& position_in_tab(w.id, itemstart, REFRINCL) != -1)
			refr_enter_or_exit(&w, itemstart, 0, e);
		else
			refr_enter_or_exit(&w, itemstart, 1, e);
	}
	w.coef = oldwork.coef * mat.reflection;
	return (w);
}

/*
**	ITEMTYPE function:
**	Finds the item type from the item id
*/

int				itemtype(int id, t_env *e)
{
	return (e->item[id].item_type);
}
