/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_mat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 13:14:56 by asarasy           #+#    #+#             */
/*   Updated: 2018/11/12 13:55:59 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			solomat2(t_env *e, t_element elem, int i)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "specvalue"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->mat[i].specvalue = ft_posatoi(elem.attribut[j].content) / 100;
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "specpower"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->mat[i].specpower = ft_posatoi(elem.attribut[j].content);
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "n"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->mat[i].n = ft_posatoi(elem.attribut[j].content) / 1000;
	return (0);
}

int			solomat(t_env *e, t_element elem, int i)
{
	int j;

	j = 0;
	if (ft_strcmp(elem.object, "submaterial") != 0 || elem.nbr_attr != 6)
		std_err(0);
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "diffusion"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->mat[i].diffuse = ft_getcolor(elem.attribut[j].content);
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "t"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->mat[i].transparency = ft_posatoi(elem.attribut[j].content) / 100;
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "reflexion"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	solomat2(e, elem, i);
	e->mat[i].reflection = ft_posatoi(elem.attribut[j].content) / 100;
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
		solomat(e, elem.elem[i], i);
		if(e->mat[i].reflection > 100 || e->mat[i].transparency > 100)
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
