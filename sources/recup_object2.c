/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:13:14 by asarasy           #+#    #+#             */
/*   Updated: 2018/11/13 18:14:03 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		get_sphere(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	if (elem.nbr_attr != 3)
		std_err(0);
	e->item[i].item_type = 1;
	get_center(e, elem, i, "center");
	get_radius(e, elem, i);
	get_material(e, elem, i, nbr_mat);
	return (0);
}

int		get_plane(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	if (elem.nbr_attr != 3)
		std_err(0);
	e->item[i].item_type = 2;
	get_dir(e, elem, i, "normale");
	get_d(e, elem, i);
	get_material(e, elem, i, nbr_mat);
	return (0);
}

int		get_lcyl(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	if (elem.nbr_attr != 4)
		std_err(0);
	e->item[i].item_type = 4;
	get_dir(e, elem, i, "dir");
	get_center(e, elem, i, "axispoint");
	get_radius(e, elem, i);
	get_material(e, elem, i, nbr_mat);
	e->item[i].d = 0;
	e->item[i].angle = 0;
	return (0);
}

int		get_lcone(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	if (elem.nbr_attr != 4)
		std_err(0);
	e->item[i].item_type = 3;
	get_dir(e, elem, i, "dir");
	get_center(e, elem, i, "axispoint");
	get_angle(e, elem, i);
	get_material(e, elem, i, nbr_mat);
	e->item[i].radius = 0;
	e->item[i].d = 0;

	return (0);
}

int		get_disk(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	if (elem.nbr_attr != 4)
		std_err(0);
	e->item[i].item_type = 5;
	get_dir(e, elem, i, "dir");
	get_center(e, elem, i, "axispoint");
	get_radius(e, elem, i);
	get_material(e, elem, i, nbr_mat);
	return (0);
}
