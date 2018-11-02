/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2018/10/22 14:40:45 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	COLOR_CALC function:
**	The loop is here for reflections
*/

t_color		color_calc(int x, int y, t_env *e)
{
	int		itemtype;
	int		curr;
	t_vec	newstart;
	t_work	w;

	w.c = e->backgroundcolor;
	w.coef = 1.0;
	w.r.start = e->cam->pos;
	w.r.dir = set_ray_dir(x, y, e);
	w.n = 1.0;
	itemtype = find_closest_item(w.r, e, &newstart, &curr);
	if (itemtype == EMPTY)
		return (e->backgroundcolor);
	w.n_vec = find_normal_vec(w.r, itemtype, curr, e);
	return (ft_resolve(e, w, 0));
}

/*
**	GET_LIGHT_VALUE function:
**	Calculation of the light value from diffusion and lighting
**	(Lambert diffusion & Blinn-Phuong reflection)
*/

t_color		get_light_value(t_work w, t_vec newstart, t_mat currmat,
			t_env *e)
{
	int		j;
	t_light	currlight;
	t_vec	dist;
	t_ray	lightray;
	t_color	c;

	c = e->backgroundcolor;
	j = -1;
	while (++j < e->nbs[LIGHT])
	{
		currlight = e->light[j];
		dist = sub(currlight.pos, newstart);
		if (dotproduct(w.n_vec, dist) <= 0.0f
			|| sqrt(magnitude2(dist)) <= 0.0f)
			continue;
		lightray.start = newstart;
		lightray.dir = normalize(dist);
		if (!in_shadow(lightray, e, sqrt(magnitude2(dist))))
		{
			color_lambert(&c, lambert(lightray, w.n_vec), currlight, currmat);
			color_blinnphuong(&c, blinnphuong(lightray, &w.r, w.n_vec,
						currmat), currlight);
		}
	}
	return (c);
}

/*
**	SET_RAY_DIR function:
**	Calculation of the ray parameters from the x and y (screen parameters)
*/

t_vec		set_ray_dir(int x, int y, t_env *e)
{
	t_vec	i;
	t_vec	j;
	t_vec	k;
	t_vec	l;

	k = e->cam->dir;
	if (k.x == 0.0f && k.y == 1.0f && k.z == 0.0f)
		l = newvec(0.0, 0.0, 1.0);
	else
		l = newvec(0.0, 1.0, 0.0);
	i = crossproduct(k, l);
	j = crossproduct(i, k);
	l.x = (IMG_W - (double)x * 2.0) / IMG_W * i.x
			+ (IMG_H - (double)y * 2.0) / IMG_W * j.x + FOV * k.x;
	l.y = (IMG_W - (double)x * 2.0) / IMG_W * i.y
			+ (IMG_H - (double)y * 2.0) / IMG_W * j.y + FOV * k.y;
	l.z = (IMG_W - (double)x * 2.0) / IMG_W * i.z
			+ (IMG_H - (double)y * 2.0) / IMG_W * j.z + FOV * k.z;
	l = normalize(l);
	return (l);
}
