/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_cubic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:05:13 by asarasy           #+#    #+#             */
/*   Updated: 2019/01/08 17:02:53 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		cubic_polynom4(double d, double q, double *s)
{
	double u;

	u = sqrt(d) + q;
	d = sqrt(d) - q;
	if (d > 0)
		d = pow(d, 1.0 / 3.0);
	else if (d < 0)
		d = -pow(-d, 1.0 / 3.0);
	else
		d = 0;
	if (u > 0)
		u = pow(u, 1.0 / 3.0);
	else if (u < 0)
		u = -pow(-u, 1.0 / 3.0);
	else
		u = 0;
	s[0] = d - u;
	return (1);
}

int		cubic_polynom3(double q, double p, double *s)
{
	double phi;
	double t;

	phi = 1.0 / 3 * acos(-q / sqrt(-(pow(p, 3))));
	t = 2 * sqrt(-p);
	s[0] = t * cos(phi);
	s[1] = -t * cos(phi + M_PI / 3);
	s[2] = -t * cos(phi - M_PI / 3);
	return (3);
}

int		cubic_polynom2(double q, double *s)
{
	double u;

	if (q < 1e-9 && q > -1e-9)
	{
		s[0] = 0;
		return (1);
	}
	else
	{
		if (-q > 0)
			u = pow(-q, 1.0 / 3.0);
		else if (-q < 0)
			u = -pow(q, 1.0 / 3.00);
		else
			u = 0;
		s[0] = 2 * u;
		s[1] = -u;
		return (2);
	}
}

int		cubic_polynom(double *c, double *s)
{
	double	p;
	double	q;
	double	d;
	double	num;
	int		i;

	i = 0;
	p = 1.0 / 3 * (-1.0 / 3 * pow(c[2] / c[3], 2) + c[1] / c[3]);
	q = 1.0 / 2 * (2.0 / 27 * pow(c[2] / c[3], 3) - 1.0 / 3 * c[2] / c[3] *\
			c[1] / c[3] + c[0] / c[3]);
	d = pow(q, 2) + pow(p, 3);
	if (d < 1e-9 && d > 1e-9)
		num = cubic_polynom2(q, s);
	else if (d < 0)
		num = cubic_polynom3(q, p, s);
	else
		num = cubic_polynom4(d, q, s);
	p = 1.0 / 3 * c[2] / c[3];
	while (i < num)
	{
		s[i] -= p;
		i++;
	}
	return (num);
}
