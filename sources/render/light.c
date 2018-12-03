/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2018/12/02 19:47:19 by squiquem         ###   ########.fr       */
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

void		color_lambert(t_color *c, double l, t_light currl, t_color matdiff)
{
	c->red += l * currl.intensity.red * matdiff.red / 255 / 255;
	c->green += l * currl.intensity.green * matdiff.green / 255 / 255;
	c->blue += l * currl.intensity.blue * matdiff.blue / 255 / 255;
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
