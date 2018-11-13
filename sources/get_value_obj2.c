/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_obj2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:24:23 by asarasy           #+#    #+#             */
/*   Updated: 2018/11/13 17:19:18 by sderet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		get_angle(t_env *e, t_element elem, int i)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "angle"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->item[i].angle = ft_posatoi(elem.attribut[j].content);
	if (e->item[i].angle == 0 || e->item[i].angle >= 70)
		std_err(0);
	return (0);
}

int		get_height(t_env *e, t_element elem, int i)
{
	int j;

	j = 0;
	(void)i;
	(void)e;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "height"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->item[i].height = ft_posatoi(elem.attribut[j].content);
	if (e->item[i].height == 0)
		std_err(0);
	return (0);
}
