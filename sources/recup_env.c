/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarasy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:25:37 by asarasy           #+#    #+#             */
/*   Updated: 2018/11/09 10:58:50 by asarasy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "rt.h"

int		free_all_attributes(t_attribut attribut)
{
	ft_memdel((void**)&attribut.name);
	ft_memdel((void**)&attribut.content);
	return (0);
}

int		free_all_elem(t_element elem)
{
	int i;

	i = 0;
	ft_memdel((void**)&elem.object);
	ft_memdel((void**)&elem.end_object);
	while (i < elem.nbr_element)
	{
		free_all_elem(elem.elem[i]);
		i++;
	}
	i = 0;
	if (elem.nbr_element != 0)
		ft_memdel((void**)&elem.elem);
	while (i < elem.nbr_attr)
	{
		free_all_attributes(elem.attribut[i]);
		i++;
	}
	if (elem.nbr_attr != 0)
		ft_memdel((void**)&elem.attribut);
	return (0);
}

t_env	*recup_env(t_env *e, t_element elem)
{
	int nbr_mat;

	recup_light(e, elem);
	recup_camera(e, elem);
	nbr_mat = recup_mat(e, elem);
	recup_object(e, elem, nbr_mat);
	free_all_elem(elem);
	return (e);
}
