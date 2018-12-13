/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_obj3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:17:57 by asarasy           #+#    #+#             */
/*   Updated: 2018/12/11 12:23:12 by squiquem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		get_isnega(t_env *e, t_element elem, int i)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "isneg"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->item[i].isnega = ft_posatoi(elem.attribut[j].content);
	if (e->item[i].isnega < 0 || e->item[i].isnega > 1)
		std_err(0);
	return (0);
}
