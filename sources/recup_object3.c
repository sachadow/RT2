/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_object3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:45:30 by asarasy           #+#    #+#             */
/*   Updated: 2018/11/29 16:46:47 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		get_fcyl(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	if (elem.nbr_attr < 5 || elem.nbr_attr > 7)
		std_err(0);
	e->item[i].item_type = 6;
	e->item[i].dir = newvec(0, 0, 0);
	e->item[i].end = newvec(0, 0, 0);
	e->item[i].isNega = 0;
	e->item[i].d = 0;
	e->item[i].height = 0;
	e->item[i].radius = 0;
	e->item[i].angle = 0;
	get_dir(e, elem, i, "dir");
	get_center(e, elem, i, "axispoint");
	get_radius(e, elem, i);
	get_material(e, elem, i, nbr_mat);
	get_height(e, elem, i);
	if (elem.nbr_attr > 5)
	{
		j += get_translation(e, elem, i);
		j += get_rotation(e, elem, i);
		if (j + 5 != elem.nbr_attr)
			std_err(0);
	}
	return (0);
}

int		get_fcone(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	if (elem.nbr_attr < 5 || elem.nbr_attr > 7)
		std_err(0);
	e->item[i].item_type = 7;
	e->item[i].dir = newvec(0, 0, 0);
	e->item[i].end = newvec(0, 0, 0);
	e->item[i].isNega = 0;
	e->item[i].d = 0;
	e->item[i].height = 0;
	e->item[i].radius = 0;
	e->item[i].angle = 0;
	get_dir(e, elem, i, "dir");
	get_center(e, elem, i, "axispoint");
	get_angle(e, elem, i);
	get_material(e, elem, i, nbr_mat);
	get_height(e, elem, i);
	if (elem.nbr_attr > 5)
	{
		j += get_translation(e, elem, i);
		j += get_rotation(e, elem, i);
		if (j + 5 != elem.nbr_attr)
			std_err(0);
	}
	return (0);
}

int		get_box(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	if (elem.nbr_attr < 3 || elem.nbr_attr > 4)
		std_err(0);
	e->item[i].item_type = BOX;
	e->item[i].dir = newvec(0, 0, 0);
	e->item[i].end = newvec(0, 0, 0);
	e->item[i].isNega = 0;
	e->item[i].d = 0;
	e->item[i].height = 0;
	e->item[i].radius = 0;
	e->item[i].angle = 0;
	get_center(e, elem, i, "start");
	get_end(e, elem, i, "end");
	get_material(e, elem, i, nbr_mat);
	if (elem.nbr_attr > 3)
	{
		j += get_translation(e, elem, i);
		if (j + 3 != elem.nbr_attr)
			std_err(0);
	}
	return (0);
}
