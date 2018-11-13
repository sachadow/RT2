/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_object3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:45:30 by asarasy           #+#    #+#             */
/*   Updated: 2018/11/13 17:15:16 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		get_fcyl(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	if (elem.nbr_attr != 5)
		std_err(0);
	e->item[i].item_type = 6;
	get_dir(e, elem, i, "dir");
	get_center(e, elem, i, "axispoint");
	get_radius(e, elem, i);
	get_material(e, elem, i, nbr_mat);
	get_height(e, elem, i);
	return (0);
}

int		get_fcone(t_env *e, t_element elem, int i, int nbr_mat)
{
	int j;

	j = 0;
	if (elem.nbr_attr != 5)
		std_err(0);
	e->item[i].item_type = 7;
	get_dir(e, elem, i, "dir");
	get_center(e, elem, i, "axispoint");
	get_angle(e, elem, i);
	get_material(e, elem, i, nbr_mat);
	get_height(e, elem, i);
	return (0);
}
