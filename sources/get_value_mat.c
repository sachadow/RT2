/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_mat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:08:12 by asarasy           #+#    #+#             */
/*   Updated: 2018/11/29 14:46:50 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rt.h"
#include <stdio.h>

int		recup_value_checker(t_env *e, t_element elem, int i)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "diffusion"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->mat[i].diffuse = ft_getcolor(elem.attribut[j].content);
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name,\
				"diffusionbis"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->mat[i].diffuse2 = ft_getcolor(elem.attribut[j].content);
	return (0);
}

int		recup_value_text(t_env *e, t_element elem, int i)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "pathtext"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->mat[i].path_text = ft_strdup(elem.attribut[j].content);
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "width"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->mat[i].tex.realw = ft_posatoi(elem.attribut[j].content);
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "height"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->mat[i].tex.realh = ft_posatoi(elem.attribut[j].content);
	return (0);
}

int		get_bump(t_env *e, t_element elem, int i)
{
	int j;

	j = 0;
	e->mat[i].bump = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "bump"))
		j++;
	if (j == elem.nbr_attr)
		return (0);
	e->mat[i].bump = ft_posatoi(elem.attribut[j].content) / 100;
	if (e->mat[i].bump < 1 || e->mat[i].bump > 99)
		std_err(0);
	return (1);
}

int		recup_value_mat2(t_env *e, t_element elem, int i)
{
	int j;

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

int		recup_value_mat(t_env *e, t_element elem, int i)
{
	int j;

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
	e->mat[i].reflection = ft_posatoi(elem.attribut[j].content) / 100;
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "specvalue"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->mat[i].specvalue = ft_posatoi(elem.attribut[j].content) / 100;
	recup_value_mat2(e, elem, i);
	return (0);
}
