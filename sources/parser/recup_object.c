/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:18:27 by asarasy           #+#    #+#             */
/*   Updated: 2018/12/11 12:15:12 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rt.h"

int		soloobject(t_env *e, t_element elem, int i, int nbr_mat)
{
	if (ft_strcmp(elem.object, "sphere") == 0)
		get_sphere(e, elem, i, nbr_mat);
	else if (ft_strcmp(elem.object, "plane") == 0)
		get_plane(e, elem, i, nbr_mat);
	else if (ft_strcmp(elem.object, "icyl") == 0)
		get_lcyl(e, elem, i, nbr_mat);
	else if (ft_strcmp(elem.object, "icone") == 0)
		get_lcone(e, elem, i, nbr_mat);
	else if (ft_strcmp(elem.object, "disk") == 0)
		get_disk(e, elem, i, nbr_mat);
	else if (ft_strcmp(elem.object, "fcyl") == 0)
		get_fcyl(e, elem, i, nbr_mat);
	else if (ft_strcmp(elem.object, "fcone") == 0)
		get_fcone(e, elem, i, nbr_mat);
	else if (ft_strcmp(elem.object, "box") == 0)
		get_box(e, elem, i, nbr_mat);
	else
		std_err(0);
	return (0);
}

int		get_objects(t_element elem, t_env *e, int nbr_mat)
{
	int i;

	i = 0;
	if (elem.nbr_element == 0)
		std_err(0);
	if (!(e->item = (t_item*)malloc(sizeof(t_item) * elem.nbr_element)))
		std_err(0);
	e->nbs[3] = elem.nbr_element;
	while (i < elem.nbr_element)
	{
		e->item[i].isnega = 0;
		soloobject(e, elem.elem[i], i, nbr_mat);
		i++;
	}
	return (0);
}

t_env	*recup_object(t_env *e, t_element elem, int nbr_mat)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < elem.nbr_element)
	{
		if (ft_strcmp(elem.elem[i].object, "objects") == 0)
		{
			if (j == 1 || elem.elem[i].nbr_attr > 0)
				std_err(0);
			get_objects(elem.elem[i], e, nbr_mat);
			j++;
		}
		i++;
	}
	if (j == 0)
		std_err(0);
	return (e);
}
