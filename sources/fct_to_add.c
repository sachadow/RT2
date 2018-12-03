/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_to_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/11/27 17:56:23 by sderet           ###   ########.fr       */
=======
/*   Updated: 2018/11/15 11:37:10 by squiquem         ###   ########.fr       */
>>>>>>> 9bb6ef917ac07142ede3f5b0bd805df97aba3b8d
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
	t_vec		newstart;
	double		nrefr;

	w.item_hit = find_closest_item(w.r, e, &newstart);
	if (w.item_hit == EMPTY || lvl > e->lvl)
		return (e->backgroundcolor);
	mat = find_material(w.item_hit, newstart, e);
	nrefr = find_nrefr(w, mat, w.item_hit, e);
	w.n_vec = find_normal_vec(w.r, w.item_hit, e);
	if (mat.n)
		return (add_3colors(get_light_value(w, newstart, mat, e),
			multiply_color(ft_resolve(e, newwork(w, refracted_ray(w.r.dir,
			w.n_vec, w.n / nrefr, newstart), 1, e), lvl + 1),
			1 - fresnel(w.r.dir, w.n_vec, w.n, nrefr)),
			multiply_color(ft_resolve(e, newwork(w, reflected_ray(w.r.dir,
			w.n_vec, newstart), 0, e), lvl + 1), fresnel(w.r.dir, w.n_vec,
			w.n, nrefr))));
	else if (!mat.n && mat.reflection)
		return (add_2colors(get_light_value(w, newstart, mat, e),
			multiply_color(ft_resolve(e, newwork(w, reflected_ray(w.r.dir,
			w.n_vec, newstart), 0, e), lvl + 1), mat.reflection)));
	else
		return (get_light_value(w, newstart, mat, e));
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
	mat = find_material(itemstart, newstart, e);
	itemend = find_closest_item(newray, e, &newstart);
	w.n_vec = find_normal_vec(newray, itemend, e);
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
