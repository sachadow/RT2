/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2018/11/12 16:40:37 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	MULTIPLY_COLOR function:
**	Multiplies the RGB values by a double
*/

t_color			multiply_color(t_color c, double k)
{
	if (k == 0.00f)
		return (newcolor(0, 0, 0));
	else
		return (newcolor(c.red * k, c.green * k, c.blue * k));
}

/*
**	ADD_2COLORS function:
**	Adds 2 colors
*/

t_color			add_2colors(t_color a, t_color b)
{
	t_color	c;

	c.red = a.red + b.red;
	c.green = a.green + b.green;
	c.blue = a.blue + b.blue;
	return (c);
}

/*
**	ADD_3COLORS function:
**	Adds 3 colors
*/

t_color			add_3colors(t_color a, t_color b, t_color c)
{
	t_color	d;

	d.red = a.red + b.red + c.red;
	d.green = a.green + b.green + c.green;
	d.blue = a.blue + b.blue + c.blue;
	return (d);
}
