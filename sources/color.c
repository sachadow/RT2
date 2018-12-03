/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 00:34:11 by squiquem          #+#    #+#             */
/*   Updated: 2018/10/22 14:41:12 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	MULTIPLY_COLOR function:
**	Multiplies the RGB values by a double
*/

t_color			multiply_color(t_color c, double k)
{
	t_color c2;

	c2.red = c.red * k;
	c2.green = c.green * k;
	c2.blue = c.blue * k;
	return (c2);
}

/*
**	ADD_COLORS function:
**	Adds 2 colors
*/

t_color			add_colors(t_color a, t_color b)
{
	t_color	c;

	c.red = a.red + b.red;
	c.green = a.green + b.green;
	c.blue = a.blue + b.blue;
	return (c);
}
