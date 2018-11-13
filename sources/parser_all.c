/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:23:27 by asarasy           #+#    #+#             */
/*   Updated: 2018/11/12 12:12:12 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rt.h"
#include <stdio.h>

int			print_elem(t_env *e)
{
	int i;

	i = 0;
	printf("x = %f / y = %f / z = %f\n", e->light[0].pos.x, e->light[0].pos.y, e->light[0].pos.z);
	printf("r = %f, g = %f , b = %f\n", e->light[0].intensity.red, e->light[0].intensity.green, e->light[0].intensity.blue);
	printf("x = %f, y = %f, z = %f\n", e->cam->pos.x,e->cam->pos.y,e->cam->pos.z);
	printf("x = %f, y = %f, z = %f\n", e->cam->dir.x,e->cam->dir.y,e->cam->dir.z);
	while (i < 3)
	{
		printf("r = %f, g = %f , b = %f\n", e->mat[i].diffuse.red, e->mat[i].diffuse.green, e->mat[i].diffuse.blue);
		printf("ref =  %f, specval = %f, specpow = %f, n = %f\n", e->mat[i].reflection, e->mat[i].specvalue, e->mat[i].specpower, e->mat[i].n);
		i++;
	}




	return(0);
}

t_env		*parser_all(char *file, t_env *e)
{
	t_element	elem;

	elem.nbr_attr = 0;
	elem = parser_xml(file, elem);
	e = recup_env(e, elem);
	//print_elem(e);
	e->cam->dir = normalize(e->cam->dir);
	e->nbs[0] = 1;
	return(e);
}
