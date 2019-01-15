/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_items_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sderet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:32:50 by sderet            #+#    #+#             */
/*   Updated: 2019/01/15 17:07:09 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	HITPLANE function:
**	Returns 1 if the plane is hit and change the parameter t, else 0
*/

int		hitplane(t_ray r, t_item p, double *t)
{
	double	t0;

	if (dotproduct(p.dir, r.dir) != 0)
	{
		t0 = -(dotproduct(p.dir, r.start) + p.d)
			/ dotproduct(p.dir, r.dir);
		if (t0 > 0.001f && (*t == -1 || t0 < *t))
		{
			*t = t0;
			return (1);
		}
		else
			return (0);
	}
	else
		return (0);
}

int		closest_disk(t_ray r, t_item cy, double *t)
{
	int		ret;
	double	hit;
	double	hit2;

	hit = -1;
	hit2 = -1;
	ret = (hitdisk(r, newdisk(cy.dir, cy.center, cy.radius, cy.mat), &hit));
	if (ret == 0)
		ret = (hitdisk(r, newdisk(cy.dir, add(cy.center, scale(cy.height,
								cy.dir)), cy.radius, cy.mat), &hit2));
	if ((hit > hit2 && hit2 > -1) || (hit == -1 && hit2 != -1))
	{
		*t = hit2;
		return (1);
	}
	else if ((hit2 > hit && hit > -1) || (hit2 == -1 && hit != -1))
	{
		*t = hit;
		return (1);
	}
	else
		return (0);
}

int		hitfcylinder(t_ray r, t_item cy, double *t)
{
	double	hit;
	double	sign;
	t_vec	intersection;

	hit = *t;
	if (!hitcylinder(r, cy, &hit))
		return (0);
	intersection = add(r.start, scale(hit, r.dir));
	sign = dotproduct(cy.dir, sub(intersection, cy.center)) /
		magnitude2(cy.dir);
	if (sign < 0)
		return (hitdisk(r, newdisk(cy.dir, cy.center, cy.radius, cy.mat), t));
	else if (sign > cy.height)
		return (hitdisk(r, newdisk(cy.dir, add(cy.center, scale(cy.height,
								cy.dir)), cy.radius, cy.mat), t));
	else
	{
		*t = hit;
		return (1);
	}
}

int		hitfcone(t_ray r, t_item cy, double *t)
{
	double	hit;
	double	sign;
	t_vec	intersection;
	t_vec	tmp;

	hit = *t;
	if (!hitcone(r, cy, &hit))
		return (0);
	intersection = add(r.start, scale(hit, r.dir));
	sign = dotproduct(cy.dir, sub(intersection, cy.center)) /
		magnitude2(cy.dir);
	if (sign > cy.height)
	{
		tmp = find_h(cy.dir, cy.center, intersection);
		return (hitdisk(r, newdisk(cy.dir, add(cy.center, scale(cy.height,
								cy.dir)), sqrt(magnitude2(sub(tmp,
								intersection))), cy.mat), t));
	}
	else if (sign <= 0)
		return (0);
	else
	{
		*t = hit;
		return (1);
	}
}
