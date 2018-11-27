/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_mat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:14:56 by asarasy           #+#    #+#             */
/*   Updated: 2018/11/27 15:22:26 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			recup_checker_mat(t_env *e, t_element elem, int i, char *name)
{
	int nb;

	nb = 0;
	if (elem.nbr_attr < 7 || elem.nbr_attr > 8)
		std_err(0);
	if (ft_strcmp(name, "checker") == 0)
		e->mat[i].type = 2;
	else if (ft_strcmp(name, "marble") == 0)
		e->mat[i].type = 3;
	else if (ft_strcmp(name, "perturb") == 0)
		e->mat[i].type = 4;
	else if (ft_strcmp(name, "waves") == 0)
		e->mat[i].type = 5;
	else
		std_err(0);
	recup_value_mat(e, elem, i);
	recup_value_checker(e, elem, i);
	nb = get_bump(e, elem, i);
	if (elem.nbr_attr - nb != 7)
		std_err(0);
	return (0);
}

int			recup_texture_mat(t_env *e, t_element elem, int i)
{
	int j;
	int nb;

	nb = 0;
	j = 0;
	if (elem.nbr_attr < 9 || elem.nbr_attr > 11)
		std_err(0);
	e->mat[i].type = 1;
	recup_value_mat(e, elem, i);
	recup_value_text(e, elem, i);
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "angle"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->mat[i].tex.angle = ft_posatoi(elem.attribut[j].content);
	if (e->mat[i].tex.angle > 360)
		std_err(0);
	e->mat[i].tex.center = newvec(0, 0, 0);
	nb = get_bump(e, elem, i);
	if (elem.nbr_attr - nb == 9)
		return(0);
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "center"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->mat[i].tex.center = ft_getpos(elem.attribut[j].content);
	return (0);
}

int			recup_uniform_mat(t_env *e, t_element elem, int i)
{
	int j;
	int nb;

	j = 0;
	if (elem.nbr_attr < 6 || elem.nbr_attr > 7)
		std_err(0);
	e->mat[i].type = 0;
	recup_value_mat(e, elem, i);
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "diffusion"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->mat[i].diffuse = ft_getcolor(elem.attribut[j].content);
	nb = get_bump(e, elem, i);
	if (elem.nbr_attr - nb != 6)
		std_err(0);
	return (0);
}

int			get_mat(t_element elem, t_env *e)
{
	int i;

	i = 0;
	if (elem.nbr_element == 0)
		std_err(0);
	if (!(e->mat = (t_mat*)malloc(sizeof(t_mat) * elem.nbr_element)))
		std_err(0);
	e->nbs[1] = elem.nbr_element;
	while (i < elem.nbr_element)
	{
		if (ft_strcmp(elem.elem[i].object, "uniform") == 0)
			recup_uniform_mat(e, elem.elem[i], i);
		else if (ft_strcmp(elem.elem[i].object, "texture") == 0)
			recup_texture_mat(e, elem.elem[i], i);
		else
			recup_checker_mat(e, elem.elem[i], i, elem.elem[i].object);
		if (e->mat[i].reflection > 100 || e->mat[i].transparency > 100)
			std_err(0);
		i++;
	}
	return (0);
}

int			recup_mat(t_env *e, t_element elem)
{
	int i;
	int j;
	int nbr_mat;

	j = 0;
	i = 0;
	while (i < elem.nbr_element)
	{
		if (ft_strcmp(elem.elem[i].object, "material") == 0)
		{
			if (j == 1)
				std_err(0);
			get_mat(elem.elem[i], e);
			nbr_mat = elem.elem[i].nbr_element;
			j++;
		}
		i++;
	}
	if (j == 0)
		std_err(0);
	return (nbr_mat);
}
