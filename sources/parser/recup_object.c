/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:18:27 by asarasy           #+#    #+#             */
/*   Updated: 2019/01/29 17:04:12 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rt.h"

int			free_checker_waves(t_mat *mat, int j)
{
	int i;

	i = 0;
	while(i < j)
	{
		if(mat[i].type == 2 || mat[i].type == 5)
			free(mat[i].tex.pixel_img);
		i++;
	}
	free(mat);
	return(0);
}

t_mat		cut_struct(t_mat *mat, int i)
{
	return (mat[i]);
}

int			soloobject(t_env *e, t_element elem, int i, t_mat *mat)
{
	if (ft_strcmp(elem.object, "sphere") == 0)
		get_sphere(e, elem, i, e->nbs[1]);
	else if (ft_strcmp(elem.object, "plane") == 0)
		get_plane(e, elem, i, e->nbs[1]);
	else if (ft_strcmp(elem.object, "icyl") == 0)
		get_lcyl(e, elem, i, e->nbs[1]);
	else if (ft_strcmp(elem.object, "icone") == 0)
		get_lcone(e, elem, i, e->nbs[1]);
	else if (ft_strcmp(elem.object, "disk") == 0)
		get_disk(e, elem, i, e->nbs[1]);
	else if (ft_strcmp(elem.object, "fcyl") == 0)
		get_fcyl(e, elem, i, e->nbs[1]);
	else if (ft_strcmp(elem.object, "fcone") == 0)
		get_fcone(e, elem, i, e->nbs[1]);
	else if (ft_strcmp(elem.object, "box") == 0)
		get_box(e, elem, i, e->nbs[1]);
	else if (ft_strcmp(elem.object, "quadric") == 0)
		get_quadric(e, elem, i, e->nbs[1]);
	else
		std_err(0);
	e->mat[i] = cut_struct(mat, e->item[i].mat);
	e->item[i].mat = i;
	return (0);
}

int			get_objects(t_element elem, t_env *e, t_mat *mat)
{
	int i;

	i = 0;
	if (elem.nbr_element == 0)
		std_err(0);
	if (!(e->item = (t_item*)malloc(sizeof(t_item) * elem.nbr_element)))
		std_err(0);
	if (!(e->mat = (t_mat*)malloc(sizeof(t_mat) * elem.nbr_element)))
		std_err(0);
	e->nbs[3] = elem.nbr_element;
	while (i < elem.nbr_element)
	{
		e->item[i].isnega = 0;
		soloobject(e, elem.elem[i], i, mat);
		i++;
	}
	return (0);
}

t_env		*recup_object(t_env *e, t_element elem, t_mat *mat)
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
			get_objects(elem.elem[i], e, mat);
			j++;
		}
		i++;
	}
	if (j == 0)
		std_err(0);
	//free_checker_waves(mat, e->nbs[1]);
	e->nbs[1] = e->nbs[3];
	return (e);
}
