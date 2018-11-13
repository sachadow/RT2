/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squiquem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:19:32 by squiquem          #+#    #+#             */
/*   Updated: 2018/11/13 15:21:42 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
**	NEWCOLOR function:
**	Create a new color with 3 parameters
*/

t_color		newcolor(double r, double g, double b)
{
	t_color	c;

	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		ft_printerror("Wrong value for color");
	c.red = r;
	c.green = g;
	c.blue = b;
	return (c);
}

/*
**	NEWSH function:
**	Create a new sphere with 3 parameters
*/

t_item		newsph(t_vec center, double radius, int mat, int isNega)
{
	t_item	sph;

	if (radius <= 0 || mat < 0)
		ft_printerror("Wrong value for sphere");
	sph.item_type = SPHERE;
	sph.dir = newvec(0, 0, 0);
	sph.isNega = isNega;
	sph.center = center;
	sph.radius = radius;
	sph.mat = mat;
	sph.d = 0;
	sph.angle = 0;
	return (sph);
}

/*
**	NEWPLANE function:
**	Create a new plane with 3 parameters
*/

t_item		newplane(t_vec dir, double d, int mat)
{
	t_item	p;

	if (mat < 0)
		ft_printerror("Wrong value for plane");
	p.item_type = PLANE;
	p.dir = dir;
	p.center = newvec(0, 0, 0);
	p.isNega = 0;
	p.radius = 0;
	p.mat = mat;
	p.d = d;
	p.angle = 0;
	return (p);
}

/*
**	NEWCYL function:
**	Create a new cylinder with 4 parameters
*/

t_item		newcyl(t_vec dir, t_vec center, double radius, int mat, int isNega)
{
	t_item	cy;

	if (radius <= 0 || mat < 0)
		ft_printerror("Wrong value for cylinder");
	cy.item_type = I_CYL;
	cy.dir = dir;
	cy.isNega = isNega;
	cy.center = center;
	cy.radius = radius;
	cy.mat = mat;
	cy.d = 0;
	cy.angle = 0;
	return (cy);
}

/*
**	NEWCONE function:
**	Create a new cone with 4 parameters
*/

t_item		newcone(t_vec dir, t_vec center, double angle, int mat, int isNega)
{
	t_item	co;

	if (angle <= 0 || angle >= 70 || mat < 0)
		ft_printerror("Wrong value for cone");
	co.item_type = I_CONE;
	co.dir = dir;
	co.center = center;
	co.isNega = isNega;
	co.radius = 0;
	co.mat = mat;
	co.d = 0;
	co.angle = angle;
	return (co);
}

t_item		newdisk(t_vec dir, t_vec center, double radius, int mat)
{
	t_item	cy;

	if (radius <= 0 || mat < 0)
		ft_printerror("Wrong value for cylinder");
	cy.item_type = DISK;
	cy.dir = dir;
	cy.center = center;
	cy.isNega = 0;
	cy.radius = radius;
	cy.mat = mat;
	cy.d = 0;
	cy.angle = 0;
	return (cy);
}

t_item		newfcyl(t_vec dir, t_vec center, double radius, int mat, double height, int isNega)
{
	t_item	cy;

	cy.item_type = F_CYL;
	cy.dir = dir;
	cy.center = center;
	cy.radius = radius;
	cy.mat = mat;
	cy.isNega = isNega;
	cy.height = height;
	cy.d = 0;
	cy.angle = 0;
	return (cy);
}

t_item		newfcone(t_vec dir, t_vec center, double angle, int mat, double height, int isNega)
{
	t_item	co;

	if (angle <= 0 || angle >= 70 || mat < 0)
		ft_printerror("Wrong value for cone");
	co.item_type = F_CONE;
	co.dir = dir;
	co.center = center;
	co.radius = 0;
	co.mat = mat;
	co.isNega = isNega;
	co.height = height;
	co.d = 0;
	co.angle = angle;
	return (co);
}

t_item  newbox(t_vec center, t_vec end, int mat)
{
	t_item bo;

	bo.item_type = BOX;
	bo.center = center;
	bo.end = end;
	bo.mat = mat;
	bo.isNega = 0;
	return (bo);
}
