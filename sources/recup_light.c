/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:30:35 by asarasy           #+#    #+#             */
/*   Updated: 2018/11/28 16:53:10 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rt.h"

int		ambiantlight(t_env *e, t_element elem)
{
	if (elem.nbr_attr != 1)
		std_err(0);
	if (ft_strcmp(elem.attribut[0].name, "color") != 0)
		std_err(0);
	e->backgroundcolor = ft_getcolor(elem.attribut[0].content);
	return (1);
}

int		sololight(t_env *e, t_element elem, int i)
{
	int j;

	j = 0;
	if (elem.nbr_attr > 3)
		std_err(0);
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "pos"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->light[i].pos = ft_getpos(elem.attribut[j].content);
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "intensity"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->light[i].intensity = ft_getcolor(elem.attribut[j].content);
	if (elem.nbr_attr == 2)
		return (1);
	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "translation"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->light[i].pos = add(e->light[i].pos, ft_getpos(elem.attribut[j].content));
	return (1);
}

int		get_light(t_element elem, t_env *e)
{
	int i;
	int j;
	int p;

	p = 0;
	j = 0;
	i = 0;
	if (elem.nbr_element == 0)
		std_err(0);
	if (!(e->light = (t_light*)malloc(sizeof(t_light) * elem.nbr_element - 1)))
		std_err(0);
	e->nbs[2] = elem.nbr_element - 1;
	while (i < elem.nbr_element)
	{
		if (ft_strcmp(elem.elem[i].object, "sublight") == 0)
			p += sololight(e, elem.elem[i], p);
		else if (ft_strcmp(elem.elem[i].object, "ambiant") == 0)
			j += ambiantlight(e, elem.elem[i]);
		else
			std_err(0);
		i++;
	}
	if (j != 1 || elem.nbr_attr > 0)
		std_err(0);
	return (0);
}

t_env	*recup_light(t_env *e, t_element elem)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < elem.nbr_element)
	{
		if (ft_strcmp(elem.elem[i].object, "light") == 0)
		{
			if (j == 1)
				std_err(0);
			get_light(elem.elem[i], e);
			j++;
		}
		i++;
	}
	if (j == 0)
		std_err(0);
	return (e);
}
