/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:04:12 by squiquem          #+#    #+#             */
/*   Updated: 2018/12/20 15:53:07 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		hitquadric(t_ray r, t_item q, double *t)
{
	t_vec	sb;
	t_vec	rq;
	double	a;
	double	b;
	double	c;

	sb = newvec((r.start.x - q.center.x) / q.param.x, (r.start.y - q.center.y)
			/ q.param.y, (r.start.z - q.center.z) / q.param.z);
	rq = newvec(r.dir.x / q.param.x, r.dir.y / q.param.y, r.dir.z / q.param.z);
	a = dotproduct(r.dir, rq);
	b = 2 * dotproduct(rq, sub(r.start, q.center));
	c = dotproduct(sb, sub(r.start, q.center)) - 1;
	if (b * b - 4 * a * c < 0)
		return (0);
	else
		return (calc_discr(a, b, c, t));
}

t_vec	find_quadric_normal(t_vec impact, t_item q)
{
	t_vec	grad;

	grad.x = 2 * impact.x / q.param.x;
	grad.y = 2 * impact.y / q.param.y;
	grad.z = 2 * impact.z / q.param.z;
	if (magnitude(grad))
		grad = normalize(grad);
	return (grad);
}
