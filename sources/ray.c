/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2018/11/09 15:59:47 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	COLOR_CALC function:
**	The loop is here for reflections
*/

t_color		color_calc(int x, int y, t_env *e)
{
	t_work	w;
	int		i;

	w.c = e->backgroundcolor;
	w.coef = 1.0;
	w.r.start = e->cam->pos;
	w.r.dir = set_ray_dir(x, y, e);
	w.n = 1.000;
	i = -1;
	while (++i < REFRINCL)
		w.id[i] = -1;
	return (ft_resolve(e, w, 0));
}

/*
**	GET_LIGHT_VALUE function:
**	Calculation of the light value from diffusion and lighting
**	(Lambert diffusion & Blinn-Phuong reflection)
*/

t_color		get_light_value(t_work w, t_vec newstart, t_mat mat, t_env *e)
{
	int		j;
	t_vec	dist;
	t_ray	lightray;
	t_color	c;
	int		inshdw;

	c = e->backgroundcolor;
	j = -1;
	while (++j < e->nbs[LIGHT])
	{
		dist = sub(e->light[j].pos, newstart);
		if (dotproduct(w.n_vec, dist) <= 0.0f
			|| sqrt(magnitude2(dist)) <= 0.0f)
			continue;
		lightray.start = newstart;
		lightray.dir = normalize(dist);
		inshdw = in_shadow(lightray, e, sqrt(magnitude2(dist)));
		if (inshdw == EMPTY || e->mat[e->item[inshdw].mat].n)
		{
			color_lambert(&c, lambert(lightray, w.n_vec), e->light[j], mat);
			color_blinnphuong(&c, blinnphuong(lightray, &w.r, w.n_vec,
						mat), e->light[j]);
		}
		if (inshdw != -1 && e->mat[e->item[inshdw].mat].n)
			c = multiply_color(c, e->mat[e->item[inshdw].mat].transparency);
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
	l = (k.x == 0.0f && k.y == 1.0f && k.z == 0.0f) ?
		newvec(0.0, 0.0, 1.0) : newvec(0.0, 1.0, 0.0);
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
