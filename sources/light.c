/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2018/11/02 17:48:39 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	LAMBERT function:
**	Returns the lambert coefficient (for shape shadow)
*/

double		lambert(t_ray lightray, t_vec n)
{
	double	f;

	f = dotproduct(lightray.dir, n);
	return (f);
}

/*
**	COLOR_LAMBERT function:
*/

void		color_lambert(t_color *c, double l, t_light currl, t_mat currm)
{
	c->red += l * currl.intensity.red * currm.diffuse.red / 255 / 255;
	c->green += l * currl.intensity.green * currm.diffuse.green / 255 / 255;
	c->blue += l * currl.intensity.blue * currm.diffuse.blue / 255 / 255;
}

/*
**	BLINNPHUONG function:
**	Returns the Blinn-Phuong coefficient (for bright)
*/

double		blinnphuong(t_ray lightray, t_ray *r, t_vec n, t_mat currmat)
{
	t_vec	blinndir;
	double	blinnterm;

	blinndir = sub(lightray.dir, r->dir);
	if (magnitude2(blinndir) != 0)
	{
		blinndir = normalize(blinndir);
		blinnterm = ft_max(dotproduct(blinndir, n), 0.0f);
		blinnterm = currmat.specvalue * powf(blinnterm, currmat.specpower);
	}
	else
		blinnterm = 0;
	return (blinnterm);
}

/*
**	COLOR_BLINNPHUONG function:
**	Changes the color to add the BP coefficient according to the color
*/

void		color_blinnphuong(t_color *c, double b, t_light currl)
{
	c->red += b * currl.intensity.red / 255;
	c->green += b * currl.intensity.green / 255;
	c->blue += b * currl.intensity.blue / 255;
}

/*
**	IN_SHADOW function:
**	Determines if the point is in the shadow
*/

int			in_shadow(t_ray lightray, t_env *e, double t)
{
	int		k;
	int		(*hit[10])(t_ray, t_item, double *);

	hit[SPHERE] = &hitsphere;
	hit[PLANE] = &hitplane;
	hit[I_CONE] = &hitcone;
	hit[I_CYL] = &hitcylinder;
	hit[DISK] = &hitdisk;
	hit[F_CYL] = &hitfcylinder;
	hit[F_CONE] = &hitfcone;
	k = -1;
	while (++k < e->nbs[3])
		if (hit[e->item[k].item_type](lightray, e->item[k], &t) && t > 0.001 &&
				e->item[k].isNega == 0)
			return (1);
	return (0);
}
