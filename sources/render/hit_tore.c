/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_tore.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:44:28 by asarasy           #+#    #+#             */
/*   Updated: 2019/01/08 17:21:39 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int		hittore2(double *c, double *t)
{
	int		i[3];
	double	solution[4];

	i[0] = 0;
	c[3] /= c[4];
	c[2] /= c[4];
	c[1] /= c[4];
	c[0] /= c[4];
	c[4] = 1;
	i[1] = quartic_polynom(c, solution);
	i[2] = 0;
	while (i[0] < i[1])
	{
		if (solution[i[0]] > 0.001f && (*t = -1 || solution[i[0]] < *t))
		{
			*t = solution[i[0]];
			i[2]++;
		}
		i[0]++;
	}
	if (i[2] > 0)
		return (1);
	return (0);
}

int		hittore(t_ray r, t_item tor, double *t)
{
	double	c[5];
	t_vec	dist;
	double	m[5];

	dist = sub(r.start, tor.center);
	m[0] = magnitude2(r.dir);
	m[1] = dotproduct(r.dir, dist);
	m[2] = magnitude2(dist);
	m[3] = dotproduct(r.dir, tor.dir);
	m[4] = dotproduct(dist, tor.dir);
	c[4] = m[0] * m[0];
	c[3] = 4 * m[0] * m[1];
	c[2] = 4 * m[1] * m[1] + 2 * m[0] * (m[2] - tor.radius2 * tor.radius2 \
			- tor.radius * tor.radius) + 4 * tor.radius * tor.radius * \
			m[3] * m[3];
	c[1] = 4 * m[1] * (m[2] - tor.radius2 * tor.radius2 - tor.radius * \
			tor.radius) + 8 * tor.radius * tor.radius * m[3] * m[4];
	c[0] = (m[2] - tor.radius2 * tor.radius2 - tor.radius * tor.radius) *
		(m[2] - tor.radius2 * tor.radius2 - tor.radius * tor.radius) \
		+ 4 * tor.radius * tor.radius * m[4] * m[4] \
		- 4 * tor.radius * tor.radius * tor.radius2 * tor.radius2;
	return (hittore2(c, t));
}
