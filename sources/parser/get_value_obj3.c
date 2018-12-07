/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_obj3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:17:57 by asarasy           #+#    #+#             */
/*   Updated: 2018/12/06 12:07:35 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int		get_isNega(t_env *e, t_element elem, int i)
{
	int j;

	j = 0;
	while (j < elem.nbr_attr && ft_strcmp(elem.attribut[j].name, "isneg"))
		j++;
	if (j == elem.nbr_attr)
		std_err(0);
	e->item[i].isNega = ft_posatoi(elem.attribut[j].content);
	if (e->item[i].isNega < 0 || e->item[i].isNega > 1)
		std_err(0);
	return (0);
}
