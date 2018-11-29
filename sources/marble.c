/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:55:20 by squiquem          #+#    #+#             */
/*   Updated: 2018/11/27 18:59:32 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_color	color_marble(t_color c1, t_color c2, t_vec impact)
{
	int		lvl;
	double	noisecoef;

	lvl = 0;
	noisecoef = 0;
	impact = scale(0.5, impact);
	while (++lvl < 10)
		noisecoef += (1.0f / lvl) * fabs(noise(lvl * 0.05 * impact.x,
					lvl * 0.05 * impact.y, lvl * 0.05 * impact.z));
	noisecoef = 0.5f * sin((impact.x + impact.y) * 0.05 + noisecoef) + 0.5f;
	return (add_2colors(multiply_color(c1, noisecoef),
				multiply_color(c2, 1.0f - noisecoef)));
}

t_color	color_turbulence(t_color c1, t_color c2, t_vec impact)
{
	int		lvl;
	double	noisecoef;

	lvl = 0;
	noisecoef = 0;
	impact = scale(0.75, impact);
	while (++lvl < 10)
		noisecoef += (1.0f / lvl) * fabs(noise(lvl * 0.05 * impact.x,
					lvl * 0.05 * impact.y, lvl * 0.05 * impact.z));
	return (add_2colors(multiply_color(c1, noisecoef),
				multiply_color(c2, 1.0f - noisecoef)));
}

t_color	color_wood(t_color c1, t_color c2, t_vec impact)
{
	int		lvl;
	double	grain;

	lvl = 0;
	impact = scale(0.001, impact);
	grain = noise(impact.x, impact.y, impact.z);
	grain *= 5;
	grain = grain - (int)grain;
	return (add_2colors(multiply_color(c1, grain),
				multiply_color(c2, 1.0f - grain)));
}


t_vec	bumpmapping(t_vec n, t_vec impact, t_mat m)
{
	t_vec	noisecoef;
	t_vec	res;

	if (!m.bump)
		return (n);
	//matbump = 0.1;
	noisecoef.x = noise(0.1 * impact.x, 0.1 * impact.y, 0.1 * impact.z);
	noisecoef.y = noise(0.1 * impact.y, 0.1 * impact.z, 0.1 * impact.x);
	noisecoef.z = noise(0.1 * impact.z, 0.1 * impact.x, 0.1 * impact.y);
	res.x = (1.0f - m.bump) * n.x + m.bump * noisecoef.x;
	res.y = (1.0f - m.bump) * n.y + m.bump * noisecoef.y;
	res.z = (1.0f - m.bump) * n.z + m.bump * noisecoef.z;
	//res = add(scale(1.0f - m.bump, n), scale(m.bump, noisecoef));
	return (normalize(res));
}
