/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:08:09 by asarasy           #+#    #+#             */
/*   Updated: 2019/01/08 17:03:44 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		quadric_polynom(double *c, double *s)
{
	double	p;
	double	q;
	double	d;

	p = c[1] / (2 * c[2]);
	q = c[0] / c[2];
	d = p * p - q;
	if (d < 1e-9 && d > -1e-9)
	{
		s[0] = -p;
		return (1);
	}
	else if (d < 0)
		return (0);
	else
	{
		s[0] = sqrt(d) - p;
		s[1] = -sqrt(d) - p;
		return (2);
	}
}

int		quartic_polynom4(double *c, double *s, double *u, double *p)
{
	int num;

	c[0] = u[2] - u[0];
	c[1] = p[1] < 0 ? -u[1] : u[1];
	c[2] = 1;
	num = quadric_polynom(c, s);
	c[0] = u[2] + u[0];
	c[1] = p[1] < 0 ? u[1] : -u[1];
	c[2] = 1;
	num += quadric_polynom(c, s + num);
	return (num);
}

int		quartic_polynom2(double *c, double *s, double *p)
{
	int		num;
	double	u[3];

	u[2] = s[0];
	u[0] = s[0] * s[0] - p[2];
	u[1] = 2 * s[0] - p[0];
	if (u[0] < 1e-9 && u[0] > -1e-9)
		u[0] = 0;
	else if (u[0] > 0)
		u[0] = sqrt(u[0]);
	else
		return (0);
	if (u[1] < 1e-9 && u[1] > -1e-9)
		u[1] = 0;
	else if (u[1] > 0)
		u[1] = sqrt(u[1]);
	else
		return (0);
	num = quartic_polynom4(c, s, u, p);
	return (num);
}

int		quartic_polynom3(double *c, double *s, double *p, double *coeffs)
{
	int num;

	p[0] = -3.0 / 8 * pow(c[3] / c[4], 2) + c[2] / c[4];
	p[1] = 1.0 / 8 * pow(c[3] / c[4], 3) - 1.0 / 2 * c[3] / c[4] * c[2] / c[4] \
		+ c[1] / c[4];
	p[2] = -3.0 / 256 * pow(c[3] / c[4], 4) + 1.0 / 16 * pow(c[3] / c[4], 2) *\
		c[2] / c[4] - 1.0 / 4 * c[3] / c[4] * c[1] / c[4] + c[0] / c[4];
	if (p[2] < 1e-9 && p[2] > -1e-9)
	{
		coeffs[0] = p[1];
		coeffs[1] = p[0];
		coeffs[2] = 0;
		coeffs[3] = 1;
		num = cubic_polynom(coeffs, s);
	}
	else
	{
		coeffs[0] = 1.0 / 2 * p[2] * p[0] - 1.0 / 8 * p[1] * p[1];
		coeffs[1] = -p[2];
		coeffs[2] = -1.0 / 2 * p[0];
		coeffs[3] = 1;
		cubic_polynom(coeffs, s);
		num = quartic_polynom2(coeffs, s, p);
	}
	return (num);
}

int		quartic_polynom(double *c, double *s)
{
	double		coeffs[4];
	int			i;
	double		p[3];
	int			num;

	i = 0;
	num = quartic_polynom3(c, s, p, coeffs);
	while (i < num)
	{
		s[i] -= 1.0 / 4 * c[3] / c[4];
		i++;
	}
	return (num);
}
