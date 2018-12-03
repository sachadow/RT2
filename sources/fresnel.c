/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresnel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 13:45:09 by squiquem          #+#    #+#             */
/*   Updated: 2018/10/22 14:41:50 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	REFRACTED_RAY function:
**	Calculates the new ray produced by refraction
*/

t_ray	refracted_ray(t_vec inc, t_vec norm, double n, t_vec newstart)
{
	double	c1;
	double	c2;
	t_ray	r;

	c1 = dotproduct(norm, inc);
	c2 = sqrtf(1 - n * n * (1 - c1 * c1));
	r.dir = add(scale(n, inc), scale(n * c1 - c2, norm));
	r.start = newstart;
	return (r);
}

/*
**	REFLECTED_RAY function:
**	Calculates the new ray produced by reflection
*/

t_ray	reflected_ray(t_vec inc, t_vec norm, t_vec newstart)
{
	double	f;
	t_vec	tmp;
	t_ray	r;

	f = dotproduct(inc, norm);
	tmp = scale(2.0f * f, norm);
	r.dir = sub(inc, tmp);
	r.start = newstart;
	return (r);
}

/*
**	FRESNEL function:
**	Calculates the Fresnel coefficient for the reflection
*/

double	fresnel(t_vec i, t_vec n, double n1, double n2)
{
	double	cosi;
	double	etai;
	double	etat;
	double	sint;
	double	cost;

	cosi = ft_clamp(-1, 1, dotproduct(i, n));
	etai = n1;
	etat = n2;
	if (cosi > 0)
		ft_dswap(&etai, &etat);
	sint = etai / etat * sqrt(ft_max(0.f, 1 - cosi * cosi));
	if (sint >= 1)
		return (1);
	else
	{
		cost = sqrt(ft_max(0.f, 1 - sint * sint));
		cosi = ft_abs(cosi);
		return ((pow(((etat * cosi) - (etai * cost)) / ((etat * cosi) + (etai *
			cost)), 2) + pow(((etai * cosi) - (etat * cost)) / ((etai * cosi) +
			(etat * cost)), 2)) / 2);
	}
}
