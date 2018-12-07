/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_object3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:45:30 by asarasy           #+#    #+#             */
/*   Updated: 2018/12/06 12:08:01 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		get_fcyl(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	if (elem.nbr_attr < 6 || elem.nbr_attr > 8)
		std_err(0);
	e->item[i].item_type = 6;
	get_dir(e, elem, i, "dir");
	get_center(e, elem, i, "axispoint");
	get_radius(e, elem, i);
	get_material(e, elem, i, nbr_mat);
	get_height(e, elem, i);
	get_isNega(e, elem, i);
	if (elem.nbr_attr > 6)
	{
		j += get_translation(e, elem, i);
		j += get_rotation(e, elem, i);
		if (j + 6 != elem.nbr_attr)
			std_err(0);
	}
	return (0);
}

int		get_fcone(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	printf("1");
	if (elem.nbr_attr < 6 || elem.nbr_attr > 8)
		std_err(0);
	e->item[i].item_type = 7;
	get_dir(e, elem, i, "dir");
	get_center(e, elem, i, "axispoint");
	get_angle(e, elem, i);
	get_material(e, elem, i, nbr_mat);
	get_height(e, elem, i);
	get_isNega(e, elem, i);
	if (elem.nbr_attr > 6)
	{
		j += get_translation(e, elem, i);
		j += get_rotation(e, elem, i);
		if (j + 6 != elem.nbr_attr)
			std_err(0);
	}
	return (0);
}

int		get_box(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	if (elem.nbr_attr < 4 || elem.nbr_attr > 5)
		std_err(0);
	e->item[i].item_type = BOX;
	get_center(e, elem, i, "start");
	get_end(e, elem, i, "end");
	get_material(e, elem, i, nbr_mat);
	get_isNega(e, elem, i);
	if (elem.nbr_attr > 4)
	{
		j += get_translation(e, elem, i);
		if (j + 4 != elem.nbr_attr)
			std_err(0);
	}
	return (0);
}
