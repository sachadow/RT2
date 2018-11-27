/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:12:07 by squiquem          #+#    #+#             */
/*   Updated: 2018/11/27 14:23:11 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color	find_texture_color(t_vec impact, t_work w, t_env *e)
{
	t_mat	m;
	t_item	item;

	item = e->item[w.item_hit];
	m = e->mat[item.mat];
	if (m.type == UNIFORM)
		return (m.diffuse);
	else if (m.type == TEXTURE || m.type == CHECKER || m.type == WAVES)
	{
		if (item.item_type == PLANE)
			return (texture_plane(m.tex, item, impact));
		else if (item.item_type == SPHERE)
			return (texture_sphere(m.tex, item, w));
		else if (item.item_type == I_CYL || item.item_type == F_CYL)
			return (texture_cylinder(m.tex, item, impact));
		else if (item.item_type == I_CONE || item.item_type == F_CONE)
			return (texture_cone(m.tex, item, impact));
		else
			return (e->backgroundcolor);
	}
	else if (m.type == MARBLE)
		return (color_marble(m.diffuse, m.diffuse2, impact));
	else if (m.type == PERTURB)
		return (color_turbulence(m.diffuse, m.diffuse2, impact));
	else
		return (e->backgroundcolor);
}

t_color	texture_plane(t_img tex, t_item item, t_vec impact)
{
	t_color	c;
	t_vec	d;
	t_vec	u;
	t_pix	p;

	if (magnitude(tex.center) && (fabs(dotproduct(item.dir, tex.center)
					- item.d) > 0.01f))
		ft_printerror("Texture center not on the obj");
	d = sub(impact, tex.center);
	u = (d.x == 0 && d.x == 0 && d.z == 1) ? newvec(0, 1, 0) : newvec(0, 0, 1);
	if (u.x == item.dir.x && u.y == item.dir.y && u.z == item.dir.z)
		u = newvec(1, 0, 0);
	p.x = (int)(dotproduct(d, u) * tex.w / tex.realw + tex.w / 2);
	p.y = (int)(dotproduct(d, crossproduct(item.dir, u)) * tex.h / tex.realh
			+ tex.h / 2);
	p = adjust_pix(p, tex.w, tex.h);
	p = rotate_pix(tex.angle, p);
	p = adjust_pix(p, tex.w, tex.h);
	get_img_color(tex, p, &c);
	return (c);
}

t_color	texture_sphere(t_img tex, t_item item, t_work w)
{
	t_color	c;
	t_pix	p;
	t_vec	k;

	if (magnitude(tex.center) && (fabs(magnitude(sub(item.center, tex.center))
					- item.radius) > 0.01f))
		ft_printerror("Texture center not on the obj");
	if (magnitude(item.center))
		k = normalize(sub(tex.center, item.center));
	p.x = (int)(((magnitude(tex.center) ? atan2(k.z, k.x) : 0.5)
		- atan2(w.n_vec.z, w.n_vec.x)) / (2 * M_PI) * tex.w * 1.5 * item.radius
		/ tex.realw + tex.w / 2);
	p.y = (int)((asin(w.n_vec.y) - (magnitude(tex.center) ? asin(k.y) : 0))
			/ M_PI * tex.h * 1.5 * item.radius / tex.realh + tex.h / 2);
	p = adjust_pix(p, tex.w, tex.h);
	p = rotate_pix(tex.angle, p);
	p = adjust_pix(p, tex.w, tex.h);
	get_img_color(tex, p, &c);
	return (c);
}

t_color	texture_cylinder(t_img tex, t_item item, t_vec impact)
{
	t_color		c;
	t_pix		p;
	t_matrix	m;
	t_vec		v;
	t_vec		u;

	if (magnitude(tex.center) && (fabs(magnitude(sub(sub(item.center,
			tex.center), scale(dotproduct(sub(item.center, tex.center),
			item.dir), item.dir))) - item.radius) > 0.01f))
		ft_printerror("Texture center not on the obj");
	u = sub(impact, item.center);
	v = sub(tex.center, item.center);
	m.colvec2 = crossproduct(item.dir, ((item.dir.x == 0 && item.dir.y == 0
					&& item.dir.z == 1) ? newvec(0, 1, 0) : newvec(0, 0, 1)));
	m.colvec3 = crossproduct(item.dir, m.colvec2);
	p.x = (int)((dotproduct(u, item.dir) - dotproduct(v, item.dir))
		* item.radius / tex.realw + tex.w / 2);
	p.y = (int)((atan(dotproduct(u, m.colvec2) / dotproduct(u, m.colvec3))
		- (magnitude(tex.center) ? atan(dotproduct(v, m.colvec2)
		/ dotproduct(v, m.colvec3)) : 0)) / M_PI * 2 * tex.h * item.radius
			/ tex.realh + tex.h / 2);
	p = adjust_pix(p, tex.w, tex.h);
	p = rotate_pix(tex.angle, p);
	p = adjust_pix(p, tex.w, tex.h);
	get_img_color(tex, p, &c);
	return (c);
}

t_color	texture_cone(t_img tex, t_item item, t_vec impact)
{
	t_color		c;
	t_pix		p;
	t_matrix	m;
	t_vec		v;
	t_vec		u;

	if (magnitude(tex.center) && (fabs(magnitude(sub(sub(item.center,
			tex.center), scale(dotproduct(sub(item.center, tex.center),
			item.dir), item.dir))) - magnitude(sub(impact, item.center))
			* cos(item.angle * M_PI / 180)) > 0.01f))
		ft_printerror("Texture center not on the obj");
	u = sub(impact, item.center);
	v = sub(tex.center, item.center);
	m.colvec2 = crossproduct(item.dir, ((item.dir.x == 0 && item.dir.y == 0
					&& item.dir.z == 1) ? newvec(0, 1, 0) : newvec(0, 0, 1)));
	m.colvec3 = crossproduct(item.dir, m.colvec2);
	p.x = (int)((dotproduct(u, item.dir) - dotproduct(v, item.dir))
		* 150 / tex.realw + tex.w / 2);
	p.y = (int)((atan(dotproduct(u, m.colvec2) / dotproduct(u, m.colvec3))
		- (magnitude(tex.center) ? atan(dotproduct(v, m.colvec2)
		/ dotproduct(v, m.colvec3)) : 0)) / M_PI * 2 * tex.h * 150
			/ tex.realh + tex.h / 2);
	p = adjust_pix(p, tex.w, tex.h);
	p = rotate_pix(tex.angle, p);
	p = adjust_pix(p, tex.w, tex.h);
	get_img_color(tex, p, &c);
	return (c);
}
